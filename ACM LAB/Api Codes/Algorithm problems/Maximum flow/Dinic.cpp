#include<bits/stdc++.h>
using namespace std;
#define MAXN 110     ///maximum number of nodes
#define MAXE 10100    ///maximum number of edges * 2
#define oo 1<<28

int edge,last[MAXN],next[MAXN];

struct info{
    int to,prev,cap,flow;
};
info Ed[MAXE];

void init(int n)
{
    edge=0;
    memset(last,-1,sizeof(int)*n);
}

void addEdge(int u,int v,int cap,int flow)
{
    Ed[edge].to=v;
    Ed[edge].prev=last[u];
    Ed[edge].cap=cap;
    Ed[edge].flow=flow;
    last[u]=edge++;

    Ed[edge].to=u;
    Ed[edge].prev=last[v];
    Ed[edge].cap=0;
    Ed[edge].flow=0;
    last[v]=edge++;
}

int level[MAXN];
queue<int>q;

bool DinicBFS(int S,int E,int N)
{
    memset(level,0,sizeof(int)*N);
    level[S]=1;
    while(!q.empty()) q.pop();
    q.push(S);
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int i=last[u];i>-1;i=Ed[i].prev){
            int v=Ed[i].to;
            if(!level[v] && Ed[i].cap>Ed[i].flow){
                level[v]=level[u]+1;
                q.push(v);
                if(v==E) return true;
            }
        }
    }
    return (level[E]!=0);
}

int DinicDFS(int from,int minedge,int E)
{
    if(from==E) return minedge;
    if(minedge==0) return 0;
    int e;
    for(;next[from]>=0;next[from]=Ed[e].prev){
        e=next[from];
        if(level[Ed[e].to]!=level[from]+1) continue;
        int ret=DinicDFS(Ed[e].to,min(minedge,Ed[e].cap-Ed[e].flow),E);
        if(ret){
            Ed[e].flow+=ret;
            Ed[e^1].flow-=ret;
            return ret;
        }
    }
    return 0;
}

int DinicUpdate(int S,int E)
{
    int flow=0,minedge;
    while(minedge=DinicDFS(S,oo,E)){
        if(minedge==0) break;
        flow+=minedge;
    }
    return flow;
}

int MaxFlow(int source,int sink,int n)
{
    int totflow=0;
    while(DinicBFS(source,sink,n)){
        //cout<<totflow<<endl;
        for(int i=0;i<=n;i++) next[i]=last[i]; /// update last edge of ith node
        totflow+=DinicUpdate(source,sink);
    }
    return totflow;
}

int main()
{
    int t,n,srce,sink,a,b,c,conn,ans,kase=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        init(n+5);
        scanf("%d%d%d",&srce,&sink,&conn);
        while(conn--){
            scanf("%d%d%d",&a,&b,&c);
            addEdge(a,b,c,0);
            addEdge(b,a,c,0);
        }
        //cout<<"--------------->";
        ans=MaxFlow(srce,sink,n+5);
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}

