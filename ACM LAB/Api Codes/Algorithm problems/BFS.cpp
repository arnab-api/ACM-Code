#include<bits/stdc++.h>
using namespace std;
#define M 1000

int vis[M],D[M],parent[M];
vector<int>edge[M],path;

void init()
{
    memset(vis,0,sizeof(vis));
    memset(D,-1,sizeof(D));
    memset(parent,-1,sizeof(parent));
    path.clear();
    for(int i=0;i<M;i++) edge[i].clear();
}

int BFS(int srce,int dest)
{
    vis[srce]=1;
    D[srce]=0;
    queue<int>q;
    q.push(srce);
    while(!q.empty()){
        int u=q.front(); q.pop();
        int ucost=D[u];
        for(int i=0;i<edge[u].size();i++){
            int v=edge[u][i];
            if(!vis[v]){
                vis[v]=1;
                parent[v]=u;
                D[v]=ucost+1;
                q.push(v);
            }
        }
        if(vis[dest]==1){
            int u=dest;
            while(u!=-1){
                path.push_back(u);
                u=parent[u];
            }
            reverse(path.begin(),path.end());
            for(int i=0;i<path.size()-1;i++) printf("%d --> ",path[i]);
            printf("%d\n",path[path.size()-1]);
            return 1;
        }
    }
    printf("No path exists between %d to %d\n",srce,dest);
    return -1;
}

int main()
{
    int n,m,a,b,s,d,val;
    ///n= number of nodes
    ///m= number of edges
    while(scanf("%d%d",&n,&m)==2){
        init();
        while(m--){
            scanf("%d%d",&a,&b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        scanf("%d%d",&s,&d);
        BFS(s,d);
    }
    return 0;
}
/*
5 6
1 2
2 3
3 6
6 4
4 5
1 4
*/
