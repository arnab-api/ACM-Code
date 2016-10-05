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
#define N 8;

int vis[100][100],m,n,i,j;
int fx[]={1,1,1,0,0,-1,-1,-1};
int fy[]={-1,0,1,-1,1,-1,0,1};
char input[100][100];

void DFS(int x,int y)
{
    int k;
    vis[x][y]=1;
    for(k=0;k<8;k++){
        int nx=x+fx[k];
        int ny=y+fy[k];
        if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny]){
            DFS(nx,ny);
        }
    }
}

int main()
{
    while(scanf("%d%d",&m,&n)==2){
        if(m==0 && n==0) break;
        getchar();
        for(i=0;i<m;i++) gets(input[i]);
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(input[i][j]=='*') vis[i][j]=1;
                if(input[i][j]=='@') vis [i][j]=0;
            }
        }
        int c=0;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(!vis[i][j]){
                    //printf("==>%d %d\n",i,j);
                    c++;
                    DFS(i,j);
                }
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
