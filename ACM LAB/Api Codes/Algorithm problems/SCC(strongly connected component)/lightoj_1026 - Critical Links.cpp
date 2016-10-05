#include<bits/stdc++.h>
using namespace std;
#define M 10100

int low[M],dfn[M],parent[M],depth;
vector<int>G[M];

struct data{
    int u,v;
    bool operator < (const data & p)const{
        if(u==p.u) return v < p.v;
        return u < p.u;
    }
};

vector<data>ans;

void init()
{
    for(int i=0;i<M;i++){
        G[i].clear();
        dfn[i]=-1;
        low[i]=-1;
        parent[i]=-1;
    }
    depth=0;
    ans.clear();
}

void tarjan(int u)
{
    low[u]=dfn[u]=depth++;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(dfn[v]==-1){
            parent[v]=u;
            tarjan(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]) {
                ///printf("Bridge ==> %d --- %d\n",u,v);
                data A;
                A.u=u;
                A.v=v;
                if(A.u>A.v) swap(A.u,A.v);
                ans.push_back(A);
            }
        }
        else if(v!=parent[u]) low[u]=min(low[u],dfn[v]);
    }
}

int main()
{
    int n,m,i,j,a,b,t,kase=0;
    char ch;
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a);
            scanf(" %c",&ch);
            scanf("%d",&m);
            scanf(" %c",&ch);
            for(j=0;j<m;j++){
                scanf("%d",&b);
                G[a].push_back(b);
                G[b].push_back(a);
            }
        }
        for(i=0;i<n;i++) if(dfn[i]==-1) tarjan(i);
        sort(ans.begin(),ans.end());
        printf("Case %d:\n",++kase);
        printf("%d critical links\n",ans.size());
        for(i=0;i<ans.size();i++) printf("%d - %d\n",ans[i].u,ans[i].v);
    }
    return 0;
}
/*
3

8
0 (1) 1
1 (3) 2 0 3
2 (2) 1 3
3 (3) 1 2 4
4 (1) 3
7 (1) 6
6 (1) 7
5 (0)

0

2
0 (1) 1
1 (1) 0
*/
