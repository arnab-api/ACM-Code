#include<bits/stdc++.h>
using namespace std;
#define M 10010

vector<int>G[M];
int low[M],dfn[M],parent[M],depth,Bridge[M],D[M],cnt;

void init()
{
    for(int i=0;i<M;i++){
        G[i].clear();
        low[i]=-1;
        dfn[i]=-1;
        parent[i]=-1;
        Bridge[i]=-1;
        D[i]=-1;
    }
    depth=cnt=0;
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
            if(low[v]>dfn[u]){
                //printf("Bridge => %d %d\n",u,v);
                Bridge[u]=v;
                Bridge[v]=u;
            }
        }
        else if(v!=parent[u]) low[u]=min(low[u],dfn[v]);
    }
}

bool isBridge(int u,int v)
{
    if(Bridge[u]==v) return true;
    if(Bridge[v]==u) return true;
    return false;
}

bool found;

void DFS(int u,int d)
{
    if(dfn[u]==1) return;
    cnt++;
    D[u]=d;
    dfn[u]=1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(isBridge(u,v)) continue;
        if(dfn[v]==0) DFS(v,d+1);
        else if((D[u]-D[v])%2==0) found=true;
    }
}

int main()
{
    int a,b,n,m,t,i,j,kase=0,ans;
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
        memset(dfn,0,sizeof(dfn));
        ans=0;
        for(i=0;i<n;i++){
            if(dfn[i]==0){
                found=false;
                cnt=0;
                DFS(i,1);
                if(found) ans+=cnt;
            }
        }
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}
