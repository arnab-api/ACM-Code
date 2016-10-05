#include<bits/stdc++.h>
using namespace std;
#define M 10100

int low[M],dfn[M],parent[M],api[M],depth;
vector<int>G[M];

void init()
{
    for(int i=0;i<M;i++){
        G[i].clear();
        low[i]=-1;
        dfn[i]=-1;
        parent[i]=-1;
        api[i]=-1;
    }
    depth=0;
}

void tarjan(int u)
{
    low[u]=dfn[u]=depth++;
    int children=0;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(dfn[v]==-1){
            parent[v]=u;
            children++;
            tarjan(v);
            low[u]=min(low[u],low[v]);
            if(parent[u]==-1 && children>1) api[u]=1;
            if(parent[u]!=-1 && low[v]>=dfn[u]) api[u]=1;
        }
        else if(v!=parent[u]) low[u]=min(low[u],dfn[v]);
    }
}

int main()
{
    int t,n,m,i,j,a,b,kase=0,cnt;
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d%d",&n,&m);
        while(m--){
            scanf("%d%d",&a,&b);
            a--; b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        cnt=0;
        for(i=0;i<n;i++) if(dfn[i]==-1) tarjan(i);
        for(i=0;i<n;i++) if(api[i]==1) {
            //printf("==>%d",i);
            cnt++;
        }
        //printf("\n");
        printf("Case %d: %d\n",++kase,cnt);
    }
    return 0;
}
