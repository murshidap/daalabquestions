#include <stdio.h>

int a[20], x[20], n, target;

void sumOfSubsets(int i, int sum)
{
    int j;

    if(sum == target)
    {
        printf("{ ");
        for(j = 0; j < i; j++)
            if(x[j] == 1)
                printf("%d ", a[j]);
        printf("}\n");
        return;
    }

    if(i == n || sum > target)
        return;

    x[i] = 1;
    sumOfSubsets(i + 1, sum + a[i]);

    x[i] = 0;
    sumOfSubsets(i + 1, sum);
}

int main()
{
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("Subsets with sum %d:\n", target);
    sumOfSubsets(0, 0);

    return 0;
}