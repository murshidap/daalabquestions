#include <stdio.h>

#define MAX_SIZE 100

static void displayStack(const int stack[], int top) {
    int i;

    printf("Current Stack: ");
    if (top == -1) {
        printf("empty\n");
        return;
    }

    printf("[");
    for (i = 0; i <= top; i++) {
        printf("%d", stack[i]);
        if (i < top) printf(", ");
    }
    printf("]\n");
}

int main(void) {
    int stack[MAX_SIZE];
    int top = -1;
    int choice, element;

    while (1) {
        displayStack(stack, top);
        printf("\nChoose:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peak\n");
        printf("4. Abort\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                if (top == MAX_SIZE - 1) {
                    printf("Stack overflow\n");
                    break;
                }
                printf("Enter the element: ");
                if (scanf("%d", &element) != 1) {
                    fprintf(stderr, "Invalid input.\n");
                    return 1;
                }
                stack[++top] = element;
                displayStack(stack, top);
                break;
            case 2:
                if (top == -1) {
                    printf("Stack underflow\n");
                    break;
                }
                top--;
                displayStack(stack, top);
                break;
            case 3:
                if (top == -1)
                    printf("empty\n");
                else
                    printf("Peak element: %d\n", stack[top]);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
        printf("\n");
    }
}
