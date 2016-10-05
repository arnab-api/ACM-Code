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
#define oo 1<<30;

int n,m,Left[M],Right[M],used[M],vis[M];
vector<int>edge[M];

void init()
{
    for(int i=0;i<M;i++){
        edge[i].clear();
        Left[i]=-1;
        Right[i]=-1;
    }
}

void DFS(int u)
{
    if(u==-1 || vis[u]==1) return;
    vis[u]=1;
    DFS(Right[u]);
    DFS(Left[u]);
}

int match(int u)
{
    if(used[u]==1) return 0;
    used[u]=1;
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if(Left[v]==-1 || match(Left[v])){
            Right[u]=v;
            Left[v]=u;
            return 1;
        }
    }
    return 0;
}

int BPM()
{
    int path=1,ret=0;
    while(path){
        path=0;
        memset(used,0,sizeof(used));
        for(int i=1;i<=n;i++){
            if(!used[i] && Right[i]==-1){
                path+=match(i);
            }
        }
    }
    //for(int i=1;i<=n;i++) printf("-->%d %d %d\n",i,Left[i],Right[i]);
    /*memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ret++;
            DFS(i);
        }
    }*/
    for(int i=1;i<=n;i++) if(Right[i]!=-1) ret++;
    return ret;
}

int main()
{
	int i,j,k,l,t,a,b,ans,kase=0;
	scanf("%d",&t);
	while(t--){
        init();
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            edge[a].push_back(b);
        }
        //ans=BPM();
        ans=n-BPM();
        printf("Case %d: %d\n",++kase,ans);
	}
	return 0;
}

