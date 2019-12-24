#include <stdio.h>

void selection_sort();

void main()
{
    int n,i,ch,ans;
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    selection_sort(a,n);
}

void selection_sort(int a[],int n)
{
    int i,j,k,min,temp=0;
    for(i=0;i<=n-2;i++)
    {
        min=i;
        for(j=i+1;j<=n-1;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
        printf("\nAfter pass %d: ",(i+1));
        for(k=0;k<n;k++)
        printf("%d ",a[k]);
    }
}
