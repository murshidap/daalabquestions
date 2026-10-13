#include <stdio.h>

void heapify(int a[], int n, int i)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2, temp;
    if (left < n && a[left] > a[largest]) largest = left;
    if (right < n && a[right] > a[largest]) largest = right;
    if (largest != i) {
        temp = a[i]; a[i] = a[largest]; a[largest] = temp;
        heapify(a, n, largest);
    }
}

int main(void)
{
    int n, i, temp;
    printf("Enter the no.of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 0;
    }

    int a[n];
    printf("Enter %d elements: \n", n);
    for (i = 0; i < n; i++)
        if (scanf("%d", &a[i]) != 1) {
            printf("Invalid input.\n");
            return 0;
        }

    for (i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
    for (i = n - 1; i > 0; i--) {
        temp = a[0]; a[0] = a[i]; a[i] = temp;
        heapify(a, i, 0);
    }

    printf("Sorted elements: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
