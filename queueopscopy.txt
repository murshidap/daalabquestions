#include <stdio.h>

int main()
{
    int q[100], front = -1, rear = -1;
    int choice, value, i;

    while(1)
    {
        printf("\n1.ENQUEUE  2.DEQUEUE  3.DISPLAY  4.EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(rear == 99)
                    printf("Queue Overflow\n");
                else
                {
                    printf("Enter element: ");
                    scanf("%d", &value);

                    if(front == -1)
                        front = 0;

                    q[++rear] = value;
                }
                break;

            case 2:
                if(front == -1 || front > rear)
                    printf("Queue Underflow\n");
                else
                {
                    printf("Deleted element: %d\n", q[front++]);

                    if(front > rear)
                        front = rear = -1;
                }
                break;

            case 3:
                if(front == -1)
                    printf("Queue is empty\n");
                else
                {
                    for(i = front; i <= rear; i++)
                        printf("%d ", q[i]);
                    printf("\n");
                }
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}