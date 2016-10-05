#include<bits/stdc++.h>
using namespace std;
#define MX 10010
#define oo 1<<28

int n,m,s,t,p;
struct edge{
    int u,v,w;
    edge(){}
    edge(int a,int b,int c){
        u=a; v=b; w=c;
    }
};
vector<edge>E;

struct data{
    int to,cost;
    data(){}
    data(int a,int c){
        to=a;
        cost=c;
    }
    bool operator < (const data & p)const{
        return cost > p.cost;
    }
};
vector<data>G[MX],R[MX];
int stox[MX],ttox[MX];

void init(int N)
{
    E.clear();
    for(int i=0;i<N;i++){
        G[i].clear();
        R[i].clear();
        stox[i]=oo;
        ttox[i]=oo;
    }
}

void Dijkstra(int srce)
{
    priority_queue<data>pq;
    stox[srce]=0;
    pq.push(data(srce,0));
    while(!pq.empty()){
        data U=pq.top(); pq.pop();
        int u=U.to;
        int ucost=U.cost;
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i].to;
            int vcost=G[u][i].cost+ucost;
            if(vcost<stox[v]){
                pq.push(data(v,vcost));
                stox[v]=vcost;
            }
        }
    }
}

void Rev_Dijkstra(int srce)
{
    priority_queue<data>pq;
    ttox[srce]=0;
    pq.push(data(srce,0));
    while(!pq.empty()){
        data U=pq.top(); pq.pop();
        int u=U.to;
        int ucost=U.cost;
        for(int i=0;i<R[u].size();i++){
            int v=R[u][i].to;
            int vcost=R[u][i].cost+ucost;
            if(vcost<ttox[v]){
                pq.push(data(v,vcost));
                ttox[v]=vcost;
            }
        }
    }
}

int main()
{
    int test,kase=0,i,j,k,l,a,b,c,mx,u,v,w;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        scanf("%d",&m);
        scanf("%d",&s);
        scanf("%d",&t);
        scanf("%d",&p);
        init(n);
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            a--;b--;
            E.push_back(edge(a,b,c));
            G[a].push_back(data(b,c));
            R[b].push_back(data(a,c));
        }
        s--;t--;
        Dijkstra(s);
        Rev_Dijkstra(t);
        mx=-1;
        //for(i=0;i<n;i++) printf("%d(%d) ",i+1,stox[i]);
        //printf("\n");
        //for(i=0;i<n;i++) printf("%d(%d) ",i+1,ttox[i]);
        //printf("\n");
        for(i=0;i<E.size();i++){
            u=E[i].u;
            v=E[i].v;
            w=E[i].w;
            if(stox[u]+ttox[v]+w<=p) mx=max(mx,w);
            //if(stox[v]+ttox[u]+w<=p) mx=max(mx,w);
        }
        //cerr<<test<<"------------------->";
        printf("Case %d: %d\n",++kase,mx);
    }
    return 0;
}
