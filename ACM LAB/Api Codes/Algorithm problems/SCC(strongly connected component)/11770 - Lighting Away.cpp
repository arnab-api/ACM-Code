#include<bits/stdc++.h>
using namespace std;
#define M 10100

int n,m,vis[M];
vector<int>edge[M],topsort;

void init(int n)
{
    topsort.clear();
    for(int i=0;i<=n;i++) {
        edge[i].clear();
        vis[i]=0;
    }
}

void DFS(int p)
{
    if(vis[p]==1) return;
    vis[p]=1;
    for(int i=0;i<edge[p].size();i++) if(!vis[edge[p][i]]) DFS(edge[p][i]);
    topsort.push_back(p);
}

int kosaraju()
{
    int i,l,cnt=0;
    for(i=1;i<=n;i++) if(!vis[i]) DFS(i);
    l=topsort.size();
    for(i=1;i<=n;i++) vis[i]=0;
    //for(i=0;i<l;i++) printf("%d ",topsort[i]);
    //printf("\n");
    for(i=l-1;i>=0;i--) if(!vis[topsort[i]]) {
        DFS(topsort[i]);
        cnt++;
    }
    return cnt;
}

int main()
{
    int t,i,j,a,b,ans,kase=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        init(n);
        for(i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            edge[a].push_back(b);
        }
        ans=kosaraju();
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}
