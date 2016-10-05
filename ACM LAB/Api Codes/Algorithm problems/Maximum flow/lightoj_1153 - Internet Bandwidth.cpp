#include<bits/stdc++.h>
using namespace std;
#define M 110
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

int taken[M],level[M],parent[M];

int BFS(int srce,int dest)
{
    int ret=oo;
    memset(taken,0,sizeof(taken));
    memset(parent,-1,sizeof(parent));
    taken[srce]=0;
    queue<int>q;
    q.push(srce);
    while(!q.empty()){
        int u=q.front(); q.pop();
        int ucost=level[u];
        for(int i=0;i<=n;i++) if(cf[u][i]>0){
            int v=i;
            if(!taken[v]){
                taken[v]=1;
                level[v]=ucost+1;
                parent[v]=u;
                q.push(v);
            }
        }
    }
    if(taken[dest]==0) return 0;
    int node=dest;
    while(node!=srce){
        E.push_back(edge(parent[node],node));
        //printf("--->%d %d\n",node,parent[node]);
        node=parent[node];
    }
    for(int i=0;i<E.size();i++){
        ret=min(ret,cf[E[i].u][E[i].v]);
    }
    return ret;
}

int maxflow(int source,int sink)
{
    int i,j,totalflow=0,mini;
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++) cf[i][j]=cap[i][j];
    }
    while(1){
        E.clear();
        mini=BFS(source,sink);
        //printf("--->%d\n",mini);
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
    int test,kase=0,i,j,source,sink,a,b,w,c,ans;
    scanf("%d",&test);
    while(test--){
        init();
        scanf("%d",&n);
        scanf("%d%d%d",&source,&sink,&c);
        while(c--){
            scanf("%d%d%d",&a,&b,&w);
            cap[a][b]+=w;
            //cap[b][a]+=w;
        }
        ans=maxflow(source,sink);
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}
/**
5
6
0 5 9
0 1 16
0 2 13
1 3 12
2 1 4
3 2 9
2 4 14
4 5 4
4 3 7
3 5 20
**/
