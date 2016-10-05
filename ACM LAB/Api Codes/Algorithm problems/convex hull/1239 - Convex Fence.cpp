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
    return (A.x-O.x)*(B.y-O.y)-(A.y-O.y)*(B.x-O.x);
    //returns +ve if OAB counter clockwise
    //returns -ve if OAB clockwise
    //returns 0 if co-linear
}

int main()
{
    int t,i,j,n,kase=0,k,l;
    double d,x,y,sum,eps = 1e-9;
    scanf("%d",&t);
    while(t--){
        P.clear();
        v.clear();
        scanf("%d%lf",&n,&d);
        for(i=0;i<n;i++){
            scanf("%lf%lf",&x,&y);
            P.push_back(point(x,y));
        }
        sort(P.begin(),P.end(),con);
        //printf("==>\n\n");
        //for(i=0;i<P.size();i++) printf("%lf %lf\n",P[i].x,P[i].y);
        for(i=0;i<n;i++){
            k=v.size();
            while(k>=2 && cross(v[k-2],v[k-1],P[i])<=0){
                k--;
                v.pop_back();
            }
            v.push_back(P[i]);
        }
        l=v.size()+1;
        for(i=n-2;i>=0;i--){
            k=v.size();
            while(k>=l && cross(v[k-2],v[k-1],P[i])<=0){
                k--;
                v.pop_back();
            }
            v.push_back(P[i]);
        }
        //printf("==>\n\n");
        //for(i=0;i<v.size();i++) printf("%lf %lf\n",v[i].x,v[i].y);

        sum=0;
        for(i=1;i<v.size();i++) {
            sum+=sqrt((v[i].x-v[i-1].x)*(v[i].x-v[i-1].x)+(v[i].y-v[i-1].y)*(v[i].y-v[i-1].y));
        }
        sum+=2*pi*d;
        printf("Case %d: %lf\n",++kase,sum+eps);
    }
    return 0;
}
