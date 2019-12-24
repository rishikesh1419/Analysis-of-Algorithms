#include<stdio.h>
int abs(int);
void Queen(int,int);
void display(int[] ,int);
int place(int,int);

int x[100],count=0;

int abs (int k)
{
    if(k<0)
	return 0-k;
    return k;
}

void Queen(int k,int n)
{
    int i;
    for (i=1;i<=n;i++)
    {
        if (place(k,i))
        {
        x[k]=i;
        if (k==n)
            {
             count++;
            display(x,n);
            }
            Queen(k+1,n);
        }
     }
}
int place(int k,int i)
{
    int j;
    for (j=1;j<=k-1;j++)
        if ((x[j]==i) || (abs(x[j]-i)==abs(j-k)))
            return 0;
        return 1;
}
void display(int x[],int n)
{
    int i,j,m;
    char a[20][20];
    for (i=1;i<=n;i++)
        {
            printf("\n");
            m=x[i];
            a[i][m]='Q';
        }
    for (i=1;i<=n;i++)
       {
            for (j=1;j<=n;j++)
            {
                if (a[i][j]=='Q')
                printf("%c  ",a[i][j]);
                else
                printf("*  ");
                a[i][j]='o';
            }
            printf("\n");
       }
}
void main()
{
    int n;
    printf("Enter number of queens: ");
    scanf("%d",&n);
    printf("Solutions for %d-Queen problem is :\n",n);
    Queen(1,n);
    printf("\nNo. of solutions is %d.",count);
}
