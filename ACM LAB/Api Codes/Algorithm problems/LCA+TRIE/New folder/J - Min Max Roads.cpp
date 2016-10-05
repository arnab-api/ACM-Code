#include<bits/stdc++.h>
using namespace std;
#define M 100100

struct peerse{
    int n,sw,lw;
};
peerse T[M],P[M][22];
vector<int>G[M],C[M];
int L[M];
void init()
{
    memset(T,-1,sizeof(T));
    for(int i=0;i<M;i++){
        G[i].clear();
        C[i].clear();
        L[i]=-1;
    }
}

void DFS(int from,int u,int dep)
{
    T[u].n=from;
    L[u]=dep;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==from){
            if(T[u].sw!=-1) continue;
            T[u].sw=C[u][i];
            T[u].lw=C[u][i];
            continue;
        }
        DFS(u,v,dep+1);
    }
}

void LCA_init(int N)
{
    memset(P,-1,sizeof(P));
    for(int i=0;i<22;i++) T[0].sw=INT_MAX;
    int i,j;
    for(i=0;i<N;i++) P[i][0]=T[i];
    for(j=1;(1<<j)<N;j++){
        for(i=0;i<N;i++){
            if(P[i][j-1].n==-1) continue;
            P[i][j].lw=max(P[P[i][j-1].n][j-1].lw,P[i][j-1].lw);
            P[i][j].sw=min(P[P[i][j-1].n][j-1].sw,P[i][j-1].sw);
            P[i][j].n=P[P[i][j-1].n][j-1].n;
        }
    }
}

int mini,maxi;

void LCA_query(int N,int x,int y)
{
    int i,j,log,next;
    if(L[x]<L[y]) swap(x,y);
    log=1;
    while(1){
        next=log+1;
        if((1<<next)>L[x]) break;
        log++;
    }
    for(i=log;i>=0;i--){
        if(L[x]-(1<<i)>=L[y]){
            mini=min(mini,P[x][i].sw);
            maxi=max(maxi,P[x][i].lw);
            x=P[x][i].n;
        }
    }
    if(x==y) return;
    for(i=log;i>=0;i--){
        if(P[x][i].n==-1 || P[x][i].n==P[y][i].n) continue;
        mini=min(mini,P[x][i].sw);
        mini=min(mini,P[y][i].sw);

        maxi=max(maxi,P[x][i].lw);
        maxi=max(maxi,P[y][i].lw);

        x=P[x][i].n;
        y=P[y][i].n;
    }
    mini=min(mini,T[x].sw);
    mini=min(mini,T[y].sw);

    maxi=max(maxi,T[x].lw);
    maxi=max(maxi,T[y].lw);

    return;
}

int main()
{
    //freopen("B.txt","w",stdout);
    int q,t,n,m,i,j,a,b,c,kase=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        m=n-1;
        init();
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            a--;b--;
            G[a].push_back(b);
            G[b].push_back(a);
            C[a].push_back(c);
            C[b].push_back(c);
        }
        DFS(0,0,0);
        LCA_init(n);
        /*for(i=0;i<n;i++){
            printf("%d(%d) -->",i,L[i]);
            for(j=0;j<4;j++) printf(" %4d(%4d%4d)",P[i][j].n,P[i][j].sw,P[i][j].lw);
            printf("\n");
        }*/
        printf("Case %d:\n",++kase);
        scanf("%d",&q);
        while(q--){
            scanf("%d%d",&a,&b);
            a--;b--;
            if(a==b) {mini=0; maxi=0;}
            else{
                mini=INT_MAX;
                maxi=-INT_MAX;
                LCA_query(n,a,b);
            }
            //cerr<<"----------------->";
            printf("%d %d\n",mini,maxi);
        }
    }
    return 0;
}
