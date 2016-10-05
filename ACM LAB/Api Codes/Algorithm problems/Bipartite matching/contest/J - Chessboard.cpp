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
#define M 1111

vector<int>E[M];
int Left[M],Right[M],n,m;
int Grid[35][35];

void init()
{
    memset(Grid,0,sizeof(Grid));
    for(int i=0;i<M;i++){
        E[i].clear();
        Left[i]=-1;
        Right[i]=-1;
    }
}


int fx[]={0,0,-1,1};
int fy[]={-1,1,0,0};

void call(int sx,int sy)
{
    if(Grid[sx][sy]) return;
    for(int i=0;i<4;i++){
        int vx=sx+fx[i];
        int vy=sy+fy[i];
        if(vx>=0 && vx<m && vy>=0 && vy<n && Grid[vx][vy]!=1){
            E[sx*n+sy].push_back(vx*n+vy);
        }
    }
}

int used[M];

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

int BPM(int N)
{
    int path=1,ans=0;
    while(path){
        path=0;
        memset(used,0,sizeof(used));
        for(int i=0;i<N;i++){
            if(!used[i] && Right[i]==-1) path+=match(i);
        }
    }
    for(int i=0;i<N;i++) if(Right[i]!=-1) ans++;
    return ans;
}

int main()
{
    int i,j,k,t,a,b,ans,kase=0;
    while(scanf("%d%d%d",&m,&n,&k)==3){
        init();
        for(i=0;i<k;i++){
            scanf("%d%d",&a,&b);
            a--;b--;
            Grid[b][a]=1;
        }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++) call(i,j);
        }
        if(BPM(M)==m*n-k) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
/**
4 3 2
2 1
3 3

4 4 3
4 1
1 2
2 4

4 4 2
4 1
2 4
**/
