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
#define M 2020
#define oo 1<<30

int n,e;
vector<int>adj[M];
int col[M];

void init()
{
    for(int i=0;i<M;i++){
        adj[i].clear();
        col[i]=-1;
    }
}

bool BFS(int srce)
{
    queue<int>q;
    q.push(srce);
    col[srce]=0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        int col_u = col[u];
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i];
            //printf("%d(%d) %d(%d)\n",u,col[u],v,col[v]);
            if(col[v]==-1){
                col[v] = (1^col_u);
                q.push(v);
            }
            else if(!(col[v]^col[u])) return false;
        }
    }
    return true;
}

int main()
{
	int i,j,k,l,t,a,b,kase=0;
	scanf("%d",&t);
	while(t--){
        init();
        scanf("%d%d",&n,&e);
        while(e--){
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bool flag = true;
        for(i=1;i<=n;i++) if(col[i]==-1){
            flag = BFS(i);
            if(!flag) break;
        }

        //for(i=1;i<=n;i++) printf("%d(%d) ",i,col[i]);
        //printf("\n");

        printf("Scenario #%d:\n",++kase);
        if(flag) printf("No suspicious bugs found!\n");
        else printf("Suspicious bugs found!\n");
	}
	return 0;
}

