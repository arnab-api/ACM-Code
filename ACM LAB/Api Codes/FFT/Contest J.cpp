#include<bits/stdc++.h>
using namespace std;

struct point
{
    double x,y;
    point(double a,double b)
    {
        x=a;
        y=b;
    }
};

bool con(point A,point B)
{
    if(A.y==B.y) return A.x<B.x;
    return A.y<B.y;
}

vector<point>P,v;
int n,l,t,i;

double cross(point O,point A,point B)
{
    return (A.x-O.x)*(B.y-O.y)-(A.y-O.y)*(B.x-O.x);
}

double find_angle(point A,point B,point C)
{
    double a = sqrt((B.x - C.x)*(B.x - C.x) + (B.y - C.y)*(B.y - C.y));
    double b = sqrt((A.x - C.x)*(A.x - C.x) + (A.y - C.y)*(A.y - C.y));
    double c = sqrt((B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y));

    return acos((c*c + a*a - b*b)/(2*a*c));
}

bool convex_hull()
{
    sort(P.begin(),P.end(),con);
    for(i=0; i<n; i++)
    {
        l=v.size();
        while(l>=2 && cross(v[l-2],v[l-1],P[i])<=0)
        {
            l--;
            v.pop_back();
        }
        v.push_back(P[i]);
    }
    t=v.size()+1;
    for(i=n-2; i>=0; i--)
    {
        l=v.size();
        while(l>=t && cross(v[l-2],v[l-1],P[i])<=0)
        {
            l--;
            v.pop_back();
        }
        v.push_back(P[i]);
    }
    //printf("=====> %d\n",v.size());
    if(v.size()<n+1) return false;
    v.push_back(v[1]);
    //for(i=0; i<v.size(); i++) printf("-------------> %.0lf %.0lf\n",v[i].x,v[i].y);
    double angle = 0.0;
    for(i=0;i<v.size()-2;i++){
        //cout<<"=====>>>>>=====>>>>> "<<find_angle(v[i],v[i+1],v[i+2])<<endl;
        if(angle==0.0){
            angle = find_angle(v[i],v[i+1],v[i+2]);
        }
        else {
            if(abs(angle - find_angle(v[i],v[i+1],v[i+2])) > 0.000001) return false;
        }
    }
    if(angle==0) return false;
    return true;
    //if(k) printf("-1\n");
}

int main()
{
    int t;
    double a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        P.clear();
        v.clear();
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&a,&b);
            P.push_back(point(a,b));
        }
        bool flag = convex_hull();

        //cerr<<"----------------->";
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

/**
3
3
0 0
1 1
1 0
4
0 0
0 1
1 0
1 1
5
0 0
0 1
0 2
2 2
2 0
*/
