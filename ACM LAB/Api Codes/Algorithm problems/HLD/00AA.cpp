//#include<bits/stdc++.h>
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
#define M 10010
#define lli long long int
#define LOG 18

vector<lli>adj[M],Costs[M];

struct sparse
{
    lli data;
    lli node;
    sparse(){}
    sparse(lli n,lli d){
        node = n;
        data = d;
    }
};

/// LCA
lli L[M],n,m;
sparse P[M][20],T[M];
void DFS(lli from,lli u,lli dep)
{
    T[u].node = from;
    L[u] = dep;

    for(lli i=0; i<adj[u].size(); i++)
    {
        lli v = adj[u][i];
        if(v == from) {
            T[u].data = Costs[u][i];
            continue;
        }
        DFS(u,v,dep+1);
    }
}

/// make peerse table
void LCA_init()
{
    memset(P,-1,sizeof(P));
    lli i,j;
    for(i=0; i<n; i++) P[i][0] = T[i];
    for(j=1; (1<<j)<=n; j++)
    {
        for(i=0; i<n; i++)
        {
            if(P[i][j-1].node!=-1) {
                P[i][j].data = P[i][j-1].data + P[P[i][j-1].node][j-1].data;
                P[i][j].node = P[P[i][j-1].node][j-1].node;
            }
        }
    }
}

sparse LCA_query(lli x,lli y)
{
    lli i,j;
    if(L[x]<L[y]) swap(x,y);
    /// determine LOG2(L[x])
    lli sum = 0;
    /// jump to level the level :)
    lli k = L[x] - L[y] ;
    i = 0;
    while(k){
        if(k&1) {
            sum += P[x][i].data;
            x = P[x][i].node;
        }
        i++;
        k>>=1;
    }
    if(x==y) return  sparse(x,sum);


    lli log = 1;
    for(;(1<<log)<L[x];log++);

    /// eksathe jump
    for(i=log; i>=0; i--)
    {
        if(P[x][i].node!=-1 && P[x][i].node!=P[y][i].node)
        {
            sum += P[x][i].data     ;  x=P[x][i].node;
            sum += P[y][i].data     ;  y=P[y][i].node;
        }
    }
    return sparse(T[x].node,sum+T[x].data+T[y].data);
}


lli queryKth(lli u,lli v,lli k)
{
    lli lca = LCA_query(u,v).node;
    lli d1 = L[u] - L[lca] + 1;
    lli d2 = L[v] - L[lca] + 1;
    lli node = u;
    if(k==d1) return  lca;
    if(k>d1){
        k = d1 + d2 - k - 1;
        node = v;
    }
    //cout<<" ===> "<<node<<endl;
    if(node==u) k--;
    lli i = 0;
    while(k){
        if(k&1) node = P[node][i].node;
        i++;
        k>>=1;
    }
    return node;
}

lli queryDist(lli u,lli v)
{
    return LCA_query(u,v).data;
}

void init(lli N)
{
    for(lli i=0; i<N; i++)
    {
        adj[i].clear();
        Costs[i].clear();
    }
    memset(T,-1,sizeof(T));
}

int main()
{
    //freopen("00in.txt","r",stdin);
    lli t,a,b,c,k;
    scanf("%lld",&t);
    char QQ[10];
    while(t--)
    {
        scanf("%lld",&n);
        init(n+5);
        for(lli i=1; i<n; i++)
        {
            scanf("%lld%lld%lld",&a,&b,&c);
            a-- ; b--;
            adj[a].push_back(b);
            Costs[a].push_back(c);

            adj[b].push_back(a);
            Costs[b].push_back(c);
        }
        //cerr<<" === X ===\n";
        DFS(-1,0,0);
        LCA_init();
        //cerr<<" === X ===\n";
        while(scanf(" %s",&QQ)==1){
            if(QQ[0] == 'D' && QQ[1] == 'O') break;
            scanf("%lld%lld",&a,&b);
            if(QQ[0] == 'K') {
                scanf("%lld",&k);
                //cerr<<"--------------> ";
                printf("%lld\n",queryKth(a-1,b-1,k)+1);
            }
            else{
                //cerr<<"--------------> ";
                printf("%lld\n",queryDist(a-1,b-1));
            }
            //cout<<"--->\n";
        }
        //printf("\n");
        //cerr<<"Yeyyyyy\n";
    }
    return 0;
}

/**

10

6
1 2 1
2 4 1
2 5 2
1 3 1
3 6 2
DIST 4 6
KTH 4 6 4
KTH 4 6 3
KTH 4 6 2
DIST 5 3
KTH 5 3 1
KTH 5 3 2
KTH 5 3 3
DIST 1 1
KTH 1 1 1
DONE

*/

