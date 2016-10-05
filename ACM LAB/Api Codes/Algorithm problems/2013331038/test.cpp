#include <sstream>
#include <cstdio>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <string.h>
#include <cstring>

using  namespace std ;

#define pb push_back
#define pp pop_back
#define clr(a,b) memset(a,b,sizeof(a))
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define ll long long
#define ull unsigned long long
#define jora_int pait<int,int>
#define jora_ll pair<ll,ll>
#define sz 2000+7
#define fs first
#define sc second
#define sf scanf
#define pf printf
#define mp make_pair
#define ps pf("PASS\n")

template<class T1> void deb(T1 e1)
{
    cout<<e1<<endl ;
}

template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl ;
}

template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<< " " << e3 << endl ;
}

template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<< " " << e3 << " " << e4 << endl ;
}

ll type[300+7] , dis[300+7] ;
int head[sz] , prev[sz] , cap[sz] , flow[sz] , last[300+7] , dist[sz] , nexted[sz] ;
int edges , n , nodes ;

void add_edges(int u,int v,int cp)
{
    head[edges] = v ;
    prev[edges] = last[u] ;
    cap[edges] = cp ;
    flow[edges] = 0 ;
    last[u] = edges++;

    head[edges] = u ;
    prev[edges] = last[v] ;
    cap[edges] = 0 ;
    flow[edges] = 0 ;
    last[v] = edges++;
}

bool bfs(int s,int d)
{
    clr(dist,0);
    queue<int>q ;

    q.push(s);
    dist[s] = 1 ;

    int u , v ;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(int i=last[u] ; i>-1 ; i = prev[i])
        {
            v = head[i] ;

            if(dist[v] == 0 and cap[i]>flow[i])
            {
                dist[v] = dist[u] + 1 ;
                q.push(v);
            }
        }
    }

    return (dist[d] != 0) ;
}

int dfs(int u,int dest,int mn_e)
{
    if(mn_e == 0)
        return 0 ;

    if(u == dest)
        return mn_e ;

    int v , e , ret ;

    for(; nexted[u] != -1 ; nexted[u] = prev[e])
    {
        e = nexted[u] ;
        v = head[e] ;

        if(dist[u]+1 != dist[v])
            continue;

        ret = dfs(v,dest,min(mn_e,cap[e]-flow[e]));

        if(ret > 0)
        {
            flow[e] += ret ;
            flow[e^1] -= ret ;
            return ret ;
        }
    }

    return 0 ;
}

int dinic_update(int s,int d)
{
    int flow = 0 , mned ;

    while(mned = dfs(s,d,10000))
    {
        if(mned == 0)
            break;

        flow += mned ;

        if(flow>=2)
            break;
    }

    return flow ;
}

bool mxflow(int s,int d)
{
    int flow = 0 ;

    while(bfs(s,d))
    {
        for(int i=0 ; i<nodes ; i++)
            nexted[i] = last[i] ;

        flow += dinic_update(s,d);
    }

    return (flow>=2) ;
}

int b_search(int s,int d)
{
    ll l =0  , h  = 1000000000 , mid ;

    while(l<=h)
    {
        mid = (l+h)/2 ;

        if(mxflow(mid))
            h = mid - 1 ;

        else
            l = mid + 1 ;
    }

    pf("%lld\n",l);
}

char str[50] ;

int __ini(int nd)
{
    if(str[0] == 'B')
        type[nd] = 1000000 ;

    else
        type[nd] = 1 ;

    ll num = 0 ;

    int len = strlen(str) ;

    for(int i=2 ; i<len ; i++)
    {
        num = num*10 + (str[i]-'0') ;
    }

    dis[nd] = num ;
}
