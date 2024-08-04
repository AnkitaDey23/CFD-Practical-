#include <stdio.h>

float f(int i)
{
   return (i*(8-i)/2.0);
}
int main()
{
 int i,j,m,n;
 float h,k,c,r,u[20][20];
 h=1.0,k=0.125,c=1,m=8,n=5;
 for(j=0;j<n+1;j++)
{
    u[0][j]=0;
    u[m][j]=0;
}
for(i=1;i<m;i++)
    u[i][0]=f(i);
r=0.5;
for(j=0;j<n;j++)
{
    for(i=1;i<m;i++)
    {
        u[i][j+1]=r*u[i-1][j]+(1-2*r)*u[i][j]+r*u[i+1][j];
        printf("\n");
    }
}
printf("The solution of heat equation:\n");
printf("(i,j)\t");
for(i=0;i<=m;i++)
    printf("u(%d,j)\t",i);
printf("\n");
for(j=0;j<n+1;j++)
{
    printf("(i,%d)\t",j);
    {
        for(i=0;i<=m;i++)
            printf("%5.2f\t",u[i][j]);
        printf("\n");
    }
}
return 0;
}
