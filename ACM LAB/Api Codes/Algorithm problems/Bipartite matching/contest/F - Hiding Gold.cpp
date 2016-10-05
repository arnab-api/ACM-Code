#include<bits/stdc++.h>
using namespace std;
#define M 444

int grid[22][22],Left[M],Right[M],used[M],m,n;
vector<int>E[M];

int fx[]={0,0,1,-1};
int fy[]={1,-1,0,0};

void call(int x,int y)
{
    if(grid[x][y]==0) return;
    int u=grid[x][y];
    for(int i=0;i<4;i++){
        int vx=x+fx[i];
        int vy=y+fy[i];
        if(vx>=0 && vx<m && vy>=0 && vy<n){
            int v=grid[vx][vy];
            if(v!=0) E[u].push_back(v);
        }
    }
}

void init()
{
    for(int i=0;i<M;i++){
        E[i].clear();
        Right[i]=-1;
        Left[i]=-1;
    }
}

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
        for(int i=1;i<=N;i++) if(!used[i] && Right[i]==-1) path+=match(i);
    }
    for(int i=1;i<=N;i++) if(Right[i]!=-1) ans++;
    return ans/2;
}

int main()
{
    int i,j,t,cnt,ans,kase=0;
    char ch;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);

        init();
        cnt=0;
        memset(grid,0,sizeof(grid));

        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                scanf(" %c",&ch);
                if(ch=='*') grid[i][j]=++cnt;
            }
        }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++) call(i,j);
        }
        ans=cnt-BPM(cnt);
        //cerr<<"------------------->";
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}
