///HEADER FILES///

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<cstdlib>
#include<complex>
#include<iomanip>
#include<utility>
#include<bitset>
#include<list>
#include<assert.h>
#include<numeric>
#include<fstream>
using namespace std;

///DEFINES///

///ALWAYS USEFUL
#define     caseprint(case)     printf("Case %d: ", case++)
#define     clr(a)              memset(a, 0, sizeof(a))
#define     mem(a, b)           memset(a, b, sizeof(a))
#define     pb                  push_back
#define     pp                  pop_back
#define     ful_vec(v)          v.begin(), v.end()
#define     sort_vec(v)         sort(fulvec(v))
#define     sz(a)               (int)a.size()
#define     sf                  scanf
#define     pf                  printf
#define     NL                  pf("\n")
#define     bitcheck(n, pos)    (n & (1<<(pos)))
#define     biton(n, pos)       (n | (1<<(pos)))
#define     bitoff(n, pos)      (n & ~(1<<(pos)))

///SCAN
#define     sfs                 scanf("%s", &a)
#define     sfi1(a)             scanf("%d", &a)
#define     sfi2(a, b)          scanf("%d %d", &a, &b)
#define     sfi3(a, b, c)       scanf("%d %d %d", &a, &b, &c)
#define     sfi4(a, b, c, d)    scanf("%d %d %d %d", &a, &b, &c, &d)
#define     sfd1(a)             scanf("%lf", &a)
#define     sfd2(a, b)          scanf("%lf %lf", &a, &b)
#define     sfd3(a, b, c)       scanf("%lf %lf %lf", &a, &b, &c)
#define     sfd4(a, b, c, d)    scanf("%lf %lf %lf %lf", &a, &b, &c, &d)
#define     sfll1(a)            scanf("%lld", &a)
#define     sfll2(a, b)         scanf("%lld %lld", &a, &b)
#define     sfll3(a, b, c)      scanf("%lld %lld %lld", &a, &b, &c)
#define     sfll4(a, b, c, d)   scanf("%lld %lld %lld %lld", &a, &b, &c, &d)
#define     sfull1(a)           scanf("%llu", &a)
#define     sfull2(a, b)        scanf("%llu %llu", &a, &b)
#define     sfull3(a, b, c)     scanf("%llu %llu %llu", &a, &b, &c)
#define     sfull4(a, b, c, d)  scanf("%llu %llu %llu %llu", &a, &b, &c, &d)

///GEOMETRY
#define     ang(a, b, c)            acos((sqr(b)+sqr(c)-sqr(a))/(2.0*b*c))
#define     dist(x1, y1, x2, y2)    sqrt(sqr(x1-x2)+sqr(y1-y2))

///TYPES///
typedef     long long           ll;
typedef     unsigned long long  ull;

///TEMPLATES///
template<class T1>void check(T1 e)
{
    cout <<"-->"<< e << endl;
}
template<class T1, class T2> void check(T1 e1, T2 e2)
{
    cout <<"-->"<< e1 << " " << e2 << endl;
}
template<class T1, class T2, class T3> void check(T1 e1, T2 e2, T3 e3)
{
    cout <<"-->"<< e1 << " " << e2 << " " << e3 << endl;
}
template<class T1, class T2, class T3, class T4> void check(T1 e1, T2 e2, T3 e3, T4 e4)
{
    cout <<"-->"<< e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template<class T1, class T2, class T3, class T4, class T5> void check(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5)
{
    cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template<class T1, class T2, class T3, class T4, class T5, class T6> void check(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6)
{
    cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6 << endl;
}

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} ret urn R;} /// (B^P)%M

//int x[] = {0,0,-1,1};//4-ways
//int y[] = {1,-1,0,0};//4-ways
//int x[] = {-1,-1,-1,0,0,1,1,1};//8-ways
//int y[] = {-1,0,1,-1,1,-1,0,1};//8-ways
//int x[] = {-2,-2,2,2,1,1,-1,-1};//knight moves
//int y[] = {1,-1,1,-1,2,-2,2,-2};//knight moves

///CONSTANTS
#define     pi                  acos(-1.0)
#define     ex                  exp(1)
#define     oo                  (1<<30)

///OTHERS
#define     sqr(a)              (a*a)
#define     debug               printf("Ok\n")
#define     MOD                 1000000007
#define     M                   1000

struct info
{
    double x, y, s;
    bool operator<(const info &p)const
    {
        return s<p.s;
    }
};

double area(pair<double, double>a, pair<double, double>b, pair<double, double>c)
{
    double ans=0.5*((a.first*(b.second-c.second))+(b.first*(c.second-a.second))+(c.first*(a.second-b.second)));
    return ans;
}

int n;
pair<double, double>point[M], CH[M];
double slope[M];
vector<info>v;

int main()
{
    while(sfi1(n)==1)
    {
        int i, j;
        for(i=0; i<n; i++)
        {
            sfd2(point[i].first, point[i].second);
        }
        sort(point, point+n);
        double x=point[0].first, y=point[0].second;
        info in;
        for(i=1; i<n; i++)
        {
            in.x=point[i].first;
            in.y=point[i].second;
            in.s=(point[i].second-y)/(point[i].first-x);
            v.pb(in);
        }
        sort(v.begin(), v.end());
        /*for(i=0; i<v.size(); i++)
        {
            pf("%.3lf  %.3lf  %.3lf\n", v[i].x, v[i].y, v[i].s);
        }*/
        CH[0]=point[0];
        CH[1]=point[1];
        CH[2]=point[2];
        j=3;
        for(i=3; i<n; i++)
        {
            while(area(CH[j-2], CH[j-1], point[i])<=0) j--;
            CH[j++]=point[i];
        }

        for(i=0; i<j; i++)
        {
            pf("%.4lf  %.4lf\n", CH[i]);
        }
    }

    return 0;
}

/*
6
0 10
1 0
1 1
2 2
3 3
10 10
*/
