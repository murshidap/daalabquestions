#include<stdio.h>

int main()
{
    int n,trgt,                  rt,lt,md;
    int res=0;
    printf("Enter the no.of elements: ");
    scanf("%d",&n);
    int array[n];
    printf("Enter %d elements in ascending order: \n",n);
    for(int i=0;i<n;i++)
        scanf("%d",&array[i]);
    printf("enter the element to search: ");
    scanf("%d",&trgt);
    lt=0;
    rt=n-1;
    while(lt<=rt){
        md=lt+(rt-lt)/2;
        if(array[md]==trgt)
        {
            printf("%d found at position %d.\n",trgt,md);
            res=1;
            break;
        }
        else if(array[md]<trgt)
            lt=md+1;
        else
            rt=md-1;
    }
    if(!res)
        printf("%d was not found in the array.\n",trgt);
    return 0;
}
