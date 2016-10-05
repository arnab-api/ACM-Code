#include<bits/stdc++.h>
using namespace std;
#define M 210
#define oo INT_MAX

int cap[M][M],cf[M][M],n;

struct edge{
    int u,v;
    edge(int a,int b){
        u=a; v=b;
    }
};

vector<edge>E;

void init()
{
    memset(cap,0,sizeof(cap));
    memset(cf,0,sizeof(cf));
    E.clear();
}

int level[M],parent[M],taken[M];

int BFS(int srce,int dest)
{
    memset(taken,0,sizeof(taken));
    memset(parent,-1,sizeof(parent));
    int ret=oo,i;
    taken[srce]=1;
    level[srce]=0;
    queue<int>q;
    q.push(srce);
    while(!q.empty()){
        int u=q.front(); q.pop();
        int ucost=level[u];
        for(i=0;i<=2*n+1;i++) if(cf[u][i]>0){
            int v=i;
            if(!taken[v]){
                level[v]=ucost+1;
                parent[v]=u;
                taken[v]=1;
                q.push(v);
            }
        }
    }
    if(taken[dest]==0) return 0;
    int node=dest;
    while(node!=srce){
        E.push_back(edge(parent[node],node));
        node=parent[node];
    }
    for(i=0;i<E.size();i++) ret=min(ret,cf[E[i].u][E[i].v]);
    return ret;
}

int maxflow(int source,int sink)
{
    int totalflow=0,i,j,mini;
    for(i=0;i<=2*n+1;i++){
        for(j=0;j<=2*n+1;j++) cf[i][j]=cap[i][j];
    }
    while(1){
        E.clear();
        mini=BFS(source,sink);
        if(mini==0) break;
        totalflow+=mini;
        for(i=0;i<E.size();i++){
            cf[E[i].u][E[i].v]-=mini;
            cf[E[i].v][E[i].u]+=mini;
        }
    }
    return totalflow;
}

int main()
{
    int test,kase=0,i,j,a,b,c,m,ans,d,s_srce,s_sink;
    scanf("%d",&test);
    while(test--){
        init();
        scanf("%d",&n);
        for(i=1;i<=n;i++) {
            scanf("%d",&a);
            cap[i][i+n]=a;
        }
        scanf("%d",&m);
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            cap[a+n][b]+=c;
        }
        s_srce=0;
        s_sink=2*n+1;
        scanf("%d%d",&b,&d);
        while(b--){
            scanf("%d",&a);
            cap[s_srce][a]=oo;
        }
        while(d--){
            scanf("%d",&a);
            cap[a+n][s_sink]=oo;
        }
        ans=maxflow(s_srce,s_sink);
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}
