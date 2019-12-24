#include <stdio.h>
int knap(int n, int m, int wt[], int pf[]);
int maximum(int a, int b);
int main()
{
   int i,n,m;
   printf("Enter number of items: ");
   scanf("%d",&n);
   int wt[n+1],pf[n+1];
   printf("Enter capacity of knapsack: ");
   scanf("%d",&m);
   printf("Enter weights: ");
   for(i=1;i<=n;i++)
       scanf("%d",&wt[i]);
   printf("Enter profits: ");
   for(i=1;i<=n;i++)
       scanf("%d",&pf[i]);
   printf("\nMaximum possible profit: %d units.",knap(n,m,wt,pf));
}
int knap(int n, int m, int wt[], int pf[])
{
   int i,j;
   float f[n];
   int cost[n+1][m+1];
   printf("Solution table:\n");
   for (i=0;i<=n;i++)
   {
       for (j=0;j<=m;j++)
       {
           if (i==0 || j==0)
               cost[i][j]=0;
           else if (wt[i]<=j)
               cost[i][j]=maximum(cost[i-1][j], pf[i]+cost[i-1][j-wt[i]]);
           else cost[i][j]=cost[i-1][j];
           printf("%d\t",cost[i][j]);
       }
       printf("\n");
   }
   for(i=n,j=m;i>0;i--)
   {
       if(cost[i][j]!=cost[i-1][j])
       {
           f[i-1]=1;
           j=j-wt[i];
       }
       else f[i-1]=0;
   }
   printf("Fraction array: ");
   for(i=0;i<n;i++)
       printf("%f\t",f[i]);
   return cost[n][m];
}
int maximum(int a, int b)
{
   if (a>b)
   return a;
   else return b;
}
