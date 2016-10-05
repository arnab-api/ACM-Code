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
#define oo 1000000

vector<int>edge[25];
int vis[25],dist[25];
void init()
{
    for(int i=0;i<25;i++){
        vis[i]=0;
        dist[i]=oo;
    }
}
int BFS(int srce, int dst)
{
    vis[srce]=1;
    dist[srce]=0;
    queue<int>q;
    q.push(srce);
    while(!q.empty()){
        int u=q.front();q.pop();
        int ucost=dist[u];
        for(int k=0;k<edge[u].size();k++){
            int v=edge[u][k];
            if(!vis[v]){
                vis[v]=1;
                dist[v]=ucost+1;
                q.push(v);
            }
        }
        if(vis[dst]==1) return dist[dst];
    }
}
int main()
{
    int i,j,a,b,x,k,n,c=0;
    while(scanf("%d",&x)==1){
        for(k=0;k<25;k++) edge[k].clear();
        for(k=0;k<x;k++){
            scanf("%d",&j);
            edge[1].push_back(j);
            edge[j].push_back(1);
        }
        for(i=2;i<=19;i++){
            scanf("%d",&x);
            for(k=0;k<x;k++){
            scanf("%d",&j);
            edge[i].push_back(j);
            edge[j].push_back(i);
            }
        }
        c++;
        printf("Test Set #%d\n",c);

        scanf("%d",&n);
        while(n--){
            init();
            scanf("%d%d",&a,&b);
            printf("%2d to %2d: %d\n",a,b,BFS(a,b));
        }
        printf("\n");
    }
	return 0;
}
