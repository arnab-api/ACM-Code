#include<bits/stdc++.h>
using namespace std;
#define M 210

int n,vis[M][M];
char input[M][M],ch;

int fx[]={-1,-1,0,0,1,1};
int fy[]={-1,0,-1,1,0,1};


void DFS(int x,int y)
{
    if(vis[x][y]==1) return;
    vis[x][y]=1;
    for(int i=0;i<6;i++){
        int nx=x+fx[i];
        int ny=y+fy[i];
        if(!vis[nx][ny] && nx>=0 && nx<n && ny>=0 && ny<n && input[nx][ny]=='b') DFS(nx,ny);
    }
}

int main()
{
    int i,j,kase=0;
    while(scanf("%d",&n)==1){
        if(n==0) break;
        for(i=0;i<n;i++){
            getchar();
            for(j=0;j<n;j++) scanf("%c",&input[i][j]);
        }
        bool black=false;
        for(i=0;i<n;i++){
            if(input[0][i]=='b'){
                memset(vis,0,sizeof(vis));
                DFS(0,i);
                for(j=0;j<n;j++) if(input[n-1][j]=='b' && vis[n-1][j]==1) black=true;
            }
            if(black==true) break;
        }
       /* memset(vis,0,sizeof(vis));
        DFS(0,1);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++) printf("%d",vis[i][j]);
            printf("\n");
        }*/
        kase++;
        if(!black) printf("%d W\n",kase);
        else printf("%d B\n",kase);
    }
    return 0;
}
