#include <stdio.h>

int main() {
    int n, e, i, j, temp;
    char u[50], v[50];
    int parent[256], w[50];
    int count = 0, total = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter the edges (source destination weight):\n");
    for (i = 0; i < e; i++) {
        scanf(" %c %c %d", &u[i], &v[i], &w[i]);
    }

    for (i = 0; i < 256; i++) {
        parent[i] = i;
    }
    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (w[j] > w[j + 1]) {
                temp = w[j]; w[j] = w[j + 1]; w[j + 1] = temp;
                temp = u[j]; u[j] = u[j + 1]; u[j + 1] = temp;
                temp = v[j]; v[j] = v[j + 1]; v[j + 1] = temp;
            }
        }
    }

    printf("\nMinimum spanning tree: \n");
    for (i = 0; i < e; i++) {
        int a = u[i];
        int b = v[i];

        while (parent[a] != a) a = parent[a];
        while (parent[b] != b) b = parent[b];

        if (a != b) {
            printf("%c -- %c : %d\n", u[i], v[i], w[i]);
            total = total + w[i];
            parent[b] = a;
            count++;
            if (count == n - 1) break;
        }
    }

    printf("Minimum cost of spanning tree = %d\n", total);
    return 0;
}
