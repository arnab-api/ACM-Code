/// kosaraju's algorithm for scc

#include<bits/stdc++.h>
using namespace std;
#define M 100100

int n,m,vis[M];
vector<int>conn[M],topsort;
void init()
{
    for(int i=0;i<=n;i++) conn[i].clear();
    topsort.clear();
}

void clr_vis()
{
    for(int i=0;i<=n;i++) vis[i]=0;
}

void DFS(int x)
{
    if(vis[x]==1) return;
    vis[x]=1;
    for(int i=0;i<conn[x].size();i++){
        int n=conn[x][i];
        if(!vis[n]) DFS(n);
    }
    topsort.push_back(x);
}

int kosaraju(int n)
{
    for(int i=1;i<=n;i++) if(!vis[i]) DFS(i);
    clr_vis();
    int cnt=0;
    for(int i=topsort.size()-1;i>=0;i--){
        //printf("%d ",topsort[i]);
        if(!vis[topsort[i]]){
            cnt++;
            DFS(topsort[i]);
        }
    }
    return cnt;
}

int main()
{
    int i,j,a,b,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        init();
        clr_vis();
        while(m--){
            scanf("%d%d",&a,&b);
            conn[a].push_back(b);
        }
        printf("%d\n",kosaraju(n));
    }
    return 0;
}
