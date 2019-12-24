#include<stdio.h>
void merge_sort(int a[],int p,int r);
void merge(int a[],int p,int q,int r);

void main()
{
    int i,n,a[100],p,r;
    printf("Enter the no of elements: ");
    scanf("%d",&n);

    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    merge_sort(a,0,n-1);
    printf("Sorted list is: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

void merge_sort(int a[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        merge_sort(a,p,q);
        merge_sort(a,q+1,r);
        merge(a,p,q,r);
    }
}
void merge(int a[],int p,int q,int r)
{
    int n1,n2;
    n1=q-p+1;
    n2=r-q;
    int l[n1],R[n2];
    int i,j,k;
    for(i=0;i<=n1-1;i++)
    {
        l[i]=a[p+i];

    }
    for(j=0;j<=n2-1;j++)
    {
        R[j]=a[q+1+j];

    }
    l[n1]=R[n2]=10000;
    i=0;j=0;
    for(k=p;k<=r;k++)
    {
        if(l[i]<=R[j])
        {
            a[k]=l[i];
            i++;
        }
        else
        {
         a[k]=R[j];
        j++;
        }

    }
}
