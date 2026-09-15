#include <stdio.h>

struct Job
{
    char id;
    int deadline;
    int profit;
};

int main()
{
    int n, i, j;
    struct Job job[50], temp;
    int slot[50];
    int maxDeadline = 0;
    int totalProfit = 0;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    printf("\nEnter details of Jobs (in the format Job Deadline Profit ) :\n");
    for (i = 0; i < n; i++)
    {
        printf("\nJob %d: ", i + 1);
        scanf(" %c %d %d",
              &job[i].id,
              &job[i].deadline,
              &job[i].profit);
        if (job[i].deadline > maxDeadline)
            maxDeadline = job[i].deadline;
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (job[i].profit < job[j].profit)
            {
                temp = job[i];
                job[i] = job[j];
                job[j] = temp;
            }
        }
    }
    for (i = 1; i <= maxDeadline; i++)
        slot[i] = -1;
    for (i = 0; i < n; i++)
    {
        for (j = job[i].deadline; j >= 1; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                totalProfit += job[i].profit;
                break;
            }
        }
    }
    printf("\nScheduled Jobs:\n");
    for (i = 1; i <= maxDeadline; i++)
    {
        if (slot[i] != -1)
        {
            printf("Time Slot %d -> Job %c\n",i, job[slot[i]].id);
        }
    }
    printf("\nMaximum Profit = %d\n", totalProfit);
    return 0;
}