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
#define M 222
#define oo 1<<30

vector<int>G[M],E[M];
int Left[M],Right[M],used[M],flag[M],adj[M][M];

void init(int N)
{
    memset(adj,0,sizeof(adj));
    for(int i=0;i<N;i++){
        E[i].clear();
        G[i].clear();
        Left[i]=-1;
        Right[i]=-1;
        used[i]=0;
    }
}

void Build_Graph(int cat,int an,int N)
{
    int i,j,a,b;
    for(i=0;i<N;i++) E[i].clear();
    for(i=0;i<G[cat].size();i++){
        for(j=0;j<G[an].size();j++){
            a=G[cat][i];
            b=G[an][j];
            if(adj[a][b]==0){
                E[a].push_back(b);
                E[b].push_back(a);
            }
        }
    }
}

int match(int u)
{
    if(used[u] || flag[u]) return 0;
    used[u]=1;
    for(int i=0;i<E[u].size();i++){
        int v=E[u][i];
        if(flag[v]) continue;
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
    int path=1,ret=0;
    for(int i=0;i<N;i++){
        Left[i]=-1;
        Right[i]=-1;
    }
    while(path)
    {
        path=0;
        memset(used,0,sizeof(used));
        for(int i=0;i<N;i++) if(!flag[i] && !used[i] && Right[i]==-1) path+=match(i);
    }
    for(int i=0;i<N;i++) if(Right[i]!=-1) ret++;
    return ret/2;
}

int main()
{
    int n,m,i,j,t,ans,kase=0,cat,an,q;
    char ch;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        init(m+n);
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                scanf(" %c",&ch);
                if(ch=='1'){
                    G[i].push_back(m+j);
                    G[m+j].push_back(i);
                    adj[i][m+j]=1;
                    adj[m+j][i]=1;
                }
            }
        }
        /*for(i=0;i<m;i++){
            printf("%d --->",i);
            for(j=0;j<E[i].size();j++) printf(" %d",E[i][j]);
            printf("\n");
        }*/
        ans=0;
        for(i=0;i<m;i++){
            for(j=0;j<G[i].size();j++){
                cat=i;
                an=G[i][j];
                Build_Graph(cat,an,m+n);
                q=G[cat].size()+G[an].size();
                ans=max(ans,q-BPM(m+n));
            }
        }
        //cerr<<"----------------->";
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}
/**
5
3 4
1100
1110
0011
2 2
10
00
2 2
00
00
2 3
001
000
2 3
000
000

1
3 2
111
111
**/
