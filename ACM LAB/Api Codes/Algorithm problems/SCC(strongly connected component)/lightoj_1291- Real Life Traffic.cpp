#include<bits/stdc++.h>
using namespace std;
#define M 10010

vector<int>G[M];
int low[M],dfn[M],parent[M],deg[M],depth;

void init()
{
    for(int i=0;i<M;i++){
        G[i].clear();
        low[i]=-1;
        dfn[i]=-1;
        parent[i]=-1;
        deg[i]=0;
    }
    depth=0;
}

void tarjan(int u)
{
    low[u]=dfn[u]=depth++;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(dfn[v]==-1){
            parent[v]=u;
            tarjan(v);
            low[u]=min(low[u],low[v]);
            //if(low[v]>dfn[u]) printf("Bridge ==> %d %d\n",u,v);
        }
        else if(v!=parent[u]) low[u]=min(low[u],dfn[v]);
    }
}

void update_deg(int n)
{
    for(int u=0;u<n;u++){
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(low[u]!=low[v]) deg[low[u]]++;
        }
    }
}

int main()
{
    int n,m,a,b,t,i,cnt,kase=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        init();
        while(m--){
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        for(i=0;i<n;i++) if(dfn[i]==-1) tarjan(i);
        update_deg(n);
        cnt=0;
        for(i=0;i<n;i++) if(deg[i]==1) cnt++;
        printf("Case %d: %d\n",++kase,(cnt+1)/2);
    }
    return 0;
}
