//Using Dynamic Programming
#include <stdio.h>
#include <string.h>
int max(int a, int b);
int main()
{
    char x[20],y[20],s[20];
    int L[20][20];
    int i,j,k,n,m,l,p,t;
    printf("Enter string 1: ");
    gets(x);
    printf("Enter string 2: ");
    gets(y);
    n=strlen(x);
    m=strlen(y);
    for (i=0;i<n;i++)
        for(j=0;j<m;j++)
	    if (x[i]==y[j])
            {
                k=i-1;
                p=j-1;
                if(k==-1||p==-1)
                    L[i][j]=1;
                else L[i][j]=L[i-1][j-1]+1;
            }
            else
            {
                k=i-1;
                p=j-1;
                if(k==-1&&p==-1)
                    L[i][j]=0;
                else if (k==-1)
                    L[i][j]=L[i][j-1];
                else if(p==-1)
                    L[i][j]=L[i-1][j];
                else
                    L[i][j]=max(L[i-1][j],L[i][j-1]);
            }

    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
            printf("%d ",L[i][j]);
        printf("\n");
    }
    
    i=n-1;
    j=m-1;
    int index=L[i][j]-1;
    while(i>=0 && j>=0)
    {
	if(i==0 && j==0 && L[i][j]==1)
	{
	    s[index]=x[j];
	    i--;
	    j--;
	    index--;	
	}
	else
	if(L[i][j] != L[i-1][j-1])
	{
	    s[index]=x[j];
	    i--;
	    j--;
	    index--;
	}
	else if(L[i-1][j] > L[i][j-1])
	    i--;
	else j--;
    }

    printf("Longest Common Subsequence: ");
    for(i=0;i<L[n-1][m-1];i++)
    {
	printf("%c",s[i]);
    }
    return 0;
}

int max(int a, int b)
{
    if(a>b)
        return a;
    else return b;
}
