#include<cstdio>
#include<cmath>
#include<cctype>
#include<climits>
#include<cstring>
#include<cstdlib>

#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>

#include<vector>
#include<map>
#include<string>
#include<queue>
#include<set>
#include<iterator>
#include<numeric>
#include<stack>
#include<list>
using namespace std;
#define M 100100
#define lli long long int

struct peerse
{
    lli n,w;
};
peerse P[M][22],T[M];
lli lev[M];
vector<lli>E[M],C[M],out;

void init(lli N)
{
    out.clear();
    memset(T,-1,sizeof(T));
    for(lli i=0;i<=N;i++){
        E[i].clear();
        C[i].clear();
        lev[i]=-1;
    }
}

void DFS(lli from,lli u,lli dep)
{
    //cout<<"--->"<<endl;
    T[u].n=from;
    lev[u]=dep;
    if(from==u) T[u].w=0;
    for(lli i=0;i<E[u].size();i++){
        lli v=E[u][i];
        if(v==from){
            if(T[u].w==-1) T[u].w=C[u][i];
            continue;
        }
        DFS(u,v,dep+1);
    }
}

void LCA_init(lli N)
{
    //cout<<"called\n";
    memset(P,-1,sizeof(P));
    lli i,j;
    for(i=0;i<N;i++) P[i][0]=T[i];
    for(j=1;(1<<j)<N;j++){
        for(i=0;i<N;i++){
            if(P[i][j-1].n==-1) continue;
            P[i][j].w=P[i][j-1].w + P[P[i][j-1].n][j-1].w;
            P[i][j].n=P[P[i][j-1].n][j-1].n;
        }
    }
}

lli LCA_query(lli N,lli x,lli y)
{
    if(lev[x]<lev[y]) swap(x,y);
    lli log=0,i,j,next,sum=0;
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
    if(x==y) return sum;
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
    return sum;
}

int main()
{
    lli n,m,a,b,c,q,ans,i,j;
    while(scanf("%lld",&n)==1){
        if(n==0) break;
        init(n);
        for(a=1;a<=n-1;a++){
            scanf("%lld%lld",&b,&c);
            //printf("--->%lld %lld %lld\n",a,b,c);
            E[b].push_back(a);
            E[a].push_back(b);
            C[b].push_back(c);
            C[a].push_back(c);
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
        scanf("%lld",&q);
        while(q--){
            scanf("%lld%lld",&a,&b);
            ans=LCA_query(n,a,b);
            out.push_back(ans);
            //cout<<"------------------>";
            //printf("%lld\n",ans);
        }
        for(i=0;i<out.size()-1;i++) printf("%lld ",out[i]);
        printf("%lld\n",out[out.size()-1]);
    }
    return 0;
}
