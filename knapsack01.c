#include <stdio.h>

int main(void) {
    int n, capacity, i, w, weight[100], profit[100];

    printf("Enter capacity: ");
    if (scanf("%d", &capacity) != 1 || capacity < 0) return 1;
    printf("Enter number of items (1-100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) return 1;

    for (i = 0; i < n; i++) {
        printf("Enter weight and profit of item %d: ", i + 1);
        if (scanf("%d %d", &weight[i], &profit[i]) != 2 || weight[i] < 0)
            return 1;
    }

    int dp[n + 1][capacity + 1];
    for (w = 0; w <= capacity; w++) dp[0][w] = 0;
    for (i = 1; i <= n; i++)
        for (w = 0; w <= capacity; w++) {
            dp[i][w] = dp[i - 1][w];
            if (weight[i - 1] <= w &&
                dp[i - 1][w - weight[i - 1]] + profit[i - 1] > dp[i][w])
                dp[i][w] = dp[i - 1][w - weight[i - 1]] + profit[i - 1];
        }

    printf("Items taken:\n");
    for (i = n, w = capacity; i > 0; i--)
        if (dp[i][w] != dp[i - 1][w]) {
            printf("Item %d , ",i);
            w -= weight[i - 1];
        }
    printf("\nMaximum profit: %d\n", dp[n][capacity]);
    return 0;
}
