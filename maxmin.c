#include<stdio.h>

int max,min,mid,a[100];
void max_min(int, int);

void max_min(int i,int j)
{
    int max1,min1;
    if(i==j)
        max=min=a[i];
    else if(i==j-1)
    {
        if(a[i]<a[j])
        {
            max=a[j];
            min=a[i];
        }
        else
        {
            min=a[j];
            max=a[i];
        }
    }
    else
    {
        mid=(i+j)/2;
        max_min(i,mid);
        max1=max;
        min1=min;
        max_min(mid+1,j);
        if(max1>max)
            max=max1;
        if(min1<min)
            min=min1;
    }
}
int main()
{
    int n,i;
    printf("Enter number of players: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter runs scored by player %d: ",i+1);
        scanf("%d",&a[i]);
    }
    max_min(0,n-1);
    printf("Highest total score in year 2017: %d\n",max);
    printf("Lowest total score in year 2017: %d",min);
}

