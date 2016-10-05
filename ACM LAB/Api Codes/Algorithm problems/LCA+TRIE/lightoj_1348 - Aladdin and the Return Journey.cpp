#include<bits/stdc++.h>
using namespace std;
#define M 30030

vector<int>E[M];
int ara[M],L[M];

void init(int N)
{
    for(int i=0;i<N;i++){
        E[i].clear();
        L[i]=-1;
    }
}

struct peerse{
    int node,cost;
};

peerse T[M],P[M][30];

void DFS(int from,int u,int dep)
{
    T[u].node=from;
    L[u]=dep;
    for(int i=0;i<E[u].size();i++){
        int v=E[u][i];
        if(v==from){
            T[u].cost=ara[u];
            continue;
        }
        DFS(u,v,dep+1);
    }
}

void LCA_init(int N)
{
    int i,j;
    memset(P,-1,sizeof(P));
    for(i=0;i<N;i++) P[i][0]=T[i];
    for(j=1;(1<<j)<N;j++){
        for(i=0;i<N;i++){
            if(P[i][j-1].node==-1) continue;
            P[i][j].cost=P[i][j-1].cost+P[P[i][j-1].node][j-1].cost;
            P[i][j].node=P[P[i][j-1].node][j-1].node;
        }
    }
}

void update(int N,int u,int w)
{
    int i,j,log=1,next;
    while(1){
        next=log+1;
        if((1<<next)>L[u]) break;
        log++;
    }
    P[u][0].cost=w;
    for(i=1;i<log;i++){
        if(P[u][i-1].node==-1) continue;
        P[u][i].cost=P[u][i-1].cost+P[P[u][i-1].node][i-1].cost;
    }
    ara[u]=w;
    //DFS(0,0,0);
    //LCA_init(N);
}

int sum;

int LCA_query(int N,int x,int y)
{
    if(L[x]<L[y]) swap(x,y);
    int i,j,log=1,next;
    while(1){
        next=log+1;
        if((1<<next)>L[x]) break;
        log++;
    }
    sum=0;
    for(i=log;i>=0;i--){
        if(L[x]-(1<<i)>=L[y]){
            sum+=P[x][i].cost;
            x=P[x][i].node;
        }
    }
    if(x==y) return x;
    for(i=log;i>=0;i--){
        if(P[x][i].node==-1 || P[x][i].node==P[y][i].node) continue;
        sum+=P[x][i].cost;
        sum+=P[y][i].cost;
        x=P[x][i].node;
        y=P[y][i].node;
    }
    sum+=T[x].cost;
    sum+=T[y].cost;
    return T[x].node;
}

int main()
{
    int t,kase=0,i,n,m,a,b,q,lca,dit,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        init(n);
        for(i=0;i<n;i++) scanf("%d",&ara[i]);
        m=n-1;
        while(m--){
            scanf("%d%d",&a,&b);
            E[a].push_back(b);
            E[b].push_back(a);
        }

        DFS(0,0,0);
        LCA_init(n);
        /*for(i=0;i<n;i++) printf(" %d(%d)",i,ara[i]);
        printf("\n");

        for(i=0;i<n;i++){
            printf("%d ---> ",i);
            for(j=0;j<4;j++) printf(" %3d(%3d)",P[i][j].node,P[i][j].cost);
            printf("\n");
        }*/
        printf("Case %d:\n",++kase);
        scanf("%d",&q);
        while(q--){
            scanf("%d%d%d",&dit,&a,&b);
            if(dit==0){
                lca=LCA_query(n,a,b);
                sum=sum+ara[lca];
                //cerr<<lca<<" --------------------->";
                printf("%d\n",sum);
            }
            else{
                update(n,a,b);
                /*for(i=0;i<n;i++){
                    printf("%d ---> ",i);
                    for(j=0;j<4;j++) printf(" %3d(%3d)",P[i][j].node,P[i][j].cost);
                    printf("\n");
                }*/
            }
        }
    }
    return 0;
}
