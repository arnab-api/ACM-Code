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
#define M 101
#define oo 1<<30

struct data{
    int lob,hor;
    double val;
    data(){}
    data(int l,int h){
        lob = l;
        hor = h;
        val = (double)lob/hor;
    }
    bool operator < (const data & p)const{
        return val < p.val;
    }
};

vector<data>F;

int n;

void call(int l1,int h1,int l2,int h2)
{
    if(h1+h2>n) return;
    int l3 = (l1+l2);
    int h3 = (h1+h2);
    F.push_back(data(l3,h3));
    call(l1,h1,l3,h3);
    call(l3,h3,l2,h2);
}

int main()
{
	int i,j,k,l,t;
	while(scanf("%d%d",&n,&k)==2){
        F.clear();
        call(0,1,1,1);
        F.push_back(data(1,1));
        sort(F.begin(),F.end());
        printf("%d/%d\n",F[k-1].lob,F[k-1].hor);
	}
	return 0;
}

