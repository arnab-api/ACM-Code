#include<bits/stdc++.h>
using namespace std;
#define M 1111

vector<int>edge[M];
int low[M],dfn[M],api[M],depth,scc,belong[M],parent[M],deg[M];

void init()
{
    for(int i=0;i<M;i++){
        edge[i].clear();
        low[i]=-1;
        dfn[i]=-1;
        api[i]=0;
        belong[i]=-1;
        parent[i]=-1;
    }
    scc=depth=0;
}

void tarjan(int u)
{
    low[u]=dfn[u]=depth++;
    int children=0;
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if(dfn[v]==-1){
            parent[v]=u;
            children++;
            tarjan(v);
            low[u]=min(low[u],low[v]);
            //if(parent[u]==-1 && children>1) api[u]=1;
            //if(parent[u]!=-1 && low[v]>=dfn[u]) api[u]=1;
            if(low[v]>dfn[u]) printf("Bridge ==> %d --- %d\n",u,v);
        }
        else if(v!=parent[u])
            low[u]=min(low[u],dfn[v]);
    }
}



int main()
{
    int n,m,i,j,a,b;
    while(scanf("%d%d",&n,&m)==2){
        init();
        while(m--){
            scanf("%d%d",&a,&b);
            //a--; b--;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        for(i=0;i<n;i++) if(dfn[i]==-1) tarjan(i);
        memset(deg,0,sizeof(deg));
        //for(i=0;i<n;i++) if(api[i]==1) printf("==>%d",i);
        //printf("\n");
    }
    return 0;
}
///http://www.geeksforgeeks.org/bridge-in-a-graph/
/*
5 5
1 0
0 2
2 1
0 3
3 4

4 3
0 1
1 2
2 3

7 8
0 1
1 2
2 0
1 3
1 4
1 6
3 5
4 5
*/
///

