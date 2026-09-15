#include<stdio.h>
int main()
{
	int undo[10],redo[10];
	int topUndo=-1, topRedo=-1;
	int value=10, choice, x;
	while(x)
	{
		printf("Value=%d\n", value);
		printf("\n 1.Add\n 2.Multiply\n 3.Undo\n 4.Redo\n 5.Exit\n");
		printf("Enter your choice");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("Enter number:");
			scanf("%d",&x);
			value+=x;
			undo[++topUndo]=x;
			topRedo=-1;
		}
		else if(choice==2)
		{
			if(topUndo==-1)
			printf("Nothing to Undo\n");
			else
			{
				x=undo[topUndo--];
				value-=x;
				redo[++topRedo]=x;
			}
		}
		else if(choice==3)
		{
			if(topRedo==-1)
			{
				printf("Nothing to Redo\n");
			}
			else
			{
				x=redo[topRedo--];
				value+=x;
				undo[++topUndo]=x;
			}
		}
		else if(choice==4)
		{
			printf("Enter number:");
			scanf("%d",&x);
			value*=x;
			undo[++topUndo]=-x;
			topRedo=-1;
		}
		else if(choice==5)
		{
			break;
		}
		return 0;
    }
}

