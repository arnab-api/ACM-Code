#include<bits/stdc++.h>
using namespace std;
#define M 100500

struct edge{
    int u,v,w;
    edge(int a,int b,int c){
        u=a; v=b; w=c;
    }
    bool operator < (const edge & p)const{
        return w < p.w;
    }
};
vector<edge>E;
vector<int>G[M],C[M];

int par[M],L[M];

struct peerse{
    int n,w;
};

peerse P[M][50],T[M];

int find_set(int u)
{
    if(u==par[u]) return u;
    return par[u]=find_set(par[u]);
}

void MST()
{
    sort(E.begin(),E.end());
    int i,a,b,c,sa,sb;
    for(i=0;i<E.size();i++){
        a=E[i].u;
        b=E[i].v;
        c=E[i].w;
        sa=find_set(a);
        sb=find_set(b);
        //printf("===>%d %d %d --> %d %d\n",a,b,c,sa,sb);
        if(sa!=sb){
            par[sa]=sb;
            G[sa].push_back(sb);
            G[sb].push_back(sa);
            C[sa].push_back(c);
            C[sb].push_back(c);
        }
    }
}

void init()
{
    E.clear();
    for(int i=0;i<M;i++){
        G[i].clear();
        C[i].clear();
        par[i]=i;
        T[i].n=-1;
        T[i].w=-1;
    }
}

void DFS(int from,int u,int dep)
{
    T[u].n=from;
    L[u]=dep;
    if(from==u) T[u].w=0;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==from) {
            if(T[u].w==-1) T[u].w=C[u][i];
            continue;
        }
        DFS(u,v,dep+1);
    }
}

void lca_init(int N)
{
    memset(P,-1,sizeof(P));
    int j,i,m;
    for(i=0;i<M;i++) P[i][0]=T[i];
    for(j=1;(1<<j)<N;j++){
        for(i=0;i<N;i++){
            if(P[i][j-1].n==-1) continue;
            P[i][j].w=max(P[P[i][j-1].n][j-1].w,P[i][j-1].w);
            P[i][j].n=P[P[i][j-1].n][j-1].n;
        }
    }
}

int lca_query(int x,int y)
{
    //printf("====================================== %d %d %d %d\n",x,y,L[x],L[y]);
    if(L[x]<L[y]) swap(x,y);
    int log=0,i,j,next,ret=0;
    while(1){
        next=log+1;
        if((1<<next)>L[x]) break;
        log++;
    }
    for(i=log;i>=0;i--){
        if(L[x]-(1<<i)>=L[y]) {
            ret=max(ret,P[x][i].w);
            x=P[x][i].n;
            //printf("========= %d %d\n",ret,x);
        }
    }
    printf("===>------------------------------%d %d\n",x,y);
    if(x==y) return ret;
    //if(x==y) return x;
    for(i=log;i>=0;i--){
        if(P[x][i].n!=-1 && P[x][i].n!=P[y][i].n){
            ret=max(ret,P[x][i].w);
            ret=max(ret,P[y][i].w);
            //printf("******** %d\n",ret);
            x=P[x][i].n; y=P[y][i].n;
        }
    }
    ret = max(ret,T[x].w);
    ret = max(ret,T[y].w);
    return ret;
    //return T[x].n;
}

int main()
{
    int t,n,m,i,j,q,kase=0,a,b,c;
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d%d",&n,&m);
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            a--; b--;
            E.push_back(edge(a,b,c));
        }
        MST();
        DFS(0,0,0);
        lca_init(n);
        /*for(i=0;i<n;i++){
            printf("%d --> ",i);
            for(j=0;j<G[i].size();j++) printf("%d(%d) ",G[i][j],C[i][j]);
            printf("\n");
        }*/
        //for(i=0;i<n;i++) printf("=>%d(%d)(%d) ",i,T[i].n,T[i].w);
        //printf("\n");
        /*for(i=0;i<n;i++){
            for(j=0;j<n;j++) printf("(%2d,%2d) => (%2d,%2d) || ",i,j,P[i][j].n,P[i][j].w);
            printf("\n");
        }*/
        scanf("%d",&q);
        printf("Case %d:\n",++kase);
        while(q--){
            scanf("%d%d",&a,&b);
            //cerr<<"---------------->";
            printf("%d\n",lca_query(a-1,b-1));
        }
    }
    return 0;
}
/**
2
4 5
1 2 10
1 3 20
1 4 100
2 4 30
3 4 10
2
1 1
4 1
2 1
1 2 100
1
1 2
**/
