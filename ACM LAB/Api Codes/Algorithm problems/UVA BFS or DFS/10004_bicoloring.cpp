#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<iostream>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<iterator>
#include<string>
#include<map>
#include<set>

using namespace std;
vector<int>v[1000];
int col[1000],n;
int r;
void init()
{
    for(int i=0;i<n;i++){
        v[i].clear();
        col[i]=-1;
    }
}
int BFS(int source)
{
    col[source]=0;
    queue<int>q;
    q.push(source);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<v[u].size();i++){
            int n=v[u][i];
            if(col[n]==-1){
                if(col[u]==0) col[n]=1;
                else col[n]=0;
                q.push(n);
            }
            else if(col[n]==col[u]){
                r=1;
                return r;
            }
        }
    }
    return r;
}
int main()
{
    int l,i,j,a,b,k;
    while(scanf("%d",&n)==1){
        if(n==0) break;
        scanf("%d",&l);
        init();
        for(i=0;i<l;i++){
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        r=0;
        BFS(0);
        if(r==0) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }
    return 0;
}
