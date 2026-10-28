#include <stdio.h>

struct Edge
{
    int u, v, w;
};

int parent[20];

int find(int x)
{
    while(parent[x] != x)
        x = parent[x];

    return x;
}

int main()
{
    struct Edge e[100], temp;
    int n, m, i, j, u, v, total = 0, count = 0;

    printf("Enter number of vertices and edges: ");
    scanf("%d%d", &n, &m);

    printf("Enter edges (source destination weight):\n");
    for(i = 0; i < m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);

    for(i = 0; i < n; i++)
        parent[i] = i;

    for(i = 0; i < m - 1; i++)
        for(j = 0; j < m - i - 1; j++)
            if(e[j].w > e[j + 1].w)
            {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }

    printf("Edges in MST:\n");

    for(i = 0; i < m && count < n - 1; i++)
    {
        u = find(e[i].u);
        v = find(e[i].v);

        if(u != v)
        {
            printf("%d - %d : %d\n",
                   e[i].u, e[i].v, e[i].w);

            parent[u] = v;
            total += e[i].w;
            count++;
        }
    }

    if(count != n - 1)
        printf("Graph is disconnected\n");
    else
        printf("Total weight = %d\n", total);

    return 0;
}