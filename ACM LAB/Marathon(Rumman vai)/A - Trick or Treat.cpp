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
#define MAX 50050
#define oo 1<<30
#define lli long long int

struct Point
{
    double x;
    double y;
    Point(){}
    Point(double xx,double yy){
        x = xx;
        y = yy;
    }
};

double getDistance(Point A,Point B)
{
    return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}

Point arr[MAX];
int n;

double call(double x)
{
    double maxi = -1;
    for(int i=0;i<n;i++) maxi = max(maxi,getDistance(Point(x,0),arr[i]));
    return maxi;
}

Point ternary_search()
{
    double lo = -200020;
    double hi = 200020,d1,d2,d,fd1,fd2,ans;
    int cnt = 111;
    while(cnt--){
        d = (hi-lo)/3.0;
        d1 = lo + d;
        d2 = hi - d;
        fd1 = call(d1);
        fd2 = call(d2);
        //cout<<fd1<<"<_"<<d1<<"------"<<d2<<"_>"<<fd2<<endl;
        if(fd2>fd1) hi = d2;
        else lo = d1;
    }
    ans = (lo+hi)/2.0;
    return Point(ans,call(ans));
}

int main()
{
	int i,j,k,l,t;
	double x,y;
	Point ans;
    while(scanf("%d",&n)==1){
        if(!n) break;
        for(i=0;i<n;i++){
            scanf("%lf%lf",&x,&y);
            arr[i] = Point(x,y);
        }
        ans = ternary_search();
        cerr<<"--------------->";
        printf("%.9lf %.9lf\n",ans.x,ans.y);
    }
	return 0;
}
/**
2
1.5 1.5
3 0
1
0 0
4
1 4
4 4
-3 3
2 4
5
4 7
-4 0
7 -6
-2 4
8 -5
0

*/
