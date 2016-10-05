#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
#define infinity 1000000
#define N 1000
int sx,sy,dx,dy,r,c,i,j,k;
int dist[N][N],vis[N][N];
int fx[]={1,0,-1,0};
int fy[]={0,1,0,-1};

void init()
{
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            dist[i][j]=infinity;
            vis[i][j]=0;
        }
    }
}
void BFS(int sx,int sy,int dx,int dy)
{
    dist[sx][sy]=0;
    vis[sx][sy]=1;
    queue<pair<int,int> >q;
    q.push(make_pair(sx,sy));
    while(!q.empty()){
        int ux=q.front().first; int uy=q.front().second; q.pop();
        int ucost=dist[ux][uy];
        for(i=0;i<4;i++){
            int nx=ux+fx[i];
            int ny=uy+fy[i];
            if((nx>=0 && nx<r) && (ny>=0 && ny<c) && vis[nx][ny]==0){
                vis[nx][ny]=1;
                dist[nx][ny]=ucost+1;
                q.push(make_pair(nx,ny));
            }
        }
        if(vis[dx][dy]==1) return;
    }
}

int main()
{
    int rows;
    while(scanf("%d%d",&r,&c)==2){
        if(r==0 && c==0) break;
        init();
        int rin,b,c_in;
        scanf("%d",&rows);
        for(i=0;i<rows;i++){
            scanf("%d%d",&rin,&b);
            for(j=0;j<b;j++){
                scanf("%d",&c_in);
                vis[rin][c_in]=1;
            }
        }
        scanf("%d%d%d%d",&sx,&sy,&dx,&dy);
        BFS(sx,sy,dx,dy);
        printf("%d\n",dist[dx][dy]);
    }
	return 0;
}
