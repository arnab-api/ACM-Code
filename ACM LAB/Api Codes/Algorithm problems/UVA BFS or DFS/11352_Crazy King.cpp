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
#define N 100
int dist[N][N],vis[N][N],sx,sy,dx,dy,r,c,i,j;
int kx[]={2,2,1,-1,-2,-2,-1,1};
int ky[]={-1,1,-2,-2,-1,1,2,2};
int x[]={1,0,-1,0,1,1,-1,-1};
int y[]={0,1,0,-1,-1,1,-1,1};

void init()
{
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
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
            if((vx>=0 && vx<r) && (vy>=0 && vy<c) && vis[vx][vy]==0){
                vis[vx][vy]=1;
                dist[vx][vy]=ucost+1;
                q.push(make_pair(vx,vy));
            }
        }
    }
}

int main()
{
    int t,k,l;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d\n",&r,&c);
        init();
        char input[r][c],ch;
        for(i=0;i<r;i++){
            gets(input[i]);
        }


        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(input[i][j]=='A'){
                    sx=i;sy=j;
                }
                if(input[i][j]=='B'){
                    dx=i;dy=j;
                }
                if(input[i][j]=='Z'){
                    vis[i][j]=1;
                    for(k=0;k<8;k++){
                        int lx=i+kx[k];
                        int ly=j+ky[k];
                        if((lx>=0 && lx<r) && (ly>=0 && ly<c) && input[lx][ly]!='A' && input[lx][ly]!='B'){
                            vis[lx][ly]=1;
                        }
                    }
                }
            }
        }
        BFS(sx,sy,dx,dy);
        if(dist[dx][dy]>r*c) printf("King Peter, you can't go now!\n");
        else printf("Minimal possible length of a trip is %d\n",dist[dx][dy]);
    }
    return 0;
}
