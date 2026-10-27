#include <stdio.h>

int cost[10][10], path[10], bestPath[10];
int visited[10], n, minCost = 999999;

void tsp(int city, int count, int total)
{
    int i;

    if(count == n)
    {
        if(cost[city][0] != 0 &&
           total + cost[city][0] < minCost)
        {
            minCost = total + cost[city][0];

            for(i = 0; i < n; i++)
                bestPath[i] = path[i];
        }

        return;
    }

    for(i = 1; i < n; i++)
    {
        if(!visited[i] && cost[city][i] != 0)
        {
            visited[i] = 1;
            path[count] = i;

            tsp(i, count + 1, total + cost[city][i]);

            visited[i] = 0;
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of cities (maximum 10): ");
    scanf("%d", &n);

    if(n < 2 || n > 10)
    {
        printf("Invalid number of cities");
        return 0;
    }

    printf("Enter cost matrix (0 for no route):\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    path[0] = 0;
    visited[0] = 1;

    tsp(0, 1, 0);

    if(minCost == 999999)
        printf("No complete tour exists\n");
    else
    {
        printf("Minimum cost: %d\n", minCost);
        printf("Tour: ");

        for(i = 0; i < n; i++)
            printf("%d -> ", bestPath[i]);

        printf("0\n");
    }

    return 0;
}