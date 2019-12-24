#include <stdio.h>
float p[100],w[100],q[100],x[100];
void knapsack(int m, int n);
int main()
{    int i,m,n;
    float profit=0.0;
    printf("Enter the capacity of the truck: ");
    scanf("%d",&m);
    printf("Enter the number of liquids available: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the weight of liquid %d: ",i+1);
        scanf("%f",&w[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("Enter the profit gained by liquid %d: ",i+1);
        scanf("%f",&p[i]);
    }
    knapsack(m,n);
    printf("The elements and their fractions are:\n");
    for(i=0;i<n;i++)
    {  printf("%f\t",p[i]);
  }
printf("\n");
     for(i=0;i<n;i++)
    {
        printf("%f\t",x[i]);
        profit=profit+x[i]*p[i];
    }
        printf("\nMaximum Profit is: %f\n",profit);
}


void knapsack(int m,int n)
{
    int i,j;
    float t,u;
    for(i=0;i<n;i++)
    {
        q[i]=p[i]/(float)w[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(q[j]<q[j+1])
            {
            t=q[j];
            q[j]=q[j+1];
            q[j+1]=t;
            t=p[j];
            p[j]=p[j+1];
            p[j+1]=t;
            t=w[j];
            w[j]=w[j+1];
            w[j+1]=t;
            }
        }
    }
    for(i=0;i<n;i++)
        x[i]=0.0;
    u=m;
    for(i=0;i<n;i++)
    {
        if(w[i]>u)
            break;
        x[i]=1.0;
        u=u-w[i];
    }
    if(i<n)
        x[i]=u/w[i];
}

