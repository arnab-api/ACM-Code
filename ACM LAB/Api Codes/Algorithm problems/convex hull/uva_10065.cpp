#include<bits/stdc++.h>
using namespace std;

struct point{
    double x,y;
    point(double a,double b){
        x=a; y=b;
    }
};

vector<point>P,v;
int n;

bool con(point A,point B)
{
    if(A.x==B.x) return A.y<B.y;
    return A.x<B.x;
}

double cross(point O,point A,point B)
{
    return (A.x-O.x)*(B.y-O.y)-(B.x-O.x)*(A.y-O.y);
}

void convex_hull()
{
    int i,j,k,l,t;
    for(i=0;i<n;i++){
        k=v.size();
        while(k>=2 && cross(v[k-2],v[k-1],P[i])<=0){
            k--;
            v.pop_back();
        }
        v.push_back(P[i]);
    }
    t=v.size()+1;
    for(i=n-2;i>=0;i--){
        k=v.size();
        while(k>=t && cross(v[k-2],v[k-1],P[i])<=0){
            k--;
            v.pop_back();
        }
        v.push_back(P[i]);
    }
}

int main()
{
    int i,j,k,l,t,kase=0;
    double x,y,fx,fy,Ac,Ap,rat;
    while(scanf("%d",&n)==1){
        if(n==0) break;
        P.clear();
        v.clear();
        scanf("%lf%lf",&fx,&fy);
        P.push_back(point(fx,fy));
        for(i=1;i<n;i++){
            scanf("%lf%lf",&x,&y);
            P.push_back(point(x,y));
        }
        P.push_back(point(fx,fy));
        Ap=Ac=0;
        for(i=0;i<P.size()-1;i++) Ap+=(P[i].x*P[i+1].y)-(P[i+1].x*P[i].y);
        Ap=abs(Ap)/2;
        P.pop_back();
        sort(P.begin(),P.end(),con);
        convex_hull();
        for(i=0;i<v.size()-1;i++) Ac+=(v[i].x*v[i+1].y)-(v[i+1].x*v[i].y);
        Ac=abs(Ac)/2;
        rat=(1-(Ap/Ac))*100;
        //for(i=0;i<v.size();i++) printf("-->%lf %lf\n",v[i].x,v[i].y);
        //printf("%lf %lf %lf\n",Ap,Ac,rat);
        printf("Tile #%d\nWasted Space = %.2lf %c\n\n",++kase,rat,'%');
    }
    return 0;
}
