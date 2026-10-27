#include <stdio.h>

int main()
{
    int a[100], n, i, min, max;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    min = max = a[0];

    for(i = 1; i < n; i++)
    {
        if(a[i] < min)
            min = a[i];

        if(a[i] > max)
            max = a[i];
    }

    printf("Minimum element = %d\n", min);
    printf("Maximum element = %d\n", max);

    return 0;
}