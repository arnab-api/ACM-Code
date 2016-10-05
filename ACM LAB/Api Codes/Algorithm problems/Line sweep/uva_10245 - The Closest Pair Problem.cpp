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

int n;
vector<pair<double,double> > v;
set<pair<double,double> > setx,sety;
set<pair<double,double> > :: iterator it,itx,lb,ub;

void init()
{
    v.clear();
    setx.clear();
    sety.clear();
}

double get_dis(pair<double,double>A,pair<double,double>B)
{
    return sqrt((A.first - B.first)*(A.first - B.first)+(A.second - B.second)*(A.second - B.second));
}

double find_closest_pair()
{
    double ans = 1000000.00;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        for(it = setx.begin();it!=setx.end();itx=it++,setx.erase(itx)){
            if((v[i].first - it->first) > ans) {
                sety.erase(sety.lower_bound(make_pair(it->second,it->first)));
            }
            else break;
        }
        lb = sety.lower_bound(make_pair(v[i].second - ans,-40000));
        ub = sety.upper_bound(make_pair(v[i].second + ans,+40000));
        while(lb!=ub){
            ans = min(ans,get_dis(v[i],make_pair(lb->second,lb->first)));
            lb++;
        }
        setx.insert(make_pair(v[i].first,v[i].second));
        sety.insert(make_pair(v[i].second,v[i].first));
    }
    return ans;
}

int main()
{
	int i,j,k,l,t;
	double x,y,ans;
    while( scanf("%d",&n)==1){
        if(n==0) break;
        init();
        for(i=0;i<n;i++) {
            scanf("%lf%lf",&x,&y);
            v.push_back(make_pair(x,y));
        }
        ans = find_closest_pair();
        if(ans>=10000.0) printf("INFINITY\n");
        else printf("%.4lf\n",ans);
    }
	return 0;
}

