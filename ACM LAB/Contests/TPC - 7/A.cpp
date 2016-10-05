#include<bits/stdc++.h>
using namespace std;
#define MAX 20010
#define oo 10000000000
#define lli long long int

lli P,G,t[MAX],Ttaxi,sites[MAX];
lli n,m,taken[17][MAX],par[MAX];
vector<lli>E[MAX],C[MAX];
lli D[17][MAX];

void init()
{
    for(lli i=0;i<MAX;i++){
        E[i].clear();
        C[i].clear();
    }
    for(lli j=0;j<=P;j++){
        for(int i=0;i<=n+5;i++){
            taken[j][i] = 0;
            D[j][i] = oo;
        }
    }
}

struct data{
    lli node;
    lli cost;
    data(lli n,lli w){
        node=n; cost=w;
    }
    bool operator < (const data & p) const{
        return cost > p.cost;
    }
};

void dijkstra(lli srce,lli index)
{
    taken[index][srce]=1;
    priority_queue<data>pq;
    pq.push(data(srce,0));
    D[index][srce]=0;
    while(!pq.empty()){
        data X=pq.top(); pq.pop();
        lli u=X.node;
        lli ucost=X.cost;
        for(lli i=0;i<E[u].size();i++){
            lli v=E[u][i];
            if(ucost+C[u][i]<D[index][v]){
                D[index][v]=ucost+C[u][i];
                pq.push(data(v,D[index][v]));
                taken[index][v]=1;
            }
        }
    }
}

lli Set(lli N,lli pos) {return N | (1ll << pos);}
lli ReSet(lli N,lli pos) {return N & ~(1ll << pos);}
bool Check(lli N,lli pos) {return N & (1ll << pos);}
lli DP[1ll<<16][17],lim;

lli bitmask(lli mask,lli curr_node)
{
    if(mask >= lim) return  D[curr_node][0];
    lli &ret = DP[mask][curr_node],dd;
    if(ret!=-1) return ret;
    ret = oo;
    for(int i=0;i<P;i++){
        if(!Check(mask,i)){
            if(curr_node!=P+1) dd = D[curr_node][sites[i]];
            else dd = D[i][0];
            //cerr<<dd<<endl;
            ret = min(ret,dd + bitmask(Set(mask,i),i));
        }
    }
    //cout<<ret<<endl;
    return ret;
}

lli DP2[1<<16][17][3];

lli bitmask2(lli mask,lli curr_node,lli flag)
{
    if(mask >= lim) {
        if(!flag) return min(Ttaxi,D[curr_node][0]);
        return D[curr_node][0];
    }
    lli &ret = DP2[mask][curr_node][flag],dd;
    if(ret!=-1) return ret;
    ret = oo;
    for(int i=0;i<P;i++){
        if(!Check(mask,i)){
            if(curr_node!=P+1) dd = D[curr_node][sites[i]];
            else dd = D[i][0];
            //cerr<<dd<<endl;
            ret = min(ret,dd + bitmask2(Set(mask,i),i,flag));
            if(!flag) ret = min(ret,Ttaxi + bitmask2(Set(mask,i),i,1));
        }
    }
    return ret;
}

int main()
{
    lli i,j,k,l,a,b,c,time;
    while(scanf("%lld",&n)==1){
        scanf("%lld",&P);
        scanf("%lld",&m);
        scanf("%lld",&G);
        scanf("%lld",&Ttaxi);
        for(i=0;i<P;i++){
            scanf("%lld%lld",&sites[i],&t[i]);
            G-=t[i];
        }
        init();
        while(m--){
            scanf("%lld%lld%lld",&a,&b,&c);
            E[a].push_back(b);
            E[b].push_back(a);
            C[a].push_back(c);
            C[b].push_back(c);
        }
        for(i=0;i<P;i++) dijkstra(sites[i],i);
        lim = (1ll << P) - 1 ;
        //cerr<<"=====>>>> "<<lim<<endl;
        memset(DP,-1,sizeof(DP));
        time = bitmask(0,P+1);
        //cerr<<"----------++>>>   "<<time<<endl;
        if(time <= G) printf("possible without taxi\n");
        else{
            memset(DP2,-1,sizeof(DP2));
            time = bitmask2(0,P+1,0);
            //cerr<<Ttaxi<<endl;
            //cerr<<"---------->>>   "<<time<<endl;
            if(time <= G) printf("possible with taxi\n");
            else printf("impossible\n");
        }
    }
    return 0;
}
