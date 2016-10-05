#include<bits/stdc++.h>
using namespace std;
#define M 1010

vector<int>G[M],E[M];
int used[M],Left[M],Right[M];

void init()
{
    for(int i=0;i<M;i++){
        E[i].clear();
        G[i].clear();
        Right[i]=-1;
        Left[i]=-1;
        used[i]=0;
    }
}

void DFS(int u)
{
    if(used[u]) return;
    used[u]=1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        DFS(v);
    }
}

int match(int u)
{
    if(used[u]) return 0;
    used[u]=1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
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
    int path=1,ret=0;
    while(path){
        path=0;
        memset(used,0,sizeof(used));
        for(int i=0;i<N;i++) if(Right[i]==-1 && used[i]==0) path+=match(i);
    }
    for(int i=0;i<N;i++) if(Right[i]!=-1) ret++;
    //for(int i=0;i<N;i++) printf(" %d ---> %d %d\n",i+1,Right[i]+1,Left[i]+1);
    return ret;
}

int dfn[M],low[M],depth,belong[M],scc;
struct jora{
    int from,to;
    jora(int u,int v){
        from=u; to=v;
    }
};
vector<jora>J;
stack<int>st;

void init2(int N)
{
    for(int i=0;i<N;i++){
        dfn[i]=-1;
        low[i]=-1;
        belong[i]=-1;
    }
    J.clear();
    depth=0;
    scc=0;
    while(!st.empty()) st.pop();
}

void tarjan(int u)
{
    dfn[u]=low[u]=depth++;
    st.push(u);
    for(int i=0;i<E[u].size();i++){
        int v=E[u][i];
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
            //printf(" %d",v+1);
        }while(v!=u);
        //printf(" ===>> %d\n",scc);
        scc++;
    }
}

int main()
{
    int t,n,m,kase=0,a,b,ans,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        init();
        init2(n);
        while(m--){
            scanf("%d%d",&a,&b);
            a--;b--;
            G[a].push_back(b);
        }
        /*for(i=0;i<n;i++){
            printf("%d -->",i+1);
            for(j=0;j<G[i].size();j++) printf(" %d",G[i][j]+1);
            printf("\n");
        }*/
        for(i=0;i<n;i++){
            memset(used,0,sizeof(used));
            DFS(i);
            for(j=0;j<n;j++){
                if(used[j]){
                    if(j==i) continue;
                    E[i].push_back(j);
                    J.push_back(jora(i,j));
                }
            }
        }
        /*for(i=0;i<n;i++){
            printf("%d ----->",i+1);
            for(j=0;j<E[i].size();j++) printf(" %d",E[i][j]+1);
            printf("\n");
        }*/
        for(i=0;i<n;i++) if(dfn[i]==-1) tarjan(i);
        for(i=0;i<n;i++) G[i].clear();
        for(i=0;i<J.size();i++){
            a=belong[J[i].from];
            b=belong[J[i].to];
            if(a!=b) G[a].push_back(b);
        }
        /*for(i=0;i<n;i++){
            printf("%d ----->>>>>>",i);
            for(j=0;j<G[i].size();j++) printf(" %d",G[i][j]);
            printf("\n");
        }*/
        ans=scc-BPM(scc);
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}
