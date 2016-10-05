#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

double distance(double x1, double y1, double x2,double y2)
{
    double value;
    value = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    value = sqrt(value);
    return value;
}

double find_point(double x1,double m,double x2, double n)
{
    double value;
    value = m * x2 + n * x1;
    value = value / (m + n);
    return value;
}

double tri_area(double x1,double y1,double x2,double y2,double x3,double y3)
{
    double value;
    value = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    return value;
}

void line_intersection(double xa,double ya, double d,double xp,double yp,double b,double arrx[5],double arry[5])
{
    double A,B,C;
    A = 2 * (xp - xa);
    B = 2 * (yp - ya);
    C = xa * xa - xp * xp + ya * ya - yp * yp + b * b - d * d;
    double D,E,F,value;
    double ansx1,ansx2,ansy1,ansy2;
    if(fabs(A) <= EPS && B != 0)
    {
        ansy1 = (- C * 1.0 / B);
        ansy2 = ansy1;
        value = d * d - (ansy1 - ya) * (ansy1 - ya);
        value = sqrt(value);
        ansx1 = xa + value;
        ansx2 = xa - value;
    }
    else if(fabs(B) <= EPS && A != 0)
    {
        ansx1 = (- C * 1.0) / A;
        ansx2 = ansx1;
        value = d * d - (ansx1 - xa) * (ansx1 - xa);
        value = sqrt(value);
        ansy1 = ya + value;
        ansy2 = ya - value;
    }
    else
    {
        D = A * A + B * B;
        E = 2 * B * C + 2 * A * B * xa - 2 * A * A * ya;
        F = C * C + A * A * xa * xa + 2 * C * A * xa + A * A * ya * ya - A * A * d * d;
        value = E * E - 4.0 * D * F;
        value = sqrt(value);
        ansy1 = (- E + value) / (2.0 * D);
        ansy2 = (- E - value) / (2.0 * D);
        ansx1 = -(B * ansy1 + C) / A;
        ansx2 = -(B * ansy2 + C) / A;
    }
    double area1,area2;
    area1 = tri_area(xa,ya,xp,yp,ansx1,ansy1);
    area2 = tri_area(xa,ya,xp,yp,ansx2,ansy2);
    if(area1 > 0)
    {
        arrx[0] = ansx1;
        arry[0] = ansy1;
    }
    if(area2 > 0)
    {
        arrx[0] = ansx2;
        arry[0] = ansy2;
    }
}

int main(void)
{
    int T,t;
    double xa,ya,xb,yb,xc,yc,xp,yp,xq,yq;
    double a,b,c,d;
    double area;
    scanf("%d",&T);
    for(t = 1; t <= T; t++)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf",&xa,&ya,&xb,&yb,&b,&c,&d);
        double darrx[5],darry[5],carrx[5],carry[5];
        a = distance(xa,ya,xb,yb);
        xp = find_point(xa,a-c,xb,c);
        yp = find_point(ya,a-c,yb,c);
        line_intersection(xa,ya,d,xp,yp,b,darrx,darry);
        double xd = darrx[0];
        double yd = darry[0];
        xq = find_point(xa,c,xb,a-c);
        yq = find_point(ya,c,yb,a-c);
        line_intersection(xq,yq,d,xb,yb,b,carrx,carry);
        double xc = carrx[0];
        double yc = carry[0];
        printf("Case %d:\n",t);
        printf("%0.8lf %0.8lf %0.8lf %0.8lf\n",xc,yc,xd,yd);
    }
    return 0;
}
