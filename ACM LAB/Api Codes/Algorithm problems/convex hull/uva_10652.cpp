#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)

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
    n=P.size();
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
    //freopen("A.txt","w",stdout);
    int i,j,k,l,t,kase=0;
    double xc,yc,xm,ym,x1,y1,x2,y2,x3,y3,x4,y4,theta,beta,w,h,A,Ac,rat;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        P.clear();
        v.clear();
        A=Ac=0;
        for(i=0;i<n;i++){
            scanf("%lf%lf%lf%lf%lf",&xc,&yc,&w,&h,&theta);
            beta=90-theta;
            theta=theta*pi/180;
            beta=beta*pi/180;
            xm=xc-.5*h*sin(theta); ym=yc-.5*h*cos(theta);
            x1=xm-.5*w*sin(beta); y1=ym+.5*w*cos(beta);
            x2=2*xm-x1; y2=2*ym-y1;
            x3=2*xc-x1; y3=2*yc-y1;
            x4=2*xc-x2; y4=2*yc-y2;

            P.push_back(point(x1,y1));
            P.push_back(point(x2,y2));
            P.push_back(point(x3,y3));
            P.push_back(point(x4,y4));
            A+=w*h;
        }
        sort(P.begin(),P.end(),con);
        convex_hull();
        //for(i=0;i<P.size();i++) printf("%lf %lf\n",P[i].x,P[i].y);
        //for(i=0;i<v.size();i++) printf("-->%lf %lf\n",v[i].x,v[i].y);
        for(i=0;i<v.size()-1;i++) Ac+=(v[i].x*v[i+1].y)-(v[i+1].x*v[i].y);
        Ac=abs(Ac)/2;
        //printf("%lf %lf ",A,Ac);
        rat=(A/Ac)*100;
        printf("%.1lf %c\n",rat,'%');
    }
    return 0;
}

