#include <stdio.h>

typedef struct {
    int number;
    float profit, weight, ratio;
    int quantity;
} Item;

int main(void) {
    int n, i, j, take;
    float capacity, originalCapacity, totalWeight = 0, totalProfit = 0;
    Item item[100], temp;

    printf("Enter capacity: ");
    scanf("%f", &capacity);
    originalCapacity = capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Item %d (profit weight quantity): ", i + 1);
        item[i].number = i + 1;
        scanf("%f %f %d", &item[i].profit, &item[i].weight,
              &item[i].quantity);
        item[i].ratio = item[i].profit / item[i].weight;
    }

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (item[i].ratio < item[j].ratio) {
                temp = item[i]; item[i] = item[j]; item[j] = temp;
            }

    printf("\nItems chosen:\n");
    for (i = 0; i < n && capacity > 0; i++) {
        take = capacity / item[i].weight;
        if (take > item[i].quantity) take = item[i].quantity;
        capacity -= take * item[i].weight;
        totalWeight += take * item[i].weight;
        totalProfit += take * item[i].profit;
        if (take > 0)
            printf("Item %d: %d unit(s)\n", item[i].number, take);
    }

    printf("Total weight: %.2f\n", totalWeight);
    printf("Remaining space: %.2f\n", originalCapacity - totalWeight);
    printf("Profit: %.2f\n", totalProfit);
    return 0;
}