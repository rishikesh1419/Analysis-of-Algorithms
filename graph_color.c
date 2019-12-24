#include <stdio.h>
#include <stdbool.h>
int x[10], g[10][10], m, n, c;
bool isSafe (int k, int c);
void graphColor (int k);
int main()
{
    int e,i,j,k,l;
    printf("Enter no. of colors: ");
    scanf("%d",&m);
    printf("Enter no. of vertices: ");
    scanf("%d",&n);
    printf("Enter no. of edges: ");
    scanf("%d",&e);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            g[i][j] = 0;
    printf("Vertices and colors are named as 1,2,3,...\n");
    printf("Enter the edges (u,v) as- u v\n");
    for (i=0; i<e; i++)
    {
        scanf("%d %d", &k, &l);
        g[k-1][l-1]=1;
        g[l-1][k-1]=1;
    }
    graphColor(0);
    printf("Vertex - Colour\n");
    for (i=0;i<n;i++)
    printf(" %d    -   %d\n",i+1,x[i]);
}
void graphColor (int k)
{
    int c;
    for (c=1; c<=m; c++)
    {
        if (isSafe(k,c))
        {
            x[k]=c;
            if (k+1 < n)
                graphColor (k+1);
            return;
        }
    }
    return;
}
bool isSafe (int k, int c)
{
    int i;
    for (i=0; i<n; i++)
    {
        if ((g[k][i]==1) && (c==x[i]))
        {
            return false;
        }
    }
    return true;
}
