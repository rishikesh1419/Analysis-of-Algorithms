#include <stdio.h>

void insertion_sort();

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
    
    insertion_sort(a,n);
    
}

void insertion_sort(int a[],int n)
{
    int i,j,key=0;
    for(j=1;j<=n-1;j++)
    {
        key=a[j]; 
        i=j-1;
        while(i>-1 && a[i]>key)
        {
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=key;
        printf("\nAfter pass %d: ",j);
        for(i=0;i<n;i++)
            printf("%d ",a[i]);
    }
}
