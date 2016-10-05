#include<cstdio>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<iostream>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<list>
#include<map>
#include<stack>
#include<queue>
#include<iterator>
#include<string>
#include<set>
using namespace std;
#define oo 1000000
vector<int>v[30];
int dist[30],vis[30];
void init()
{
    for(int i=0;i<30;i++){
        //v[i].clear();
        dist[i]=oo;
        vis[i]=0;
    }
}
void BFS(int source)
{
    dist[source]=0;
    vis[source]=1;
    queue<int>q;
    q.push(source);
    while(!q.empty()){
        int u=q.front(); q.pop();
        int ucost=dist[u];
        for(int k=0;k<v[u].size();k++){
            int n=v[u][k];
            if(!vis[n]){
                vis[n]=1;
                dist[n]=ucost+1;
                q.push(n);
            }
        }
    }
}
int main()
{
    int nc,i,j,k,c=0;;
    while(scanf("%d",&nc)==1){
        if(nc==0) break;
        int n1[nc],n2[nc],a,b,m1[nc],m2[nc];
        vector<int>uniq;
        set<int>s;
        for(i=0;i<nc;i++){
            scanf("%d%d",&a,&b);
            s.insert(a);
            s.insert(b);
            n1[i]=a;
            n2[i]=b;
        }
        set<int>:: iterator it;
        for(it=s.begin();it!=s.end();it++){
            uniq.push_back(*it);
        }
        //for(i=0;i<uniq.size();i++) printf("%d\n",uniq[i]);
        for(i=0;i<uniq.size();i++){
            for(j=0;j<nc;j++){
                if(uniq[i]==n1[j]) m1[j]=i;
                if(uniq[i]==n2[j]) m2[j]=i;
            }
        }
        //printf("\n\n\n");
        //for(i=0;i<nc;i++) printf("%d %d\n",m1[i],m2[i]);
        for(i=0;i<30;i++) v[i].clear();
        for(i=0;i<nc;i++){
            v[m1[i]].push_back(m2[i]);
            v[m2[i]].push_back(m1[i]);
        }
        int source,ttl;
        while(scanf("%d%d",&source,&ttl)==2){
            if(source==0 && ttl==0) break;
            init();
            c++;
            int ans=0;
            int srce;
            for(i=0;i<uniq.size();i++) if(uniq[i]==source) srce=i;
            BFS(srce);
            //printf("%d %d\n",source,srce);
            for(i=0;i<uniq.size();i++){
                if(dist[i]>ttl) ans++;
            }
            //for(i=0;i<uniq.size();i++) printf("%d %d %d\n",i,uniq[i],dist[i]);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",c,ans,source,ttl);
        }
    }
    return 0;
}
