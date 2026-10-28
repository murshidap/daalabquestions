#include <stdio.h>

int main()
{
    float weight[100], profit[100], ratio[100];
    float capacity, totalProfit = 0, fraction, temp;
    int n, i, j;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weight and profit of each item:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%f%f", &weight[i], &profit[i]);

        if(weight[i] <= 0 || profit[i] < 0)
        {
            printf("Invalid weight or profit\n");
            return 0;
        }

        ratio[i] = profit[i] / weight[i];
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    if(capacity < 0)
    {
        printf("Invalid capacity\n");
        return 0;
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(ratio[j] < ratio[j + 1])
            {
                temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;

                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;

                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;
            }
        }
    }

    for(i = 0; i < n && capacity > 0; i++)
    {
        if(weight[i] <= capacity)
        {
            totalProfit += profit[i];
            capacity -= weight[i];
        }
        else
        {
            fraction = capacity / weight[i];
            totalProfit += profit[i] * fraction;
            capacity = 0;
        }
    }

    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}