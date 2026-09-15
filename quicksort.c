#include<stdio.h>

int pt(int a[],int l,int h)
{
    int j,t;
    int p=a[h];
    int i=l-1;
    for(j=l;j<h;j++){
        if(a[j]<=p){
            i++;
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    t=a[i+1];
    a[i+1]=a[h];
    a[h]=t;
    return i+1;
}

void qs(int a[],int l,int h)
{
    int pi;
    if(l<h){
        pi=pt(a,l,h);
        qs(a,l,pi-1);
        qs(a,pi+1,h);
    }
}

int main()
{
    int n,i;
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
    qs(a,0,n-1);
    printf("Sorted array is: \n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
