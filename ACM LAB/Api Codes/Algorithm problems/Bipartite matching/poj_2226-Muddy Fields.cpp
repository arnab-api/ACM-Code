//#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<climits>
#include<cstring>
#include<cstdlib>

#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>

#include<vector>
#include<map>
#include<string>
#include<queue>
#include<set>
#include<iterator>
#include<numeric>
#include<stack>
#include<list>
using namespace std;
#define pi acos(-1)
#define M 55
#define MX 2555
#define oo 1<<30

char grid[M][M];
int lxn[M][M],nxl[M][M],n,m,yo1,yo2;

void DFS1(int x,int y,int mark)
{
    if(grid[x][y]=='.' || lxn[x][y]>0) return;
    lxn[x][y]=mark;
    int nx=x+1;
    int mx=x-1;
    //if(nx>=n) nx=0;
    //if(mx<0) mx=n-1;
    if(nx<n) DFS1(nx,y,mark);
    if(mx>=0) DFS1(mx,y,mark);
}

void DFS2(int x,int y,int mark)
{
    if(grid[x][y]=='.' || nxl[x][y]>0) return;
    nxl[x][y]=mark;
    int ny=y+1;
    int my=y-1;
    //if(ny>=m) ny=0;
    //if(my<0) my=m-1;
    if(ny<m) DFS2(x,ny,mark);
    if(ny>=0) DFS2(x,my,mark);
}

vector<int>E[MX];
int Right[MX],Left[MX],used[MX],flag[MX];

void init()
{
    memset(lxn,0,sizeof(lxn));
    memset(nxl,0,sizeof(nxl));
    for(int i=0;i<MX;i++){
        E[i].clear();
        Right[i]=-1;
        Left[i]=-1;
        used[i]=0;
        flag[i]=0;
    }
}

int match(int u)
{
    if(used[u] || flag[u]) return  0;
    used[u]=1;
    for(int i=0;i<E[u].size();i++){
        int v=E[u][i];
        if(flag[v]) continue;
        if(Left[v]==-1 || match(Left[v])){
            Right[u]=v;
            Left[v]=u;
            return 1;
        }
    }
    return 0;
}

int BPM(int N)
{
    memset(Left,-1,sizeof(Left));
    memset(Right,-1,sizeof(Right));
    int path=1,ret=0;
    while(path){
        path=0;
        memset(used,0,sizeof(used));
        for(int i=1;i<=N;i++) if(Right[i]==-1 && used[i]==0 && flag[i]==0) path+=match(i);
    }
    for(int i=1;i<=N;i++) if(Right[i]!=-1) ret++;
    //for(int i=1;i<=N;i++) if(Right[i]!=-1) printf("--->%d %d\n",i,Right[i]);
    return ret/2;
}

int Solve()
{
    int i,j,a,b;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(grid[i][j]=='*'){
                a=lxn[i][j];
                b=nxl[i][j];
                E[a].push_back(yo1+b);
                E[yo1+b].push_back(a);
            }
        }
    }
    int ret=0;
    int cur=BPM(yo1+yo2),val;
    for(i=1;i<=yo1+yo2;i++){
        flag[i]=1;
        val=BPM(yo1+yo2);
        if(val<cur) {
            cur=val;
            ret++;
            //printf("======>..........>%d\n",i);
        }
        else flag[i]=0;
        //printf("--->%d\n",cur);
    }
    return ret;
    //return BPM(yo1+yo2);
}

int main()
{
	int i,j,k,l,t,cnt;
	while(scanf("%d%d",&n,&m)==2){
        init();
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf(" %c",&grid[i][j]);
            }
        }
        cnt=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j]=='*' && lxn[i][j]==0) DFS1(i,j,++cnt);
            }
        }
        yo1=cnt;
        cnt=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j]=='*' && nxl[i][j]==0) DFS2(i,j,++cnt);
            }
        }
        yo2=cnt;
        /*printf("\n\n");
        for(i=0;i<n;i++){
            for(j=0;j<m;j++) printf(" %d",lxn[i][j]);
            printf("\n");
        }
        printf("\n\n");
        for(i=0;i<n;i++){
            for(j=0;j<m;j++) printf(" %d",nxl[i][j]);
            printf("\n");
        }
        printf("\n\n");*/
        //cerr<<"-------------------->";
        printf("%d\n",Solve());
	}
	return 0;
}

/**
2 4
*...
*..*
4 4
*.*.
.***
***.
..*.
**/
