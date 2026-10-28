#include <stdio.h>

int main()
{
    int n, capacity, i, w;
    int weight[20], profit[20];
    int dp[21][101];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of items:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &weight[i]);

    printf("Enter the profits of items:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &profit[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= capacity; w++)
        {
            if(i == 0 || w == 0)
                dp[i][w] = 0;
            else if(weight[i] <= w)
            {
                if(profit[i] + dp[i-1][w-weight[i]] > dp[i-1][w])
                    dp[i][w] = profit[i] + dp[i-1][w-weight[i]];
                else
                    dp[i][w] = dp[i-1][w];
            }
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    printf("Maximum profit = %d\n", dp[n][capacity]);

    return 0;
}