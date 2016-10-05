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
#define N 35

int vis[N][N][N],dist[N][N][N],i,j,k,l,r,c;
char input[N][N][N];
int fx[]={0,0,0,0,1,-1};
int fy[]={0,0,1,-1,0,0};
int fz[]={1,-1,0,0,0,0};
void init()
{
    for(i=0;i<l;i++){
        for(j=0;j<r;j++){
            for(k=0;k<c;k++){
//                dist[i][j][k]=infinity;
                vis[i][j][k]=0;
            }
        }
    }
}
void BFS(int sx,int sy,int sz,int dx,int dy,int dz)
{
    dist[sx][sy][sz]=0;
    vis[sx][sy][sz]=1;
    queue<int>q;
    q.push(sx);
    q.push(sy);
    q.push(sz);
    while(!q.empty()){
        int ux=q.front();q.pop();
        int uy=q.front();q.pop();
        int uz=q.front();q.pop();
        int ucost=dist[ux][uy][uz];
        for(k=0;k<6;k++){
            int nx=ux+fx[k];
            int ny=uy+fy[k];
            int nz=uz+fz[k];
            if((nx>=0 && nx<l)&&(ny>=0 && ny<r)&&(nz>=0 && nz<c)&&vis[nx][ny][nz]==0){
                vis[nx][ny][nz]=1;
                dist[nx][ny][nz]=ucost+1;
                q.push(nx);
                q.push(ny);
                q.push(nz);
            }
        }
    }
}

int main()
{
    int sx,sy,sz,dx,dy,dz;
    while(scanf(" %d %d %d",&l,&r,&c)==3){
        if(l==0 && r==0 && c==0) break;
//        getchar();
        for(i=0;i<l;i++){
            for(j=0;j<r;j++){
                    scanf(" %s",&input[i][j]);
//                gets(input[i][j]);
            }
//            if(i<l-1) getchar();
        }
        init();
        for(i=0;i<l;i++){
            for(j=0;j<r;j++){
                for(k=0;k<c;k++){
                    if(input[i][j][k]=='S'){
                        sx=i;sy=j;sz=k;
                    }
                    else if(input[i][j][k]=='E'){
                        dx=i;dy=j;dz=k;
                    }
                    else if(input[i][j][k]=='#') vis[i][j][k]=1;
                }
            }
        }
        BFS(sx,sy,sz,dx,dy,dz);
        if(vis[dx][dy][dz]==0) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n",dist[dx][dy][dz]);
    }
    return 0;
}
