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
#define M 1010

int sg[M];

int get_sg(int p)
{
    if(sg[p]!=-1) return sg[p];
    int vis[M];
    memset(vis,0,sizeof(vis));
    int half=(p)/2;
    for(int i=1;i<=half;i++) vis[get_sg(p-i)]=1;
    for(int i=0;;i++) if(!vis[i]) return sg[p]=i;
}

void call()
{
    memset(sg,-1,sizeof(sg));
    sg[0]=sg[1]=0;
    for(int i=2;i<M;i++) sg[i]=get_sg(i);
}

int main()
{
	int i,j,k,l,t,kase=0,n,a,res;
	call();
	scanf("%d",&t);
	while(t--){
        scanf("%d",&n);
        res=0;
        for(i=0;i<n;i++){
            scanf("%d",&a);
            res=res^get_sg(a);
        }
        printf("Case %d: ",++kase);
        if(!res) printf("Bob\n");
        else printf("Alice\n");
	}
	return 0;
}

