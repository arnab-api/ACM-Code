#include<bits/stdc++.h>
using namespace std;
#define M 20010

int n,m;

vector<int>G[M],va,vb,edge[M];
int low[M],dfn[M],belong[M],scc,depth,longest,indeg[M],outdeg[M];
stack<int>st;

void init()
{
    for(int i=0;i<M;i++){
        G[i].clear();
        edge[i].clear();
        dfn[i]=-1;
        belong[i]=-1;
        indeg[i]=0;
        outdeg[i]=0;
    }
    scc=depth=longest=0;
    while(!st.empty()) st.pop();
}

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

int main()
{
    int t,kase=0,i,a,b,in,out,j,ans;
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
        if(scc==1) ans=0;
        else{
            for(i=0;i<n;i++){
                for(j=0;j<G[i].size();j++){
                    a=belong[i];
                    b=belong[G[i][j]];
                    if(a!=b) {
                        outdeg[a]++;
                        indeg[b]++;
                    }
                }
            }
            in=out=0;
            for(i=0;i<scc && scc>0;i++){
                if(!indeg[i]) in++;
                if(!outdeg[i]) out++;
            }
            ans=max(in,out);
        }
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}

