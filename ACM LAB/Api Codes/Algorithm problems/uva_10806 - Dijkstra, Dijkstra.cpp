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
#define M 110
#define oo INT_MAX

int n,m,vis[M],D[M],used[M][M],P[M],jog[M];
vector<int>edge[M],cost[M];

struct data
{
    int node,cost;
    data(int n,int c){
        node=n; cost=c;
    }
    bool operator < (const data & p) const{
        return cost > p.cost;
    }
};

int dijkstra(int srce,int dest)
{
    for(int i=0;i<M;i++){
        vis[i]=0;
        D[i]=oo;
    }
    vis[srce]=1;
    D[srce]=0;
    priority_queue<data>pq;
    pq.push(data(srce,0));
    while(!pq.empty()){
        data u=pq.top(); pq.pop();
        for(int i=0;i<edge[u.node].size();i++){
            int vnode=edge[u.node][i];
            int vcost=u.cost+cost[u.node][i];
            if(vcost<D[vnode]){
                D[vnode]=vcost;
                vis[vnode]=1;
                P[vnode]=u.node;
                jog[vnode]=cost[u.node][i];
                pq.push(data(vnode,vcost));
            }
        }
    }
    if(!vis[dest]) return -1;
    return D[dest];
}

void init()
{
    for(int i=0;i<M;i++){
        edge[i].clear();
        cost[i].clear();
        for(int j=0;j<M;j++) used[i][j]=0;
    }
}

vector<int> :: iterator it;

int main()
{
	int i,j,k,l,t,a,b,c,ans,val;
	while(scanf("%d",&n)==1){
        if(n==0) break;
        init();
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            edge[a].push_back(b);
            edge[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }
        cout<<"---------------------------->";
        ans=dijkstra(1,n);
        if(ans==-1) printf("Back to jail\n");
        else{
            printf("%d\n====>",ans);
            k=n;
            while(k!=1){
                printf("%d(%d)<--",k,jog[k]);
                used[k][P[k]]=used[P[k]][k]=1;
                a=k; b=P[k]; c=jog[k];
                for(i=0;i<edge[a].size();i++) if(edge[a][i]==b && cost[a][i]==c) break;
                edge[a].erase(edge[a].begin()+i);
                cost[a].erase(cost[a].begin()+i);
                a=P[k]; b=k; c=jog[k];
                for(i=0;i<edge[a].size();i++) if(edge[a][i]==b && cost[a][i]==c) break;
                edge[a].erase(edge[a].begin()+i);
                cost[a].erase(cost[a].begin()+i);
                k=P[k];
            }
            printf("1\n");
            val=dijkstra(1,n);
            if(val==-1) printf("Back to jail\n");
            else{
                ans=ans+val;
                printf("------------------------------------------------->%d\n==>",ans);
                k=n;
                while(k!=1){
                    printf("%d(%d)<--",k,jog[k]);
                    used[k][P[k]]=used[P[k]][k]=1;
                    k=P[k];
                }
                printf("1\n");
            }
        }
	}
	return 0;
}

