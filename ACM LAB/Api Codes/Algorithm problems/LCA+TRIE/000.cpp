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

/*int main()
{
    int i,j,a,b,q,out,c;
    string dit;
    while(scanf("%d%d",&n,&m)==2){
        init();
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            G[a].push_back(b);
            G[b].push_back(a);
            C[a].push_back(c);
            C[b].push_back(c);
        }
        DFS(0,0,0);
        lca_init();
        printf("--->");
        //cin>>dit;
        while(cin>>dit){
            if(dit=="DONE") {
                cout<<"---XXX---\n";
                break;
            }
            else{
                scanf("%d%d",&a,&b);
                int lca=lca_query(a,b);
                printf("%d %d ---> %d\n",a,b,lca);
            }
        }
    }
    return 0;
}*/

int main()
{
    int n,m,i,j,a,b,c,lca;
    string dit;
    while(scanf("%d",&n)==1){
        m=n-1;
        init();
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            //a--;
            //b--;
            G[a].push_back(b);
            G[b].push_back(a);
            C[a].push_back(c);
            C[b].push_back(c);
        }
        DFS(0,0,0);
        lca_init();
        getchar();
        //cout<<"======"<<a<<b<<endl;
        cin>>dit;
        while(cin>>dit){
            if(dit=="DONE") {
                cout<<"---XXX---\n";
                break;
            }
            else{
                scanf("%d%d",&a,&b);
                lca=lca_query(a,b);
                printf("%d %d ---> %d\n",a,b,lca);
            }
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
0 1 1
0 2 1
2 3 1
2 4 1
3 5 1
3 6 1
4 7 1
4 8 1
api 6 7
api 3 8
api 1 8
DONE
**/
