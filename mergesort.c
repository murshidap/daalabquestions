#include<stdio.h>

void mg(int a[],int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int x[n1],y[n2];
    for(i=0;i<n1;i++)
        x[i]=a[l+i];
    for(j=0;j<n2;j++)
        y[j]=a[m+1+j];
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(x[i]<=y[j])
        {
            a[k]=x[i];
            i++;
        }
        else
        {
            a[k]=y[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=x[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=y[j];
        j++;
        k++;
    }
}

void ms(int a[],int l,int r)
{
    int m;
    if(l<r){
        m=l+(r-l)/2;
        ms(a,l,m);
        ms(a,m+1,r);
        mg(a,l,m,r);
    }
}

int main()
{
    int n,i;
    printf("Enter the no.of elements: ");
    scanf("%d",&n);
    if(n<=0)
        printf("Invalid input.\n");
    int a[n];
    printf("Enter %d elements: \n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    ms(a,0,n-1);
    printf("Sorted array is: \n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
    }
