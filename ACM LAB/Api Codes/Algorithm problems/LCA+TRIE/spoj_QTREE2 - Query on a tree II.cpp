#include<bits/stdc++.h>
using namespace std;
#define M 10100
#define oo 1<<30

vector<int>G[M],C[M];
int P[M][30],T[M],L[M];

void init()
{
    for(int i=0;i<M;i++){
        G[i].clear();
        C[i].clear();
    }
}

void DFS(int from,int u,int dep)
{
    //cout<<"---->";
    T[u]=from;
    L[u]=dep;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==from) continue;
        DFS(u,v,dep+1);
    }
}

void lca_init(int N)
{
    //cout<<"+++++"<<N<<endl;
    int i,j;
    memset(P,-1,sizeof(P));
    for(i=0;i<N;i++) P[i][0]=T[i];
    for(j=1;(1<<j)<N;j++){
        for(i=0;i<N;i++){
            if(P[i][j-1]==-1) continue;
            P[i][j]=P[P[i][j-1]][j-1];
        }
    }
    //cout<<"===>";
}

int lca_query(int n,int x,int y)
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
        if(L[x]-(1<<i)>=L[y]) x=P[x][i];
    }
    if(x==y) return y;
    for(i=log;i>=0;i--){
        if(P[x][i]!=-1 && P[x][i]!=P[y][i]){
            x=P[x][i]; y=P[y][i];
        }
    }
    return T[x];
}

int D[M];

struct info{
    int node,cost;
    info(int n,int c){
        node=n; cost=c;
    }
    bool operator < (const info & p)const{
        return cost > p.cost;
    }
};

void Dijkstra(int srce)
{
    for(int i=0;i<M;i++) D[i]=oo;
    D[srce]=0;
    priority_queue<info>pq;
    pq.push(info(srce,0));
    while(!pq.empty()){
        int u=pq.top().node;
        int ucost=pq.top().cost;
        pq.pop();
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(ucost+C[u][i]<D[v]){
                D[v]=ucost+C[u][i];
                pq.push(info(v,D[v]));
            }
        }
    }
}

int main()
{
    int n,m,i,j,a,b,c,lca,k,llv,node,cnt,ans,t;
    scanf("%d",&t);
    string dit;
    while(t--){
        scanf("%d",&n);
        m=n-1;
        init();
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            a--;
            b--;
            G[a].push_back(b);
            G[b].push_back(a);
            C[a].push_back(c);
            C[b].push_back(c);
        }
        Dijkstra(0);
        //for(i=0;i<n;i++) printf("%d(%d) ",i,D[i]);
        //printf("\n");
        DFS(0,0,0);
        lca_init(n);
        while(cin>>dit){
            if(dit=="DONE") {
                //cout<<"---XXX---\n";
                printf("\n");
                break;
            }
            else{
                if(dit=="DIST"){
                    scanf("%d%d",&a,&b);
                    lca=lca_query(n,a-1,b-1);
                    //printf("%d(%d) %d(%d) ---> %d(%d)\n",a,D[a-1],b,D[b-1],lca+1,D[lca]);
                    //cerr<<"---------->";
                    printf("%d\n",D[a-1]+D[b-1]-2*D[lca]);
                }
                else{
                    scanf("%d%d%d",&a,&b,&k);
                    a--; b--;
                    lca=lca_query(n,a,b);
                    llv=L[a]-L[lca]+1;
                    //cerr<<"===============>";
                    if(k==llv) ans=lca;
                    else if(k<llv){
                        node=a;
                        cnt=1;
                        while(1){
                            if(cnt==k) break;
                            node=T[node];
                            cnt++;
                        }
                        ans=node;
                    }
                    else{
                        k=L[a]-L[lca]+L[b]-L[lca]+1-k+1;
                        node=b;
                        cnt=1;
                        while(1){
                            if(cnt==k) break;
                            node=T[node];
                            cnt++;
                        }
                        ans=node;
                    }
                    printf("%d\n",ans+1);
                }
            }
        }
    }
    return 0;
}
/**
10
1 2 1
1 3 1
3 4 1
3 5 1
4 6 1
4 7 1
5 8 1
5 9 1
9 10 1
DIST 6 10
DIST 7 5
DIST 2 5
DONE

9
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
**/
