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
#define N 105

int vis[N][N],i,j,n;
char input[N][N];
int fx[]={1,0,-1,0};
int fy[]={0,1,0,-1};

void DFS(int x,int y)
{
    int k;
    vis[x][y]=1;
    for(k=0;k<4;k++){
        int nx=x+fx[k];
        int ny=y+fy[k];
        if(nx>=0 && nx<n && ny>=0 && ny<n && (!vis[nx][ny])){
            DFS(nx,ny);
        }
    }
}

int main()
{
    int t,c=0;
    scanf("%d\n",&t);
    while(t--){
        scanf(" %d\n",&n);
        for(i=0;i<n;i++) gets(input[i]);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(input[i][j]=='x' || input[i][j]=='@') vis[i][j]=0;
                else vis[i][j]=1;
            }
        }
        int cnt=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(!vis[i][j] && input[i][j]=='x'){
                    cnt++;
                    DFS(i,j);
                }
            }
        }
        c++;
        printf("Case %d: %d\n",c,cnt);
    }
    return 0;
}
