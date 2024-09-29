#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// Gauss seidal method
int main()
{
    int n,i,j,iterations;
    printf("Enter the value of n for n*n grid:");
    scanf("%d",&n);
    printf("enter the number of iteration:");
    scanf("%d",&iterations);
    float u[n][n];
    for(i=0;i<n;i++)
    {
        u[i][0]=0;
        u[n-1][i]=0;
        u[i][n-1]=0;
    }
   for(i=1;i<n-1;i++)
   {
       u[0][i]=100;
   }
   for(i=1;i<n-1;i++)
   {
       for(j=1;j<n-1;j++)
        u[i][j]=0;
   }
    printf("The inital grid is:\n");
    for(j=n-1;j>=0;j--)
    {
        for(i=0;i<n;i++)
            printf("%3.2f\t",u[i][j]);
        printf("\n");
    }
    for(int iter=0;iter<iterations;iter++)
    {
        for(i=1;i<n-1;i++)
        {
            for(j=1;j<n-1;j++)
                u[i][j]=0.25*(u[i-1][j]+u[i+1][j]+u[i][j-1]+u[i][j+1]);
        }
        printf("iteration %d:\n",iter+1);
        for(j=0;j<=n-1;j++)
        {
            for(i=0;i<n;i++)
                printf("%3.2f\t",u[i][j]);
            printf("\n");
        }
    }
  
}