#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <queue>
#define INF 111111
#define N 220
using namespace std;
int g[N][N],d[N],path[N],vis[N],n,m,s,t;
int sum;

void spfa()
{
    queue <int> q;
    for(int i=1; i<=n; i++)
    {d[i]=INF; vis[i]=0; path[i]=s;}
    d[s]=0; q.push(s); vis[s]=1;
    while(!q.empty())
    {
        int u;
        u=q.front(); q.pop(); vis[u]=0;
        for(int v=1; v<=n; v++)
            if(d[u]+g[u][v]<d[v])
            {
                d[v]=d[u]+g[u][v];
                path[v]=u;
                if(!vis[v])
                {  q.push(v); vis[v]=1;  }
            }
    }
    return ;
}
void change(int v)
{
    int u=path[v];
    //printf("===>%d %d\n",u,v);
    g[u][v]*=-1;
    g[v][u]=INF;
    if(u==s) return ;
    change(u);
}
int main()
{
    //printf("%d\n",INF);
    while(scanf("%d",&n)!=EOF && n)
    {
        scanf("%d",&m);
        memset(g,INF,sizeof(g));
        for(int i=1; i<=m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            g[u][v]=g[v][u]=w;
        }
        s=1; t=n;
        spfa();
        sum=d[t];
        //cout<<"------------------------------->";
        if(d[t]==INF)
        {
            printf("Back to jail\n");
            continue;
        }
        change(t);
        s=n; t=1;
        spfa();
        if(d[t]==INF)
            printf("Back to jail\n");
        else
            printf("%d\n",sum+d[t]);
    }
    return 0;
}
