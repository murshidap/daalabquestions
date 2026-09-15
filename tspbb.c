#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#define MAX 10
#define INF INT_MAX

int n, edges;
int cost[MAX][MAX];
int firstMin[MAX], secondMin[MAX];
int currentPath[MAX + 1];
int bestPath[MAX + 1];
long long bestCost;

void normalizeName(char name[])
{
    int i;
    for (i = 0; name[i] != '\0'; i++){
        if (name[i] == '\n' || name[i] == '\r')
            name[i] = '\0';
        else
            name[i] = (char)tolower((unsigned char)name[i]);
    }
}

int findCity(char cityName[MAX][50], char name[])
{
    int i;
    char normalizedName[50];

    strcpy(normalizedName, name);
    normalizeName(normalizedName);
    for (i = 0; i < n; i++){
        if (strcmp(cityName[i], normalizedName) == 0)
            return i;
    }
    return -1;
}

long long calculateInitialBound(void)
{
    int city, nextCity;
    int minimum, secondMinimum;
    long long bound = 0;

    for (city = 0; city < n; city++){
        minimum = INF;
        secondMinimum = INF;
        for (nextCity = 0; nextCity < n; nextCity++){
            if (city == nextCity || cost[city][nextCity] == INF)
                continue;
            if (cost[city][nextCity] <= minimum){
                secondMinimum = minimum;
                minimum = cost[city][nextCity];
            } else if (cost[city][nextCity] < secondMinimum)
                secondMinimum = cost[city][nextCity];
        }
        if (secondMinimum == INF)
            return INF;
        firstMin[city] = minimum;
        secondMin[city] = secondMinimum;
        bound += minimum + secondMinimum;
    }
    return (bound + 1) / 2;
}

int isVisited(int city, int level)
{
    int i;
    for (i = 0; i < level; i++)
        if (currentPath[i] == city)
            return 1;
    return 0;
}

void branchAndBound(int level, long long currentCost, long long bound)
{
    int currentCity = currentPath[level - 1];
    int nextCity;
    long long nextBound;
    long long nextCost;

    if (level == n){
        if (cost[currentCity][0] != INF){
            nextCost = currentCost + cost[currentCity][0];
            if (nextCost < bestCost){
                bestCost = nextCost;
                for (nextCity = 0; nextCity < n; nextCity++)
                    bestPath[nextCity] = currentPath[nextCity];
                bestPath[n] = 0;
            }
        }
        return;
    }

    for (nextCity = 1; nextCity < n; nextCity++){
        if (isVisited(nextCity, level) || cost[currentCity][nextCity] == INF)
            continue;

        nextCost = currentCost + cost[currentCity][nextCity];
        if (level == 1)
            nextBound = bound - (firstMin[currentCity] + firstMin[nextCity]) / 2;
        else
            nextBound = bound - (secondMin[currentCity] + firstMin[nextCity]) / 2;

        if (nextCost + nextBound < bestCost){
            currentPath[level] = nextCity;
            branchAndBound(level + 1, nextCost, nextBound);
        }
    }
}

int main(void)
{
    char cityName[MAX][50];
    char city1[50], city2[50];
    int edgeCost;
    int i, j, city1Index, city2Index;
    int currentCity, nextCity;
    long long initialBound;

    printf("Enter the number of cities: ");
    if (scanf("%d", &n) != 1 || n < 2 || n > MAX){
        printf("Invalid number of cities!\n");
        return 0;
    }

    printf("Enter the number of edges: ");
    if (scanf("%d", &edges) != 1 || edges < 0){
        printf("Invalid number of edges!\n");
        return 0;
    }

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
            cost[i][j] = (i == j) ? 0 : INF;
    }

    printf("\nEnter the names of the cities:\n");
    for (i = 0; i < n; i++){
        printf("City %d: ", i + 1);
        scanf("%49s", cityName[i]);
        normalizeName(cityName[i]);
    }

    printf("\nEnter edges (City1 City2 Cost):\n");
    for (i = 0; i < edges; i++){
        if (scanf("%49s %49s %d", city1, city2, &edgeCost) != 3 || edgeCost < 0){
            printf("Invalid edge. Use: City1 City2 non-negative-cost\n");
            return 0;
        }
        city1Index = findCity(cityName, city1);
        city2Index = findCity(cityName, city2);
        if (city1Index == -1 || city2Index == -1){
            printf("Invalid city name!\n");
            return 0;
        }
        cost[city1Index][city2Index] = edgeCost;
        cost[city2Index][city1Index] = edgeCost;
    }

    initialBound = calculateInitialBound();
    bestCost = LLONG_MAX;
    currentPath[0] = 0;
    if (initialBound != INF)
        branchAndBound(1, 0, initialBound);

    if (bestCost == LLONG_MAX){
        printf("\nNo possible tour found!\n");
    } else {
        printf("\nShortest Route: ");
        for (i = 0; i <= n; i++)
            printf("%s%s", cityName[bestPath[i]], i == n ? "\n" : " -> ");
        printf("Minimum Cost: %lld\n", bestCost);
    }
    return 0;
}