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
#define M 27
#define oo 1<<30

int fx[]={0,0,-1,1};
int fy[]={-1,1,0,0};

int n,g_cnt,h_cnt;

struct node{
    int G,H,obs;
    int lev[55];
};
node grid[M][M];

void init()
{
    memset(grid,-1,sizeof(grid));
}

void BFS(int sx,int sy)
{
    //printf("%d %d\n",sx,sy);
    int a=grid[sx][sy].G;
    grid[sx][sy].lev[a]=0;
    queue<int>q;
    q.push(sx);
    q.push(sy);
    while(!q.empty()){
        int ux=q.front(); q.pop();
        int uy=q.front(); q.pop();
        int ucost=grid[ux][uy].lev[a];
        for(int i=0;i<4;i++){
            int vx=ux+fx[i];
            int vy=uy+fy[i];
            if(vx>=0 && vx<n && vy>=0 && vy<n && grid[vx][vy].obs!=1 && grid[vx][vy].lev[a]==-1){
                grid[vx][vy].lev[a]=ucost+1;
                q.push(vx);
                q.push(vy);
            }
        }
    }
}

vector<int>E[55];
int Left[55],Right[55],used[55];

int match(int u)
{
    if(used[u]) return 0;
    used[u]=1;
    for(int i=0;i<E[u].size();i++){
        int v=E[u][i];
        if(Left[v]==-1 || match(Left[v])){
            Left[v]=u;
            Right[u]=v;
            return 1;
        }
    }
    return 0;
}

int BPM()
{
    /*for(int i=0;i<55;i++){
        printf("%d ---> %d %d\n",i,Left[i],Right[i]);
    }*/
    int path=1,ans=0;
    while(path){
        path=0;
        memset(used,0,sizeof(used));
        for(int i=1;i<=g_cnt;i++) if(!used[i] && Right[i]==-1) path+=match(i);
    }
    /*for(int i=0;i<55;i++){
        printf("%d ==---====> %d %d\n",i,Left[i],Right[i]);
    }*/
    for(int i=1;i<55;i++) if(Left[i]!=-1) ans++;
    return ans;
}

void make_graph(int val)
{
    //printf("===>===>%d\n",val);
    int i,j,k,l,a,b;
    for(i=0;i<55;i++){
        E[i].clear();
        Right[i]=-1;
        Left[i]=-1;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(grid[i][j].G==-1) continue;
            a=grid[i][j].G;
            for(k=0;k<n;k++){
                for(l=0;l<n;l++){
                    if(grid[k][l].H==-1) continue;
                    b=grid[k][l].H;
                    if(grid[k][l].lev[a]<=val && grid[k][l].lev[a]!=-1) {
                        //printf("===>===>===>%d %d\n",a,b);
                        E[a].push_back(b);
                    }
                }
            }
        }
    }
    /*for(i=1;i<55;i++){
        printf("%d --> ",i);
        for(j=0;j<E[i].size();j++)  printf(" %d",E[i][j]);
        printf("\n");
    }*/
}

int Bin_Search()
{
    int hi=n*n,lo=0,mid,val,ret=-1;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        make_graph(mid);
        val=BPM();
        //printf("===================================> %d %d\n",mid,val);
        if(val==h_cnt){
            ret=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    return ret;
}

int main()
{
    //freopen("B.txt","w",stdout);
	int i,j,k,l,t,kase=0,ans;
	char ch;
	scanf("%d",&t);
	while(t--){
        scanf("%d",&n);
        init();
        g_cnt=0;
        h_cnt=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf(" %c",&ch);
                if(ch=='G') grid[i][j].G=++g_cnt;
                if(ch=='H') grid[i][j].H=++h_cnt;
                if(ch=='#') grid[i][j].obs=1;
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++) if(grid[i][j].G!=-1) BFS(i,j);
        }
        //printf("%d ---- %d\n",g_cnt,h_cnt);
        ans=Bin_Search();
        //cerr<<"-------------------------->";
        printf("Case %d: ",++kase);
        if(ans==-1) printf("Vuter Dol Kupokat\n");
        else printf("%d\n",ans*2 + 2);
	}
	return 0;
}

