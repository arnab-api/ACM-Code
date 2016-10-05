#include<bits/stdc++.h>
using namespace std;
#define M 50100
#define pi acos(-1.0)

struct point{
    double x,y;
    point(double a,double b){
        x=a; y=b;
    }
};

vector<point>P,v;

bool con(point A,point B)
{
    if(A.x==B.x) return A.y<B.y;
    return A.x<B.x;
}

double cross(point O,point A,point B)
{
    (A.x-O.x)*(B.y-O.y)-(A.y-O.y)*(B.x-O.x);

    //returns +ve if OAB counter clockwise
    //returns -ve if OAB clockwise
    //returns 0 if co-linear
}

double angle(point A,point B,point C)
{
    //printf("(%lf,%lf) (%lf,%lf) (%lf,%lf)\n",A.x,A.y,B.x,B.y,C.x,C.y);
    double b=sqrt((A.x-C.x)*(A.x-C.x)+(A.y-C.y)*(A.y-C.y));
    double a=sqrt((B.x-C.x)*(B.x-C.x)+(B.y-C.y)*(B.y-C.y));
    double c=sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
    double angB=(a*a+c*c-b*b)/(2*a*c);
    angB=acos(angB);
    return 180*angB/pi;
}

int main()
{
    int t,i,j,n,kase=0,k,l,lst;
    double d,x,y,sum,eps = 1e-9,mn;
    scanf("%d",&t);
    while(t--){
        P.clear();
        v.clear();
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%lf%lf",&x,&y);
            P.push_back(point(x,y));
        }
        sort(P.begin(),P.end(),con);
        //printf("==>\n\n");
        //for(i=0;i<P.size();i++) printf("%lf %lf\n",P[i].x,P[i].y);
        for(i=0;i<n;i++){
            k=v.size();
            while(k>=2 && cross(v[k-2],v[k-1],P[i])<=0 && angle(v[k-2],v[k-1],P[i])<=90){
                k--;
                v.pop_back();
            }
            v.push_back(P[i]);
        }
        /*l=v.size()+1;
        for(i=n-2;i>=0;i--){
            k=v.size();
            while(k>=l && cross(v[k-2],v[k-1],P[i])<=0 && angle(v[k-2],v[k-1],P[i])<=90){
                k--;
                v.pop_back();
            }
            v.push_back(P[i]);
        }*/
        printf("==>\n\n");
        for(i=0;i<v.size();i++) printf("%lf %lf\n",v[i].x,v[i].y);
    }
    return 0;
}

