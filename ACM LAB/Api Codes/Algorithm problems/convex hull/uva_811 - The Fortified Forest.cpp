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

struct point
{
	double x, y, v, l,id;
	point(double a, double b, double c, double d,double i) {
		x = a; y = b; v = c; l = d; id=i;
	}
	bool operator < (const point & p)const {
		if (x == p.x) return y < p.y;
		return x < p.x;
	}
};

vector<point>P, v;
int n;
vector<int>tree;

double cross(point O, point A, point B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

bool flag[20];

double convex_hull()
{
	int i, k, t;
	double ret=0;
	for(i=0;i<n;i++) if(flag[i]) ret+=P[i].l;
	v.clear();
	for (i = 0; i < n; i++) {
        if(flag[i]) continue;
		k = v.size();
		while (k >= 2 && cross(v[k - 2], v[k - 1], P[i]) <= 0) {
            k--;
			v.pop_back();
		}
		v.push_back(P[i]);
	}
	t = v.size() + 1;
	for (i = n - 2; i >= 0; i--) {
	    if(flag[i]) continue;
		k = v.size();
		while (k >= t && cross(v[k - 2], v[k - 1], P[i]) <= 0) {
            k--;
			v.pop_back();
		}
		v.push_back(P[i]);
	}
	if(v.size()>1) {
        for(i=1;i<v.size();i++){
            ret-=sqrt((v[i].x-v[i-1].x)*(v[i].x-v[i-1].x)+(v[i].y-v[i-1].y)*(v[i].y-v[i-1].y));
        }
        i=v.size();
        ret-=sqrt((v[0].x-v[i-1].x)*(v[0].x-v[i-1].x)+(v[0].y-v[i-1].y)*(v[0].y-v[i-1].y));
	}
	return ret;
}

double Bitmask(int N)
{
    int lim=(1<<N),i,j,k;
    bool fl;
    double mn=100000000000,val,ex,mnex=1010101010,cnt;
    for(i=0;i<lim;i++){
        val=0;
        cnt=0;
        for(j=0;j<N;j++) {
            if(i & (1<<j)){
                //printf("1");
                flag[j]=true;
                val+=P[j].v;
                cnt++;
            }
            else{
                //printf("0");
                flag[j]=false;
            }
        }
        //printf("\n");
        ex=convex_hull();
        if(ex>=0.0){
            fl=false;
            if(val<=mn){
                if(val<mn || cnt<tree.size() || (cnt==tree.size() && ex<mnex)){
                    fl=true;
                }
                if(fl) {
                    mn=val;
                    mnex=ex;
                    tree.clear();
                    for(j=0;j<N;j++) if(i & (1<<j)) tree.push_back(P[j].id);
                }
            }
        }
    }
    return mnex;
}

void init()
{
	P.clear();
	tree.clear();
}

int main()
{
    //freopen("A.txt","w",stdout);
	int i, j, k, t, kase = 0;
	double x, y, v, l;
	while (scanf("%d", &n) == 1) {
        init();
        if(n==0) break;
		for (i = 0; i < n; i++) {
			scanf("%lf%lf%lf%lf", &x, &y, &v, &l);
			P.push_back(point(x, y, v, l,i+1));
		}
		sort(P.begin(), P.end());
		//for (i = 0; i < P.size(); i++) printf("%d %lf %lf %lf %lf\n", i, P[i].x, P[i].y,P[i].v,P[i].l);
        l=Bitmask(n);
        if(kase!=0) printf("\n");
        printf("Forest %d\n",++kase);
        printf("Cut these trees:");
        sort(tree.begin(),tree.end());
        for(i=0;i<tree.size();i++) printf(" %d",tree[i]);
        printf("\nExtra wood: %.2lf\n",l);
	}
	return 0;
}
