#include <stdio.h>

int a[100], temp[100];

void mergesort(int low, int high)
{
    int mid, i, j, k;

    if(low < high)
    {
        mid = (low + high) / 2;

        mergesort(low, mid);
        mergesort(mid + 1, high);

        i = low;
        j = mid + 1;
        k = low;

        while(i <= mid && j <= high)
        {
            if(a[i] <= a[j])
                temp[k++] = a[i++];
            else
                temp[k++] = a[j++];
        }

        while(i <= mid)
            temp[k++] = a[i++];

        while(j <= high)
            temp[k++] = a[j++];

        for(i = low; i <= high; i++)
            a[i] = temp[i];
    }
}

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    mergesort(0, n - 1);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}