#include<stdio.h>
#include<conio.h>
int stack[5],top=-1;
int isEmpty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isFull()
{
	if(top==4)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push(int x)
{
	if(!isFull())
	{
		top++;
		stack[top]=x;
	}
	else 
	{
		printf("Stack is full\n");
	}
}
void pop()
{
	if(!isEmpty())
	{
		printf("Popped:%d\n",stack[top]);
		top--;
	}
	else 
	{
		printf("Stack is empty\n");
	}
}
void displaystk()
{
	for(int i=top; i>=0; i--)
	{
		printf("%d", stack[i]);
		printf("\n");
	}
}
int main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	printf("Stack elements are: \n");
	displaystk();
	pop();
	displaystk();
	return 0;
}
