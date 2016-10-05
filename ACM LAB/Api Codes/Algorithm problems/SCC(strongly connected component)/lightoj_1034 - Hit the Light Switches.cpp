#include<bits/stdc++.h>
using namespace std;
#define M 10010

int n,m;

vector<int>G[M];
int low[M],dfn[M],belong[M],deg[M],scc,depth,ans;
stack<int>st;

void init()
{
    for(int i=0;i<=n;i++){
        G[i].clear();
        dfn[i]=-1;
        belong[i]=-1;
        deg[i]=0;
    }
    scc=depth=0;
    while(!st.empty()) st.pop();
}

/*void tarjan(int u)
{
    low[u]=dfn[u]=depth++;
    st.push(u);
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(dfn[v]==-1){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(belong[v]==-1) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        int v;
        do{
            v=st.top();
            belong[v]=scc;
            st.pop();
        }while(v!=u);
        scc++;
    }
}*/

void tarjan(int u)
{
    low[u]=dfn[u]=depth++;
    st.push(u);
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(dfn[v]==-1){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(belong[v]==-1) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        int v;
        do{
            v=st.top();
            belong[v]=scc;
            st.pop();
        }while(v!=u);
        scc++;
    }
}

void dfs(int u)
{
    dfn[u]=1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(belong[u]!=belong[v]) deg[belong[v]]++;
        if(!dfn[i]) dfs(i);
    }
}

int main()
{
    int t,kase=0,i,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        init();
        while(m--){
            scanf("%d%d",&a,&b);
            a--; b--;
            G[a].push_back(b);
        }
        for(i=0;i<n;i++) if(dfn[i]==-1) tarjan(i);
        ans=0;
        memset(dfn,0,sizeof(dfn));
        for(i=0;i<n;i++) if(!dfn[i]) dfs(i);
        for(i=0;i<scc;i++) if(deg[i]==0) ans++;
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}
