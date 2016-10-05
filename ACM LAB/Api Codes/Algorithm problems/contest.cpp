#include<stdio.h>
#include<vector>
#include<limits.h>
#include<queue>
#include<iostream>
using namespace std;
#define oo INT_MAX
#define M 1010

struct data
{
    int node,cost;
    data(int n,int c)
    {
        node=n;
        cost=c;
    }
    bool operator < (const data & p)const
    {
        return cost > p.cost;
    }
};

vector<int>edge[M],cost[M];
int taken[M],d[M],n,m,x;

int dijkstra(int srce,int dest)
{
    for(int i=0; i<=n; i++)
    {
        d[i]=oo;
        taken[i]=0;
    }
    d[srce]=0;
    taken[srce]=1;
    priority_queue<data>pq;
    pq.push(data(srce,0));
    while(!pq.empty())
    {
        data u=pq.top();
        pq.pop();
        int ucost=d[u.node];
        for(int i=0; i<edge[u.node].size(); i++)
        {
            data v=u;
            v.node=edge[u.node][i];
            v.cost=ucost+cost[u.node][i];
            if(v.cost<d[v.node])
            {
                taken[v.node]=1;
                d[v.node]=v.cost;
                pq.push(v);
            }
        }
    }
    if(!taken[dest]) return -1;
    return d[dest];
}

int main()
{
    int i,j,a,b,c,val;
    while(scanf("%d%d%d",&n,&m,&x)==3){
        for(i=0;i<=n;i++){
            edge[i].clear();
            cost[i].clear();
        }
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            edge[a].push_back(b);
            cost[a].push_back(c);
        }
        int Max=0;
        //while(scanf("%d%d",&a,&b)==2) printf("-->%d\n",dijkstra(a,b));
        for(i=1;i<=n;i++){
           val=dijkstra(i,x)+dijkstra(x,i);
           if(val>Max) Max=val;
        }
        //cout<<"=======>";
        printf("%d\n",Max);
    }
}
