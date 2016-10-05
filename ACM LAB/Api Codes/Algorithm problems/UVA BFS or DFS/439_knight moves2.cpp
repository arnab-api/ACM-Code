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
#define N 8

int dist[N][N],vis[N][N],i,j,sx,sy,dx,dy;
int fx[]={2,2,1,-1,-2,-2,-1,1};
int fy[]={-1,1,-2,-2,-1,1,2,2};

void init()
{
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            vis[i][j]=0;
            dist[i][j]=infinity;
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
        for(i=0;i<8;i++){
            int nx=ux+fx[i];
            int ny=uy+fy[i];
            if((nx>=0 && nx<8) && (ny>=0 && ny<8) && vis[nx][ny]==0){
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
    char ch1[5],ch2[5];
    while(scanf("%s%s",&ch1,&ch2)==2){
        sx=ch1[0]-'a';
        sy=ch1[1]-'1';
        dx=ch2[0]-'a';
        dy=ch2[1]-'1';
        init();
        BFS(sx,sy,dx,dy);
        printf("To get from %s to %s takes %d knight moves.\n",ch1,ch2,dist[dx][dy]);
    }
    return 0;
}
