#include <stdio.h>

int main()
{
    int n, i, j, max = 0, total = 0, temp;
    int deadline[20], profit[20], job[20];
    int slot[20], maxDeadline = 0;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    printf("Enter job ID, deadline and profit:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d%d%d", &job[i], &deadline[i], &profit[i]);

        if(deadline[i] > maxDeadline)
            maxDeadline = deadline[i];
    }

    /* Sort jobs by descending profit */
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(profit[j] < profit[j + 1])
            {
                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;

                temp = deadline[j];
                deadline[j] = deadline[j + 1];
                deadline[j + 1] = temp;

                temp = job[j];
                job[j] = job[j + 1];
                job[j + 1] = temp;
            }
        }
    }

    /* Initialize slots */
    for(i = 0; i < maxDeadline; i++)
        slot[i] = -1;

    /* Schedule jobs */
    for(i = 0; i < n; i++)
    {
        for(j = deadline[i] - 1; j >= 0; j--)
        {
            if(slot[j] == -1)
            {
                slot[j] = job[i];
                total += profit[i];
                break;
            }
        }
    }

    printf("\nJob Schedule:\n");

    for(i = 0; i < maxDeadline; i++)
    {
        if(slot[i] != -1)
            printf("Slot %d: Job %d\n", i + 1, slot[i]);
    }

    printf("Maximum Profit = %d\n", total);

    return 0;
}