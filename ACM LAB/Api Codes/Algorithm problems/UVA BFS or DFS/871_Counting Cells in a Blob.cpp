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
#define N 25

int vis[N][N],i,j,l,c;
char grid[N][N];
int fx[]={1,1,1,0,0,-1,-1,-1};
int fy[]={-1,0,1,-1,1,-1,0,1};

void DFS(int x,int y)
{
    int k;
    c++;
    vis[x][y]=1;
    for(k=0;k<8;k++){
        int nx=x+fx[k];
        int ny=y+fy[k];
        if(nx>=0 && nx<l && ny>=0 && ny<l && !vis[nx][ny]){
            DFS(nx,ny);
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        getchar();
        gets(grid[0]);
        l=strlen(grid[0]);
        for(i=1;i<l;i++) gets(grid[i]);
        for(i=0;i<l;i++){
            for(j=0;j<l;j++){
               if(grid[i][j]=='1') vis[i][j]=0;
               if(grid[i][j]=='0') vis[i][j]=1;
            }
        }
        int max=0;
        for(i=0;i<l;i++){
            for(j=0;j<l;j++){
                if(!vis[i][j]){
                    c=0;
                    DFS(i,j);
                    if(c>max) max=c;
                }
            }
        }
        printf("%d\n",max);
        if(t!=0) printf("\n");
    }
    return 0;
}
