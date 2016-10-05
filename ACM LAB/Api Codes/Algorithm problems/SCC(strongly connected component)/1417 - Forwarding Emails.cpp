#include<bits/stdc++.h>
using namespace std;
#define M 50100

int dfn[M],low[M],belong[M],n,m,scc,depth,ara[M];
vector<int>G[M];
stack<int>st;

void init()
{
    for(int i=0;i<=n;i++){
        G[i].clear();
        low[i]=-1;
        dfn[i]=-1;
        belong[i]=-1;
    }
    scc=depth=0;
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
        int v=st.top();
        do{
            v=st.top();
            belong[v]=scc;
            st.pop();
        }while(v!=u);
        ara[scc]=u;
        scc++;
    }
}

int cnt=0,taken[M];

void DFS(int u)
{
    if(taken[u]==1) return;
    taken[u]=1;
    cnt++;
    for(int i=0;i<G[u].size();i++) {
        int v=G[u][i];
        if(!taken[v]) DFS(v);
    }
}

int main()
{
    int t,kase=0,i,j,k,l,a,b,maxi,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        init();
        m=n;
        while(m--){
            scanf("%d%d",&a,&b);
            a--; b--;
            G[a].push_back(b);
        }
        for(i=0;i<n;i++) if(dfn[i]==-1) tarjan(i);
        //printf("=====> %d\n",scc);
        //for(i=0;i<scc;i++) printf("%d ",ara[i]+1);
        //printf("\n");
        maxi=0;
        for(i=0;i<scc;i++){
            cnt=0;
            memset(taken,0,sizeof(taken));
            DFS(ara[i]);
            if(cnt>maxi) {
                ans=ara[i]+1;
                maxi=cnt;
            }
            else if(cnt==maxi) ans=min(ans,ara[i]+1);
            //printf("--->%d %d\n",ara[i]+1,cnt);
        }
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}
