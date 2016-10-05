#include<bits/stdc++.h>
using namespace std;
#define M 1111

int vis[M],ans[M];
vector<int>edge[M];

void init()
{
    for(int i=0;i<M;i++){
        ans[i]=0;
        edge[i].clear();
    }
}

void DFS(int u,int it)
{
    if(vis[u]==2 && it==2){
        ans[u]=1;
        return;
    }
    if(vis[u]==1) return;
    if(it==1) vis[u]=2;
    else vis[u]=1;
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if(vis[v]!=1) DFS(v,2);
    }
}

int main()
{
    int n,m,i,a,b,s,d,cnt;
    ///n= number of nodes
    ///m= number of edges
    while(scanf("%d%d",&n,&m)==2){
        init();
        while(m--){
            scanf("%d%d",&a,&b);
            edge[a].push_back(b);
        }
        for(i=1;i<=n;i++){
            memset(vis,0,sizeof(vis));
            DFS(i,1);
        }
        cnt=0;
        for(i=1;i<=n;i++) if(ans[i]==1) {
            printf("%d ",i);
            cnt++;
        }
        if(cnt==0) printf("No such node exists\n");
        printf("\n");
    }
    return 0;
}
/*
6 7
2 1
2 3
1 5
4 1
3 6
6 4
5 4

4 5
3 1
4 3
2 3
1 4
2 1
*/
