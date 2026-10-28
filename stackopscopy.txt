#include <stdio.h>

int main()
{
    int stack[100], top = -1, n = 100;
    int choice, value, i;

    while(1)
    {
        printf("\n1.PUSH  2.POP  3.DISPLAY  4.PEAK  5.EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(top == n - 1)
                    printf("Stack Overflow\n");
                else
                {
                    printf("Enter element: ");
                    scanf("%d", &value);
                    stack[++top] = value;
                }
                break;

            case 2:
                if(top == -1)
                    printf("Stack Underflow\n");
                else
                    printf("Deleted element: %d\n", stack[top--]);
                break;

            case 3:
                if(top == -1)
                    printf("Stack is empty\n");
                else
                {
                    for(i = top; i >= 0; i--)
                        printf("%d ", stack[i]);
                    printf("\n");
                }
                break;

            case 4:
                if(top == -1)
                    printf("Stack is empty\n");
                else
                    printf("Top element: %d\n", stack[top]);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}