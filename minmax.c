#include<stdio.h>

int findMin(int a[],int l,int r)
{
    int m,x,y;
    if(l==r)
        return a[l];
    m=(l+r)/2;
    x=findMin(a,l,m);
    y=findMin(a,m+1,r);
    return (x<y)?x:y;
}
int findMax(int a[],int l,int r)
{
    if(l==r)
        return a[l];
    int m=(l+r)/2;
    int x=findMax(a,l,m);
    int y=findMax(a,m+1,r);
    return (x>y)?x:y;
}

int main()
{
    int n,i,mn,mx;
    printf("Enter the no.of elements: ");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("Invalid input.\n");
        return 0;
    }
    int a[n];
    printf("Enter %d elements: \n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mn=findMin(a,0,n-1);
    mx=findMax(a,0,n-1);
    printf("Minimum element is: %d\n",mn);
    printf("Maximum element is: %d\n",mx);
    return 0;
}
