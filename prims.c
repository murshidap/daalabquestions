  #include <stdio.h>
#define INF 9999

int main()
{
    int n, e, i, j, start, end, weight, min, u, v;
    int cost[20][20];
    int visited[20] = {0};
    int selectedEdges = 0;
    int totalCost = 0;

    // Initialize the cost matrix
    // INF means there is no edge between two vertices
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            cost[i][j] = INF;
        }
    }

    // Read number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Read number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    // Read the edges
    printf("\nEnter edges (in the format Start End Weight):\n");

    for (i = 1; i <= e; i++)
    {
        printf("Enter edge %d: ", i);
        scanf("%d %d %d", &start, &end, &weight);

        // Since the graph is undirected,
        // store the edge in both directions
        cost[start - 1][end - 1] = weight;
        cost[end - 1][start - 1] = weight;
    }

    // Start Prim's algorithm from vertex 1
    visited[0] = 1;

    printf("\nMinimum Spanning Tree:\n");

    // A spanning tree with n vertices has n-1 edges
    while (selectedEdges < n - 1)
    {
        min = INF;
        u = -1;
        v = -1;

        // Find the minimum-weight edge
        // connecting a visited vertex to an unvisited vertex
        for (i = 0; i < n; i++)
        {
            if (visited[i] == 1)
            {
                for (j = 0; j < n; j++)
                {
                    if (visited[j] == 0 && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        // If no edge is found, the graph is disconnected
        if (u == -1 || v == -1)
        {
            printf("\nMinimum Spanning Tree cannot be formed.\n");
            return 0;
        }

        // Display the selected edge
        printf("\nEdge %d:\n", selectedEdges + 1);
        printf("Vertices: %d - %d\n", u + 1, v + 1);
        printf("Weight: %d\n", min);

        // Add the edge weight to the total cost
        totalCost = totalCost + min;

        // Mark the new vertex as visited
        visited[v] = 1;

        selectedEdges++;
    }

    // Display the minimum total cost
    printf("\nMinimum Cost = %d\n", totalCost);

    return 0;
}
