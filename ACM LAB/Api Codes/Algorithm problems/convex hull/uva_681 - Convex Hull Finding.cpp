#include<bits/stdc++.h>
using namespace std;

struct point{
    double x,y;
    point(double a,double b){
        x=a; y=b;
    }
};

bool con(point A,point B)
{
    if(A.y==B.y) return A.x<B.x;
    return A.y<B.y;
}

vector<point>P,v;

double cross(point O,point A,point B)
{
    return (A.x-O.x)*(B.y-O.y)-(A.y-O.y)*(B.x-O.x);
}

int main()
{
    int i,j,n,k,l,u,t;
    double a,b;
    scanf("%d",&k);
    printf("%d\n",k);
    while(k--){
        P.clear();
        v.clear();
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%lf%lf",&a,&b);
            P.push_back(point(a,b));
        }
        if(k) scanf("%d",&u);
        sort(P.begin(),P.end(),con);
        for(i=0;i<n;i++){
            l=v.size();
            while(l>=2 && cross(v[l-2],v[l-1],P[i])<=0){
                l--;
                v.pop_back();
            }
            v.push_back(P[i]);
        }
        t=v.size()+1;
        for(i=n-2;i>=0;i--){
            l=v.size();
            while(l>=t && cross(v[l-2],v[l-1],P[i])<=0){
                l--;
                v.pop_back();
            }
            v.push_back(P[i]);
        }
        printf("%d\n",v.size());
        for(i=0;i<v.size();i++) printf("%.0lf %.0lf\n",v[i].x,v[i].y);
        if(k) printf("-1\n");
    }
    return 0;
}

