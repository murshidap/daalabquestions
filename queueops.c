#include <stdio.h>

#define MAX_SIZE 100

static void displayQueue(const int queue[], int front, int count) {
    int i;

    printf("Current Queue: ");
    if (count == 0) {
        printf("empty\n");
        return;
    }

    printf("[");
    for (i = 0; i < count; i++) {
        printf("%d", queue[(front + i) % MAX_SIZE]);
        if (i < count - 1) printf(", ");
    }
    printf("]\n");
}

int main(void) {
    int queue[MAX_SIZE];
    int front = 0;
    int count = 0;
    int choice, element;

    while (1) {
        displayQueue(queue, front, count);
        printf("\nChoose:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Abort\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                if (count == MAX_SIZE) {
                    printf("Queue overflow\n");
                    break;
                }
                printf("Enter the element: ");
                if (scanf("%d", &element) != 1) {
                    fprintf(stderr, "Invalid input.\n");
                    return 1;
                }
                queue[(front + count) % MAX_SIZE] = element;
                count++;
                displayQueue(queue, front, count);
                break;
            case 2:
                if (count == 0) {
                    printf("Queue underflow\n");
                    break;
                }
                front = (front + 1) % MAX_SIZE;
                count--;
                displayQueue(queue, front, count);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
        }
        printf("\n");
    }
}
