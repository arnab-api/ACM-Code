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
#define M 100010
#define oo 1<<30

struct data{
    int a,b,c;
    data(){}
    data(int x,int y,int z){
        a = x;
        b = y;
        c = z;
    }
    bool operator < (const data & p)const{
        if(a == p.a && b == p.b) return c < p.c;
        if(a == p.a) return b < p.b;
        return a < p.a;
    }
};

data arr[M];
int n,tree[M];

int query(int pos)
{
    int mini = oo;
    while(pos>0){
        mini = min(mini,tree[pos]);
        pos -= pos & (-pos);
    }
    return mini;
}

void update(int pos,int val)
{
    while(pos<=n){
        tree[pos] = min(tree[pos],val);
        pos += pos & (-pos);
    }
}

int main()
{
	int i,j,k,l,t,val,cnt;
	scanf("%d",&t);
	while(t--){
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%d%d%d",&arr[i].a,&arr[i].b,&arr[i].c);
        sort(arr+1,arr+n+1);
        fill(tree,tree+n+5,oo);
        cnt=0;
        for(i=1;i<=n;i++){
            val = query(arr[i].b);
            if(val > arr[i].c) cnt++;
            update(arr[i].b,arr[i].c);
        }
        //cerr<<"---------------->";
        printf("%d\n",cnt);
	}
	return 0;
}
/**
3
3
1 2 3
2 3 1
3 1 2
3
1 2 3
2 3 1
1 2 3
3
1 2 3
1 2 3
1 2 3
**/
