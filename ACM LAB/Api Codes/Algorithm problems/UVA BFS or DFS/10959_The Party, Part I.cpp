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

vector<int>v[1000];
int dist[1000];
void init()
{
    for(int i=0;i<=1000;i++){
        v[i].clear();
        dist[i]=infinity;
    }
}
void BFS()
{
    dist[0]=0;
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int u=q.front(); q.pop();
        int ucost=dist[u];
        for(int i=0;i<v[u].size();i++){
            int n=v[u][i];
            int ncost=ucost+1;
            if(ncost<dist[n]){
                dist[n]=ncost;
                q.push(n);
            }
        }
    }
}
int main()
{
    int p,d,i,j,t,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&p,&d);
        init();
        for(i=0;i<d;i++){
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        /*printf("\n\n");
        for(i=0;i<p;i++){
            printf("%d==> ",i);
            for(j=0;j<v[i].size();j++) printf("%d ",v[i][j]);
            printf("\n");
        }*/
        BFS();
        for(i=1;i<p;i++) printf("%d\n",dist[i]);
        if(t!=0) printf("\n");
    }
	return 0;
}
