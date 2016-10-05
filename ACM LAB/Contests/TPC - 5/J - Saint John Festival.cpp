//#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<climits>
#include<cstring>
#include<cstdlib>

#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>

#include<vector>
#include<map>
#include<string>
#include<queue>
#include<set>
#include<iterator>
#include<numeric>
#include<stack>
#include<list>
using namespace std;
#define pi acos(-1)
#define M
#define oo 1<<30
#define lli long long int

struct point
{
    double x,y;
    long double ang;
    point(double a,double b)
    {
        x=a;
        y=b;
        ang = 0.0;
    }
    bool operator < (const point & p) const
    {
        return ang < p.ang;
    }
    point operator - (const point & p) const
    {
        return point(x - p.x , y - p.y);
    }
};

bool con(point A,point B)
{
    if(A.x==B.x) return A.y<B.y;
    return A.x<B.x;
}

bool con2(point A,point B)
{
    if(A.y==B.y) return A.x<B.x;
    return A.y<B.y;
}

vector<point>P,p_small,v;

int orientation(point O,point A,point B)
{
    double value = (A.x-O.x)*(B.y-O.y)-(A.y-O.y)*(B.x-O.x);
    if(abs(value - 0.0)<.000001) return 0;  /// co-linear
    if(value > 0.0) return 1; /// anticlockwise
    else return -1; /// clockwise
}

void convex_hull(int n)
{
    int i,l,k,t;
    sort(P.begin(),P.end(),con);
    //for(i=0;i<n;i++) printf("---> %lf %lf\n",P[i].x,P[i].y);
    for(i=0; i<n; i++)
    {
        l=v.size();
        while(l>=2 && orientation(v[l-2],v[l-1],P[i])<=0)
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
        while(l>=t && orientation(v[l-2],v[l-1],P[i])<=0)
        {
            l--;
            v.pop_back();
        }
        v.push_back(P[i]);
    }
    //printf("%d\n",v.size());
    //for(i=0; i<v.size(); i++) printf("============> %lf %lf\n",v[i].x,v[i].y);
}

void init()
{
    P.clear();
    p_small.clear();
    v.clear();
}

set<point>st;
set<point>:: iterator it;

int dcmp(double x)
{
    if(fabs(x)<.00000001) return 0;
    return x < 0 ? -1 : 1;
}

double cross(point a,point b)
{
    return a.x*b.y -  a.y*b.x;
}

set<point>:: iterator pre(set<point>:: iterator it)
{
    if(it == st.begin()) it = st.end();
    return --it;
}

double tx,ty;

/// must be done before checkBelong
void preProcess()
{
    tx = 0, ty=0;
    int n = v.size();
    for(int i=0; i<n; i++)
    {
        tx += v[i].x;
        ty += v[i].y;
    }
    tx/=n;
    ty/=n;
    for(int i=0; i<n; i++)
    {
        point tmp = v[i];
        tmp.ang = atan2(v[i].y - ty,v[i].x - tx);
        st.insert(tmp);
    }
    //v.erase(v.begin())
    for(it = st.begin();it!=st.end();it++) {
        point tmp = *it;
        //printf(">>>>> %lf %lf\n",tmp.x,tmp.y);
    }
}

/// weather a point is inside the convex hull or not
bool checkBelong(point tmp)
{
    //printf("=========> %lf %lf ----->   ",p_small[i].x,p_small[i].y);
    tmp.ang = atan2(tmp.y - ty,tmp.x - tx);
    if(dcmp(tmp.x - tx) == 0 && dcmp(tmp.y - ty) == 0)
    {
        //cout<< "true";
        return true;
    }
    else
    {
        it = st.lower_bound(tmp);
        if(it == st.end()) it = st.begin();
        if(dcmp(cross(tmp - *pre(it) , *it - *pre(it)))<=0 )  /// <= er jaygay < bosale sudhu vitore
        {
            //cout<< "true";
            return true;
        }
    }
    //cout<<endl;
    return false;   /// point does not belong to convex hull
}

int find_total(int m)
{
    int cnt = 0;
    st.clear();
    preProcess(); ///***///
    for(int i=0; i<m; i++)
    {
        if(checkBelong(p_small[i])) cnt++;
    }
    return cnt;
}

int main()
{
    int i,j,k,L,S,t,ans;
    double x,y;
    while(scanf("%d",&L)==1)
    {
        init();
        for(i=0; i<L; i++)
        {
            scanf("%lf%lf",&x,&y);
            P.push_back(point(x,y));
        }
        scanf("%d",&S);
        for(i=0; i<S; i++)
        {
            scanf("%lf%lf",&x,&y);
            p_small.push_back(point(x,y));
        }
        //for(i=0;i<S;i++) printf("=========> %lf %lf\n",p_small[i].x,p_small[i].y);
        convex_hull(L);
        //printf("anticlock =================>   %d\n",orientation(v[0],v[1],v[2]));
        //printf("clock =================>   %d\n",orientation(v[2],v[1],v[0]));
        ans = find_total(S);
        //cerr<<"---------------------->  ";
        printf("%d\n",ans);
    }
    return 0;
}
/**

5
0 0
10 10
9 0
19 9
8 0
0
*/
