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
#define M 100100
#define oo 1<<30

int tree[M];

int query(int index)
{
    int sum=0;
    while(index>0){
        sum+=tree[index];
        index -= index & (-index);
    }
    return sum;
}

int n;

void update(int index,int x)
{
    while(index<=n){
        tree[index]+=x;
        index += index & (-index);
    }
}

int main()
{
	int i,j,k,l,t,kase=0,p,q,ans;
	scanf("%d",&t);
	while(t--){
        scanf("%d%d",&n,&q);
        memset(tree,0,sizeof(tree));
        for(i=1;i<=n;i++){
            scanf("%d",&k);
            update(i,k);
        }
        printf("Case %d:\n",++kase);
        while(q--){
            scanf("%d",&p);
            if(p==1){
                scanf("%d",&i);
                i++;
                ans = query(i) - query(i-1);
                update(i,-ans);
                //cerr<<"----->";
                printf("%d\n",ans);
            }
            else if(p==2){
                scanf("%d%d",&i,&j);
                i++;
                update(i,j);
            }
            else{
                scanf("%d%d",&i,&j);
                i++;j++;
                ans = query(j) - query(i-1);
                //cerr<<"=====>";
                printf("%d\n",ans);
            }
        }
	}
	return 0;
}

