#include<bits/stdc++.h>
using namespace std;

double x,y,z;

double subSearch(double a,double b,double limit)
{
    if(abs(a-0)<0.000001) return 0.0;
    if(abs(b-0)<0.000001) return limit;
    int cnt = 200;
    double lo = 0.0, hi = limit , m , m1 , m2;
    while(cnt--){
        m = (hi - lo)/3;
        m1 = lo + m;
        m2 = hi - m;
        if( a*log(m1) + b*log(limit - m1) > a*log(m2) + b*log(limit - m2)) hi = m2;
        else lo = m1;
    }
    return (lo+hi)/2;
}

double ternarySearch(int a,int b,int c,int limit)
{
    int cnt = 200;
    double lo = 0.0, hi = limit , m , m1 , m2 , r1, r2;
    while(cnt--){
        m = (hi - lo)/3;
        m1 = lo + m;
        m2 = hi - m;

        r1 = subSearch(a,b,m1);
        r2 = subSearch(a,b,m2);

        if(a*log(r1) + b*log(m1 - r1) + c*log(limit - m1) >
           a*log(r2) + b*log(m2 - r2) + c*log(limit - m2)) {
               hi = m2;
               x = r1;
               y = m1 - r1;
               z = limit - m1;
           }
        else {
            lo = m1;
            x = r2;
            y = m2 - r2;
            z = limit - m2;
        }
    }
    return (lo+hi)/2;
}

int main()
{
    double a,b,c,s;
    bool a0,b0,c0;
    while(scanf("%lf",&s)==1){
        scanf("%lf",&a);
        scanf("%lf",&b);
        scanf("%lf",&c);
        a0 = false;
        b0 = false;
        c0 = false;
        if(abs(a-0)<.000001) a0 = true;
        if(abs(b-0)<.000001) b0 = true;
        if(abs(c-0)<.000001) c0 = true;

        //if(a0==true) printf("a0 true\n");
        //if(b0==true) printf("b0 true\n");
        //if(c0==true) printf("c0 true\n");

        if(a0==true){
            x = 0.0;
            y = subSearch(b,c,s);
            z = s - y;
        }
        else if(b0==true){
            y = 0.0;
            x = subSearch(a,c,s);
            z = s - x;
        }
        else if(c0==true){
            z = 0.0;
            x = subSearch(a,b,s);
            y = s - x;
        }
        else{
            ternarySearch(a,b,c,s);
        }
        printf("%.10lf %.10lf %.10lf\n",x,y,z);
    }
    return 0;
}
