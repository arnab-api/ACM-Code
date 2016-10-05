#include<bits/stdc++.h>
using namespace std;
#define oo 11111
#define M 110

int n,m,cf[M][M],D[M],taken[M],parent[M],ans,srce,dest;

void init()
{
    ans=0;
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++) cf[i][j]=oo;
    }
}

void SPFA(int source,int sink)
{
    for(int i=1;i<=n;i++){
        taken[i]=0;
        D[i]=oo;
        parent[i]=source;
    }
    taken[source]=1;
    D[source]=0;
    queue<int>q;
    q.push(source);
    while(!q.empty()){
        int u=q.front(); q.pop(); taken[u]=0;
        //printf("--->%d\n",u);
        for(int v=1;v<=n;v++){
            if(D[u]+cf[u][v]<D[v]){
                D[v]=D[u]+cf[u][v];
                parent[v]=u;
                if(!taken[v]) {q.push(v); taken[v]=1;}
            }
        }
    }
}

void modify(int v)
{
    if(v==srce) return;
    int u=parent[v];
    cf[u][v]=-cf[u][v];
    cf[v][u]=oo;
    return modify(u);
}

int main()
{
    int i,j,k,l,u,v,w;
    while(scanf("%d",&n)==1){
        if(n==0) break;
        init();
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            cf[u][v]=w;
            cf[v][u]=w;
        }
        srce=1; dest=n;
        SPFA(srce,dest);
        if(D[dest]==oo){
            printf("Back to jail\n");
            continue;
        }
        ans+=D[dest];
        modify(dest);
        srce=n; dest=1;
        SPFA(srce,dest);
        if(D[dest]==oo){
            printf("Back to jail\n");
            continue;
        }
        ans+=D[dest];
        printf("%d\n",ans);
    }
    return 0;
}
