#include<bits/stdc++.h>
using namespace std;
#define M 50050
#define lli long long int

struct peerse
{
    int n,w;
};
peerse P[M][22],T[M];
int lev[M];
vector<lli>E[M],C[M],out;

void init(int N)
{
    out.clear();
    memset(T,-1,sizeof(T));
    for(int i=0;i<=N;i++){
        E[i].clear();
        C[i].clear();
        lev[i]=-1;
    }
}

void DFS(int from,int u,int dep)
{
    //cout<<"--->"<<endl;
    T[u].n=from;
    lev[u]=dep;
    if(from==u) T[u].w=0;
    for(int i=0;i<E[u].size();i++){
        int v=E[u][i];
        if(v==from){
            if(T[u].w==-1) T[u].w=C[u][i];
            continue;
        }
        DFS(u,v,dep+1);
    }
}

void LCA_init(int N)
{
    //cout<<"called\n";
    memset(P,-1,sizeof(P));
    int i,j;
    for(i=0;i<N;i++) P[i][0]=T[i];
    for(j=1;(1<<j)<N;j++){
        for(i=0;i<N;i++){
            if(P[i][j-1].n==-1) continue;
            P[i][j].w=P[i][j-1].w + P[P[i][j-1].n][j-1].w;
            P[i][j].n=P[P[i][j-1].n][j-1].n;
        }
    }
}

struct jora{
    int lca,sum;
};

int lca;

int LCA_query(int N,int x,int y)
{
    if(lev[x]<lev[y]) swap(x,y);
    int log=0,i,j,next,sum=0;
    jora J;
    while(1){
        next=log+1;
        if((1<<next)>lev[x]) break;
        log++;
    }
    for(i=log;i>=0;i--){
        if(lev[x]-(1<<i)>=lev[y]) {
            sum+=P[x][i].w;
            x=P[x][i].n;
        }
    }
    //printf("--->%lld %lld %lld %lld %lld %lld\n",log,x,y,sum,lev[x],lev[y]);
    if(x==y) {
        lca=x;
        return sum;
    }
    for(i=log;i>=0;i--){
        if(P[x][i].n==-1 || P[x][i].n==P[y][i].n) continue;
        sum+=P[x][i].w;
        sum+=P[y][i].w;
        x=P[x][i].n;
        y=P[y][i].n;
    }
    //printf("--->%lld %lld %lld\n",sum,x,y);
    sum+=T[x].w;
    sum+=T[y].w;
    lca=T[x].n;
    return sum;
}

int main()
{
    int n,m,a,b,c,q,ans,i,j,x,y,z;
    bool frst=true;
    while(scanf("%d",&n)==1){
        if(n==0) break;
        init(n);
        m=n-1;
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            E[a].push_back(b);
            E[b].push_back(a);
            C[a].push_back(c);
            C[b].push_back(c);
        }
        /*for(i=0;i<n;i++){
            printf("%lld--->",i);
            for(j=0;j<E[i].size();j++) printf(" %lld(%lld)",E[i][j],C[i][j]);
            printf("\n");
        }*/
        DFS(0,0,0);
        LCA_init(n);
        /*for(i=0;i<n;i++){
            printf("%3lld-->",i);
            for(j=0;j<4;j++) printf(" %3lld(%3lld)",P[i][j].n,P[i][j].w);
            printf("\n");
        }*/
        if(frst) frst=false;
        else printf("\n");
        scanf("%d",&q);
        while(q--){
            scanf("%d%d%d",&a,&b,&c);
            x=LCA_query(n,a,b);
            x+=LCA_query(n,lca,c);
            y=LCA_query(n,b,c);
            y+=LCA_query(n,lca,a);
            z=LCA_query(n,a,c);
            z+=LCA_query(n,lca,b);
            //printf("---> %d %d %d\n",x,y,z);
            ans=min(x,y);
            ans=min(ans,z);
            //cout<<"------------------>";
            printf("%d\n",ans);
        }
    }
    return 0;
}

