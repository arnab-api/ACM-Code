#include<bits/stdc++.h>
using namespace std;
#define M 1010

int dfn[M],low[M],depth,belong[M],scc,vis[M],indeg[M],outdeg[M];
vector<int>G[M];
struct jora{
    int from,to;
    jora(int u,int v){
        from=u; to=v;
    }
};
vector<jora>E;
stack<int>st;

void init(int N)
{
    for(int i=0;i<N;i++){
        G[i].clear();
        dfn[i]=-1;
        low[i]=-1;
        vis[i]=0;
        belong[i]=-1;
        indeg[i]=0;
        outdeg[i]=0;
    }
    E.clear();
    depth=0;
    scc=0;
    while(!st.empty()) st.pop();
}

void tarjan(int u)
{
    dfn[u]=low[u]=depth++;
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
            //printf(" %d",v);
        }while(v!=u);
        //printf(" ---> %d\n",scc);
        scc++;
    }
}

int main()
{
    //freopen("A.txt","w",stdout);
    int t,i,n,m,kase=0,a,b,in,out,need;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        init(M);
        vis[0]=1;
        while(n--){
            scanf("%d",&m);
            while(m--){
                scanf("%d%d",&a,&b);
                E.push_back(jora(a,b));
                G[a].push_back(b);
                vis[a]=1;
                vis[b]=1;
            }
        }
        for(i=0;i<M;i++) if(vis[i]==1 && dfn[i]==-1) tarjan(i);
        printf("Case %d: ",++kase);
        if(scc==1) printf("YES\n");
        else{
            bool flag=true;
            for(i=0;i<E.size();i++){
                a=belong[E[i].from];
                b=belong[E[i].to];
                if(a!=b){
                    outdeg[a]++;
                    indeg[b]++;
                    if(outdeg[a]>1){flag=false; break;}
                }
            }
            a=belong[0];
            if(outdeg[a]==0) flag=false;
            //for(i=0;i<scc;i++) printf("%d --> %d %d\n",i,indeg[i],outdeg[i]);
            if(flag){
                in=out=0;
                int mid=0,st=0,nd=0;
                /*for(i=0;i<scc;i++){
                    if(!indeg[i]) in++;
                    if(!outdeg[i]) out++;
                }
                need=max(in,out);
                if(need>1) flag=false;*/
                for(i=0;i<scc;i++) {
                    if(outdeg[i]==1 && indeg[i]==0) st++;
                    if(outdeg[i]==0 && indeg[i]==1) nd++;
                    if(outdeg[i]==1 && indeg[i]==1) mid++;
                }
                if(st==1 && nd==1 && st+nd+mid==scc) flag=true;
                else flag=false;
            }
            if(flag) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
