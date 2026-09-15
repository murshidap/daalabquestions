#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#define MAX 10
#define INF INT_MAX

int n, edges;
int cost[MAX][MAX];
int dp[1 << MAX][MAX];
int parent[1 << MAX][MAX];
int bestPath[MAX];

void normalizeName(char name[])
{
    int i;
    for (i = 0; name[i] != '\0'; i++){
        if (name[i] == '\n' || name[i] == '\r')
            name[i] = '\0';
        else
            name[i] = tolower((unsigned char)name[i]);
    }
}

int findCost(char cityName[MAX][50], char name[])
{
    int i;
    char tempName[50];
    strcpy(tempName, name);
    normalizeName(tempName);
    for (i = 0; i < n; i++){
        char tempCity[50];
        strcpy(tempCity, cityName[i]);
        normalizeName(tempCity);
        if (strcmp(tempCity, tempName) == 0)
            return i;
    }
    return -1;
}

int tsp(int bestPath[])
{
    int subset, currentCity, previousCity;
    int fullSet = (1 << n) - 1;
    int minCost = INF;
    int lastCity = -1;

    for (subset = 0; subset < (1 << n); subset++){
        for (currentCity = 0; currentCity < n; currentCity++){
            dp[subset][currentCity] = INF;
            parent[subset][currentCity] = -1;
        }
    }

    dp[1][0] = 0;

    for (subset = 1; subset <= fullSet; subset++){
        if (!(subset & 1))
            continue;

        for (currentCity = 1; currentCity < n; currentCity++){
            if (!(subset & (1 << currentCity)))
                continue;

            previousCity = subset ^ (1 << currentCity);
            for (int candidate = 0; candidate < n; candidate++){
                if (!(previousCity & (1 << candidate)) ||
                    cost[candidate][currentCity] == INF ||
                    dp[previousCity][candidate] == INF)
                    continue;

                if (dp[previousCity][candidate] +
                    cost[candidate][currentCity] < dp[subset][currentCity]){
                    dp[subset][currentCity] =
                        dp[previousCity][candidate] +
                        cost[candidate][currentCity];
                    parent[subset][currentCity] = candidate;
                }
            }
        }
    }

    for (currentCity = 1; currentCity < n; currentCity++){
        if (dp[fullSet][currentCity] == INF ||
            cost[currentCity][0] == INF)
            continue;

        if (dp[fullSet][currentCity] + cost[currentCity][0] < minCost){
            minCost = dp[fullSet][currentCity] + cost[currentCity][0];
            lastCity = currentCity;
        }
    }

    if (lastCity == -1)
        return INF;

    subset = fullSet;
    for (currentCity = n - 1; currentCity > 0; currentCity--){
        bestPath[currentCity] = lastCity;
        previousCity = parent[subset][lastCity];
        subset ^= 1 << lastCity;
        lastCity = previousCity;
    }
    bestPath[0] = 0;
    return minCost;
}

int main()
{
    char cityName[MAX][50];
    char city1[50], city2[50];
    int edgeCost;
    int i, j;
    int cityIdx1, cityIdx2;
    int minCost;
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    if (n < 2 || n > MAX){
        printf("Invalid number of cities!\n");
        return 0;
    }
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = INF;
        }
    }
    printf("\nEnter the names of the cities:\n");
    for (i = 0; i < n; i++){
        printf("City %d: ", i + 1);
        scanf("%49s", cityName[i]);
        normalizeName(cityName[i]);
    }
    printf("\nEnter Edges (City1 City2 Cost):\n");
    for (i = 0; i < edges; i++){
        if (scanf("%49s %49s %d",city1, city2, &edgeCost) != 3){
            printf("Invalid edge format.Please enter: City1 City2 Cost\n");
            while (getchar() != '\n');
            i--;
            continue;
        }

        cityIdx1 = findCost(cityName, city1);
        cityIdx2 = findCost(cityName, city2);
        if (cityIdx1 == -1 || cityIdx2 == -1){
            printf("Invalid city name!Please enter names from the city list.\n");
            i--;
            continue;
        }
        cost[cityIdx1][cityIdx2] = edgeCost;
        cost[cityIdx2][cityIdx1] = edgeCost;
    }
    minCost = tsp(bestPath);
    if (minCost == INF)
        printf("No possible tour found!\n");
    else{
        printf("\nShortest Route: ");
        for (i = 0; i < n; i++)
            printf("%s -> ", cityName[bestPath[i]]);
        printf("%s\n", cityName[bestPath[0]]);
        printf("Minimum Cost: %d\n", minCost);
    }
    return 0;
}