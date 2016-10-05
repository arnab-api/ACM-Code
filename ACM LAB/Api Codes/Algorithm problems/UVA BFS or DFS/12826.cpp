#include<bits/stdc++.h>
using namespace std;
#define infinity 1000000
#define N 10

int dist[N][N],vis[N][N],sx,sy,dx,dy,r,c,i,j;
int x[]={1,0,-1,0,1,1,-1,-1};
int y[]={0,1,0,-1,-1,1,-1,1};

void init()
{
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            vis[i][j]=0;
            dist[i][j]=infinity;
        }
    }
}

void BFS(int sx,int sy,int dx,int dy)
{
    vis[sx][sy]=1;
    dist[sx][sy]=0;
    queue<pair<int,int> >q;
    q.push(make_pair(sx,sy));
    while(!q.empty())
    {
        int ux=q.front().first; int uy=q.front().second; q.pop();
        int ucost=dist[ux][uy];
        for(i=0;i<8;i++){
            int vx=ux+x[i];
            int vy=uy+y[i];
            if((vx>=1 && vx<=8) && (vy>=1 && vy<=8) && vis[vx][vy]==0){
                vis[vx][vy]=1;
                dist[vx][vy]=ucost+1;
                q.push(make_pair(vx,vy));
            }
        }
    }
}


int main()
{
    int r1,c1,r2,c2,r3,c3,kase=0;
    while(scanf("%d%d%d%d%d%d",&r1,&c1,&r2,&c2,&r3,&c3)==6){
        init();
        vis[r3][c3]=1;
        BFS(r1,c1,r2,c2);
        printf("Case %d: %d\n",++kase,dist[r2][c2]);
    }
    return 0;
}
