#include<bits/stdc++.h>
using namespace std;
#define M 1111

int vis[M],ans[M];
vector<int>edge[M];

void init()
{
    for(int i=0;i<M;i++){
        vis[i]=0;
        edge[i].clear();
    }
}

void DFS(int x)
{
     stack<int>stk;
     stk.push(x);
     vis[x]=1;
     while(!stk.empty()){
        int u=stk.top(); stk.pop();
        for(int i=0;i<edge[u].size();i++){
            int v=edge[u][i];
            if(!vis[v]){
                vis[v]=1;
                stk.push(v);
            }
        }
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
            edge[b].push_back(a);
        }
        cnt=0;
        for(i=1;i<=n;i++) {
            if(!vis[i]) {
                DFS(i);
                cnt++;
            }
        }
        printf("-->%d\n",cnt);
    }
    return 0;
}
/*
8 5
2 3
3 4
6 5
5 7
7 8
*/
