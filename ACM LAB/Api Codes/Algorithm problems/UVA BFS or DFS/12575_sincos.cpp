#include<stdio.h>
#include<math.h>
#define  pi  acos( -1 )
#define eps 1e-6

int main()
{
    int t;
    double a, b;
    scanf( "%d", &t );
    while( t-- )
    {
        scanf("%lf%lf",&a,&b);
        double max=sqrt(a*a+b*b);
        double q=atan2(a,b);
        if(q<0) q+=pi+pi;
        printf("%.2lf %.2lf\n",q+eps,max+eps);
    }
    return 0;
}
