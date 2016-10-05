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
#define oo 1<<30

vector<int>E[M];
int Left[M],Right[M],used[M];

void init()
{
    for(int i=0;i<M;i++){
        E[i].clear();
        Left[i]=-1;
        Right[i]=-1;
    }
}

int match(int u)
{
    if(used[u]) return 0;
    used[u]=1;
    for(int i=0;i<E[u].size();i++){
        int v=E[u][i];
        if(Left[v]==-1 || match(Left[v])){
            Right[u]=v;
            Left[v]=u;
            return 1;
        }
    }
    return 0;
}

int BPM(int N)
{
    int ans=0,path=1;
    while(path){
        path=0;
        memset(used,0,sizeof(used));
        for(int i=0;i<N;i++){
            if(!used[i] && Right[i]==-1) path+=match(i);
        }
    }
    for(int i=0;i<N;i++) if(Right[i]!=-1) ans++;
    return ans/2;
}

int main()
{
	int i,j,k,l,t,n,m,a,b,ans,kase=0;
	scanf("%d",&t);
	while(t--){
        scanf("%d%d",&n,&m);
        init();
        while(m--){
            scanf("%d%d",&a,&b);
            a--;b--;
            E[a].push_back(b);
            E[b].push_back(a);
        }
        ans=n-BPM(n);
        //cerr<<"----------------------->";
        printf("Case %d: %d\n",++kase,ans);
	}
	return 0;
}

