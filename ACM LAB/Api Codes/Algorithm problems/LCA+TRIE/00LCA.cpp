#include<bits/stdc++.h>
using namespace std;
#define M 111

vector<int>G[M],C[M];
int P[M][M],T[M],L[M],n,m;
void init(){
    for(int i=0;i<M;i++){
        G[i].clear();
        T[i]=-1;
    }
}

void DFS(int from,int u,int dep)
{
    T[u]=from;
    L[u]=dep;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==from) continue;
        DFS(u,v,dep+1);
    }
}

void lca_init()
{
    memset(P,-1,sizeof(P));
    int i,j;
    for(i=0;i<n;i++) P[i][0]=T[i];
    for(j=1;(1<<j)<n;j++){
        for(i=0;i<n;i++){
            if(P[i][j-1]!=-1) P[i][j]=P[P[i][j-1]][j-1];
        }
    }
}

int lca_query(int x,int y)
{
    int log,i,j;
    if(L[x]<L[y]) swap(x,y);
    log=1;
    while(1){
        int next=log+1;
        if((1<<next)>L[x]) break;
        log++;
    }
    for(i=log;i>=0;i--){
        if(L[x]-(1<<i)>=L[y]) x=P[x][i];
    }
    if(x==y) return x;
    for(i=log;i>=0;i--){
        if(P[x][i]!=-1 && P[x][i]!=P[y][i]){
            x=P[x][i]; y=P[y][i];
        }
    }
    return T[x];
}

int main()
{
    int i,j,a,b,q,out,c;
    while(scanf("%d%d",&n,&m)==2){
        init();
        while(m--){
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        DFS(0,0,0);
        lca_init();
        printf("--->");
        scanf("%d",&q);
        while(q--){
            scanf("%d%d",&a,&b);
            int x=a;
            while(x!=0) {printf("--> %d ",x); x=T[x];}
            printf("\n");
            x=b;
            while(x!=0) {printf("--> %d ",x); x=T[x];}
            printf("\n");
            out=lca_query(a,b);
            printf("lowest common ancestor of %d & %d is ==> %d\n",a,b,out);
            printf("%d < %d %d\n",L[out],L[a],L[b]);
        }
    }
    return 0;
}
/**
5 4
0 1
0 2
2 3
2 4
1
3 4

9 8
0 1
0 2
2 3
2 4
3 5
3 6
4 7
4 8
3
6 7
3 8
1 8

**/
