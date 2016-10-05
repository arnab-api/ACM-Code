/// kosaraju's algorithm for scc

#include<bits/stdc++.h>
using namespace std;
#define M 100100

int n,m,vis[M],taken[M];
vector<int>conn[M],topsort,va,vb;
void init()
{
    for(int i=0;i<=n;i++) {
        conn[i].clear();
    //topsort.clear();
        taken[i]=0;
    }
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
    topsort.clear();
    for(int i=0;i<n;i++) if(!vis[i]) DFS(i);
    clr_vis();
    int cnt=0;
    for(int i=0;i<topsort.size();i++) printf("%d ",topsort[i]);
    printf("\n");
    init();
    for(int i=0;i<va.size();i++) conn[vb[i]].push_back(va[i]);
    for(int i=topsort.size()-1;i>=0;i--){
        if(!vis[topsort[i]]){
            cnt++;
            DFS(topsort[i]);
            cout<<"(";
            for(int j=0;j<n;j++) if(vis[j]==1 && !taken[j]){
                taken[j]=1;
                cout<<j<<" ";
            }
            cout<<")\n";
        }
    }
    //for(int i=0;i<topsort.size();i++) printf("%d ",topsort[i]);
    printf("\n");
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
            va.push_back(a);
            vb.push_back(b);
            conn[a].push_back(b);
        }
        printf("\n==>%d\n",kosaraju(n));
    }
    return 0;
}
/*
5 5
1 0
2 1
0 2
0 3
3 4
*/

