#include<bits/stdc++.h>
using namespace std;
#define M 1010
#define oo INT_MAX;

int cost[M][M],dist[M][M],taken[M][M],n,m;
int fx[]={1,0,-1,0};
int fy[]={0,1,0,-1};

void init()
{
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++) {
            dist[i][j]=oo;
            taken[i][j]=0;
        }
    }
}

struct data
{
    int x,y,dist;
    bool operator < (const data & p) const{
        return dist > p.dist;
    }
};

int dijkstra(int sx,int sy,int dx,int dy)
{
    dist[sx][sy]=cost[sx][sy];
    taken[sx][sy]=1;
    priority_queue<data>pq;
    data d;
    d.x=sx; d.y=sy; d.dist=cost[sx][sy];
    pq.push(d);
    while(!pq.empty()){
        data u=pq.top(); pq.pop();
        for(int k=0;k<4;k++){
            int nx=u.x+fx[k];
            int ny=u.y+fy[k];
            if(nx>0 && nx<=n && ny>0 && ny<=m){
                int ndist=u.dist+cost[nx][ny];
                if(ndist<dist[nx][ny]){
                    dist[nx][ny]=ndist;
                    data v;
                    v.x=nx; v.y=ny; v.dist=ndist;
                    pq.push(v);
                    taken[nx][ny]=1;
                }
            }
        }
    }
    return dist[dx][dy];
}

int main()
{
    int i,j,t,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++) scanf("%d",&cost[i][j]);
        }
        init();
        ans=dijkstra(1,1,n,m);
        printf("%d\n",ans);
    }
    return 0;
}
