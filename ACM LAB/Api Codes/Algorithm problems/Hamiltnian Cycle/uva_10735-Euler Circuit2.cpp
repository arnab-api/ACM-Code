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
#define M 111
#define oo 1<<30

int ex[1111],ey[1111],ed[1111],em[1111];
int conn[M][M],deg[M],need[M],seen[M],n,m,vis[M];
vector<int>adj[M];

void init()
{
    memset(ex,0,sizeof(ex));
    memset(ey,0,sizeof(ey));
    memset(ed,0,sizeof(ed));
    memset(em,0,sizeof(em));
    memset(vis,0,sizeof(vis));

    memset(conn,0,sizeof(conn));
    memset(deg,0,sizeof(deg));
    for(int i=0;i<M;i++) adj[i].clear();
}

void tour(int x)
{
	while (adj[x].size() > 0) {
		int y = adj[x].back();
		adj[x].pop_back();
		tour(y);
	}
	printf(m++ ? " %d" : "%d", x);
}

int aug(int u)
{
    if(seen[u]) return 0;
    seen[u]=1;
    for(int i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(em[v]==0 || aug(em[v])){
            em[v]=u;
            return 1;
        }
    }
    return 0;
}

int solve()
{
    int i,j,k;
    for(i=0;i<m;i++){
        conn[ex[i]][ey[i]] = conn[ey[i]][ex[i]] = 1;
        deg[ex[i]]++ ; deg[ey[i]]++;
    }
    ///build connection graph;
    for(k=1;k<=n;k++){
        conn[k][k]=1;
        for(i=1;i<=n;i++){
            if(conn[i][k]){
                for(j=1;j<=n;j++){
                    conn[i][j] |= conn[k][j];
                }
            }
        }
    }
    /// if the graph isn't connected return
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++) if(!conn[i][j]) return 0;
    }
    /// if the graph(undirected) has a node with odd degree return
    for(i=1;i<=n;i++) if(deg[i] & 1) return 0;

    for(i=1;i<=n;i++) need[i] = deg[i]/2;
    for(i=0;i<m;i++) {
        if(!ed[i]){
            adj[ex[i]].push_back(i);
            adj[ey[i]].push_back(i);
        }
        else{
            em[i] = ey[i];
            if(--need[em[i]]<0) return 0;
        }
    }

    for(i=1;i<=n;i++){
        for(;need[i]>0;need[i]--){
            memset(seen,0,sizeof(seen));
            if(!aug(i)) return 0;
        }
    }
    for (i = 1; i <= n; i++) adj[i].clear();

	for (i = 0; i < m; i++)
		if (ed[i] || ey[i]==em[i]) adj[ey[i]].push_back(ex[i]);
		else  adj[ex[i]].push_back(ey[i]);
	m = 0;
	tour(1);
	printf("\n");

	return 1;
}

int main()
{
	int i,j,k,l,t,a,b;
	char ch;
	scanf("%d",&t);
	while(t--){
        scanf("%d%d",&n,&m);
        init();
        for(i=0;i<m;i++){
            scanf("%d %d %c",&a,&b,&ch);
            ex[i]=a; ey[i]=b;
            if(ch=='D') ed[i]=1;
        }
        if(!solve()) printf("No euler circuit exist\n");
        if(t) printf("\n");
	}
	return 0;
}
