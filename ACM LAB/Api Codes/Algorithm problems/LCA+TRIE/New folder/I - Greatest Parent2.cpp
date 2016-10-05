#include<bits/stdc++.h>
using namespace std;
#define M 100100

vector<int>G[M];
int val[M],L[M];

struct peerse{
    int n,w;
};

peerse T[M],P[M][25];

void init()
{
    for(int i=0;i<M;i++){
        G[i].clear();
        L[i]=-1;
    }
}

void DFS(int from,int u,int dep)
{
    T[u].n=from;
    T[u].w=val[from];
    L[u]=dep;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==from) continue;
        DFS(u,v,dep+1);
    }
}

void LCA_init(int N)
{
    memset(P,-1,sizeof(P));
    int i,j;
    for(i=0;i<N;i++) P[i][0]=T[i];
    for(j=1;(1<<j)<N;j++){
        for(i=0;i<N;i++){
            if(P[i][j-1].n==-1) continue;
            P[i][j].n=P[P[i][j-1].n][j-1].n;
            P[i][j].w=val[P[i][j].n];
        }
    }
}

int LCA_query(int N,int k,int v)
{
    //printf("===>%d %d\n",k,L[k]);
    int log=1,next,i;
    while(1){
        next=log+1;
        if((1<<next)>L[k]) break;
        log++;
    }
    for(i=log;i>=0;i--){
        //printf("--->%d(%d) %d %d\n",k,log,P[k][i].n,P[k][i].w);
        if(P[k][i].w>=v) k=P[k][i].n;
    }
    return k;
}

int main()
{
    int i,j,t,n,q,a,b,kase=0,node,v,ans;
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d%d",&n,&q);
        val[0]=1;
        for(i=1;i<=n-1;i++){
            //printf("%d --> ",i);
            scanf("%d%d",&a,&b);
            G[a].push_back(i);
            G[i].push_back(a);
            val[i]=b;
        }
        DFS(0,0,0);
        LCA_init(n);
        /*for(i=0;i<n;i++){
            printf("%2d (%5d) --> ",i,val[i]);
            for(j=0;j<7;j++) printf(" %5d(%5d)",P[i][j].n,P[i][j].w);
            printf("\n");
        }*/
        printf("Case %d:\n",++kase);
        while(q--){
            scanf("%d%d",&a,&b);
            ans=LCA_query(n,a,b);
            //cerr<<"----------->";
            printf("%d\n",ans);
        }
    }
    return 0;
}
