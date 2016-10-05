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

vector<int>E[M],G[M];
int Left[M],Right[M],vis[M];

void init()
{
    for(int i=0;i<M;i++){
        E[i].clear();
        G[i].clear();
        Left[i]=-1;
        Right[i]=-1;
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
    int i,j,k,t,x,y,ans,kase=0,g,b,m;
    while(scanf("%d%d%d",&g,&b,&m)==3){
        if(g==0 && b==0 && m==0) break;
        init();
        while(m--){
            scanf("%d%d",&x,&y);
            x--; y--;
            G[x].push_back(y+g);
        }
        for(i=0;i<g;i++){
            memset(vis,0,sizeof(vis));
            for(j=0;j<G[i].size();j++) vis[G[i][j]-g]=1;
            for(j=0;j<b;j++) if(!vis[j]) {
                E[i].push_back(j+g);
                //E[j+g].push_back(i);
            }
        }
        /*for(i=0;i<g;i++){
            printf("%d -->",i+1);
            for(j=0;j<E[i].size();j++) printf(" %d",E[i][j]-g+1);
            printf("\n");
        }*/
        ans=g+b-BPM(g+b);
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}
