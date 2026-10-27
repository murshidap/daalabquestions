#include <stdio.h>

int n, cost[10][10], visited[10];
int path[10], bestPath[10];
int minCost = 999999;

void tsp(int city, int count, int total)
{
    int i;

    if(count == n)
    {
        if(cost[city][0] != 0)
        {
            total += cost[city][0];

            if(total < minCost)
            {
                minCost = total;

                for(i = 0; i < n; i++)
                    bestPath[i] = path[i];
            }
        }
        return;
    }

    for(i = 0; i < n; i++)
    {
        if(!visited[i] && cost[city][i] != 0)
        {
            if(total + cost[city][i] < minCost)
            {
                visited[i] = 1;
                path[count] = i;

                tsp(i, count + 1, total + cost[city][i]);

                visited[i] = 0;
            }
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix (0 for no path):\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    visited[0] = 1;
    path[0] = 0;

    tsp(0, 1, 0);

    if(minCost == 999999)
        printf("No valid tour exists.\n");
    else
    {
        printf("Optimal tour: ");

        for(i = 0; i < n; i++)
            printf("%d -> ", bestPath[i]);

        printf("0\n");
        printf("Minimum cost = %d\n", minCost);
    }

    return 0;
}