#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>

using namespace std;

#define MXN
#define MXE
#define MXQ
#define SZE
#define MOD
#define EPS
#define sz 10000+7
#define INF 1000000009
#define HI printf("HI\n")
#define sf scanf
#define pf printf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf4(a,b,c,d) scanf("%d %d %d %d",&a,&b,&c,&d)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sf4ll(a,b,c) scanf("%lld %lld %lld %lld",&a,&b,&c,&d)
#define forln(i,a,n) for(int i=a ; i<n ; i++)
#define foren(i,a,n) for(int i=a ; i<=n ; i++)
#define forg0(i,a,n) for(int i=a ; i>n ; i--)
#define fore0(i,a,n) for(int i=a ; i>=n ; i--)
#define pb push_back
#define ppb pop_back
#define ppf push_front
#define popf pop_front
#define ll long long int
#define ul unsigned long
#define ull unsigned long long
#define fs first
#define sc second
#define clr( a, b ) memset((a),b,sizeof(a))
#define jora pair<int, int>
#define jora_d pair<double, double>
#define jora_ll pair<long long int, long long int>
#define mp make_pair
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define PI acos(0.0)

template<class T1> void deb(T1 e1)
{
    cout<<e1<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}

/// <---------------------------  For Bitmasking  -------------------------------->
//int on( int n, int pos ){
//    return n = n|( 1<<pos );
//}
//bool check( int n, int pos ){
//    return (bool)( n&( 1<<pos ) );
//}
//int off( int n, int pos ){
//    return n = n&~( 1<<pos );
//}
//int toggle( int n, int pos ){
//    return n = n^(1<<pos);
//}
//int count_bit( int n ){
//    return __builtin_popcount( n );
//}
/// <---------------------------  End of Bitmasking  -------------------------------->


/// <---------------------------  For Three Base Numeral System  -------------------------------->
//int triGet(int mask, int pos){
//    return ( mask/powt[pos] ) % 3;
//}
//int triSet(int mask, int v, int pos){
//    int rem = mask%powt[pos];
//    mask /= powt[pos+1];
//    mask = ( mask*3 ) + v;
//    mask = ( mask*powt[pos] ) + rem;
//    return mask;
//}
//void preCalForTri(){
//    int i;
//    powt[0] = 1;
//    for( i = 1; i<16; i++ )
//        powt[i] = 3*powt[i-1];
//}
/// <--------------------------- End of Three Base Numeral System ------------------------------->


// moves

//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/

//double Expo(double n, int p) {
//	if (p == 0)return 1;
//	double x = Expo(n, p >> 1);
//	x = (x * x);
//	return ((p & 1) ? (x * n) : x);
//}

struct Point
{
    double x,y;
    Point(){}
    Point(double a,double b){
        x = a;
        y = b;
    }
    bool operator < (const Point & p)const{
        if(x!=p.x) return x < p.x;
        return y < p.y;
    }
};

vector<Point>P,v;

int dcmp(double val)
{
    if(abs(val - 0.000)<0.000001) return 0;
    if(val < 0) return -1;
    if(val > 0) return 1;
}

int orientation(Point O,Point A,Point B)
{
    double value = (A.x - O.x)*(B.y - O.y) - (A.y - O.y)*(B.x - O.x);
    return dcmp(value);
}

void convex_hull()
{
    sort(P.begin(),P.end());
    int n = P.size(),i,l,k;
    for(i = 0 ; i<n ; i++){
        l = v.size();
        while(l>=2 && orientation(v[l-2],v[l-1],P[i])<=0){
            l--;
            v.pop_back();
        }
        v.push_back(P[i]);
    }
    int t = v.size()+1;
    for(i = n - 2 ; i>=0 ; i--){
        l = v.size();
        while(l>=t && orientation(v[l-2],v[l-1],P[i])<=0){
            l--;
            v.pop_back();
        }
        v.push_back(P[i]);
    }
    v.erase(v.end()-1);
    //for(i=0;i<v.size();i++) printf("=======>  %lf %lf\n",v[i].x,v[i].y);
}

double computeArea(vector<Point>v)
{
    double area = 0.0;
    for(int i=0;i<v.size();i++){
        int j = (i+1)%v.size();
        area += v[i].x*v[j].y - v[j].x*v[i].y;
    }
    //cout<<"--> "<<area<<endl;
    return fabs(area/2.0);
}


Point getInnerDiv(Point A,Point B,double a,double b)
{
    double l = sqrt((B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y));
    double p,q;
    p = (a/b)*l;
    q = l - p;
    double x = (p*B.x + q*A.x)/(p+q);
    double y = (p*B.y + q*A.y)/(p+q);
    return Point(x,y);
}

double triangleArea(Point A,Point B,Point C)
{
    double a = sqrt((B.x - C.x)*(B.x - C.x) + (B.y - C.y)*(B.y - C.y));
    double c = sqrt((B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y));
    double b = sqrt((A.x - C.x)*(A.x - C.x) + (A.y - C.y)*(A.y - C.y));
    double theta = (a*a + b*b - c*c)/(2.0*a*b);
    theta = acos(theta);
    double ret =  abs(.5*a*b*sin(theta));
    vector<Point>pp;
    pp.push_back(A);
    pp.push_back(B);
    pp.push_back(C);
    printf("(%lf,%lf) (%lf,%lf) (%lf,%lf) ====> %lf ---> %lf\n",A.x,A.y,B.x,B.y,C.x,C.y,ret,computeArea(pp));
    return ret;
}

int N;
double a,Area;

double getVal()
{
    int i,prev,next;
    double curr = 0.0;
    Point a,b,c;
    vector<Point>triangle;
    for(int i=0;i<v.size();i++){
        triangle.clear();
        if(i == 0) prev = v.size()-1;
        else prev = i - 1;
        if(i == v.size() - 1) next = 0;
        else next = i + 1;
        triangle.push_back(v[prev]);
        triangle.push_back(v[i]);
        triangle.push_back(v[next]);
        //triangleArea(v[prev],v[i],v[next]);
        curr += computeArea(triangle);
        //cout<<curr<<"  "<<computeArea(triangle)<<endl;
    }
    return curr;
}

int main()
{
    double x,y,ans,r,rmv,allTriangle;
    while(scanf("%lf%d",&a,&N)==2){
        v.clear();
        P.clear();
        for(int i=0;i<N;i++){
            scanf("%lf%lf",&x,&y);
            P.push_back(Point(x,y));
        }
        convex_hull();
        Area = computeArea(v);
        //cout<<"----------->> "<<Area<<endl;
        rmv = Area*(1.0 - a);
        allTriangle = getVal();
        r = rmv/allTriangle;
        //cout<<r<<endl;
        //cout<<Area<<endl;
        //cout<<rmv<<endl;
        //cout<<"=====>"<<allTriangle<<endl;
        r = 1.0/r;
        r = sqrt(r);
        printf("%.10f\n",r);
    }
    return 0;
}
