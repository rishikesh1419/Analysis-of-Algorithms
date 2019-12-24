#include<stdio.h>
void quick_sort(int[], int, int);
int partition(int[], int, int);

void quick_sort(int a[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=partition(a,p,r);
        quick_sort(a,p,q-1);
        quick_sort(a,q+1,r);
    }
}

int partition(int a[],int p,int r)
{
    int x,i,j,temp;
    x=a[r];
    i=p-1;
    for(j=p;j<=r-1;j++)
    {
        if(a[j]<=x)
        {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
        temp=a[i+1];
        a[i+1]=a[r];
        a[r]=temp;
        return i+1;
}

void main()
{
int i,n,p,r,a[50];
printf("Enter the number of elements: ");
scanf("%d",&n);
printf("Enter the elements:\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
quick_sort(a,0,n-1);
printf("Sorted list is: ");
for(i=0;i<n;i++)
printf("%d ",a[i]);
}
