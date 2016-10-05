#include<bits/stdc++.h>
using namespace std;

struct point{
    double x,y;
    //char ch;
    point(double a,double b){
        x=a; y=b; //ch=c;
    }
};

bool con(point A,point B)
{
    if(A.x==B.x) return A.y<B.y;
    return A.x<B.x;
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
    scanf("%d",&t);
    while(t--){
        P.clear();
        v.clear();
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%lf%lf",&a,&b);
            //scanf(" %c",&ch)
            getchar();
            getchar();
            P.push_back(point(a,b));
        }
        sort(P.begin(),P.end(),con);
        for(i=0;i<n;i++){
            k=v.size();
            while(k>=2 && cross(v[k-2],v[k-1],P[i])<0){
                k--;
                v.pop_back();
            }
            v.push_back(P[i]);
        }
        l=v.size()+1;
        for(i=n-2;i>=0;i--){
            k=v.size();
            while(k>=l && cross(v[k-2],v[k-1],P[i])<0){
                k--;
                v.pop_back();
            }
            v.push_back(P[i]);
        }
        printf("%d\n",v.size()-1);
        for(i=0;i<v.size()-1;i++) printf("%.0lf %.0lf\n",v[i].x,v[i].y);
    }
    return 0;
}

