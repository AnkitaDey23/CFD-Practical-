#include<stdio.h>
int main()
{
    int i,n;
    float h,k,L,t1,t2,q,A,B,Q;
    float a[10],b[10],c[10],d[10],alpha[10],beta[10],x[10];
    printf("enter the value of initial and final temperature:\n");
    scanf("%f %f",&t1,&t2);
    printf("enter the length of the rod:\n");
    scanf("%f",&L);
    printf("enter the thermal conductivity:\n");
    scanf("%f",&k);
    printf("enter the cross sectional area:\n");
    scanf("%f",&A);
    printf("enter the nodal points:\n");
    scanf("%d",&n);
    printf("enter the value of q:\n");
    scanf("%f",&q);
    h=L/n;
    B=(k*A)/h;
    Q=q*A*h;
    for(i=2;i<=n;i++)
        a[i]=-B;
    for(i=1;i<n;i++)
        c[i]=-B;
    for(i=1;i<=n;i++)
    {
        if(i==1 || i==n)
            b[i]=3*B;
        else
            b[i]=2*B;
    }
    for(i=2;i<n;i++)
        d[i]=Q;
    d[1]=2*B*t1+Q;
    d[n]=2*B*t2+Q;
    alpha[1]=b[1];
    beta[1]=d[1]/b[1];
    for(i=2;i<=n;i++)
    {
        alpha[i]=b[i]-((a[i]*c[i-1])/alpha[i-1]);
        beta[i]=(d[i]-(a[i]*beta[i-1]))/alpha[i];
    }
    x[n]=beta[n];
    for(i=n-1;i>0;i--)
        x[i]=beta[i]-((c[i]*x[i+1])/alpha[i]);
    printf("the solution is:\n");
    for(i=1;i<=n;i++)
    {
        printf("%3.2f",x[i]);
        if(i<n)
            printf(",");
    }
    printf("\n");
}