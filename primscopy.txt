#include <stdio.h>

int main()
{
    int a[20][20], visited[20] = {0};
    int n, i, j, edges = 0;
    int min, u = 0, v = 0, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    visited[0] = 1;

    printf("Edges in MST:\n");

    while(edges < n - 1)
    {
        min = 999999;

        for(i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(j = 0; j < n; j++)
                {
                    if(!visited[j] && a[i][j] != 0 && a[i][j] < min)
                    {
                        min = a[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if(min == 999999)
        {
            printf("Graph is disconnected\n");
            return 0;
        }

        printf("%d - %d : %d\n", u, v, min);

        visited[v] = 1;
        total += min;
        edges++;
    }

    printf("Total weight = %d\n", total);

    return 0;
}