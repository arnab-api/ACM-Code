#include<bits/stdc++.h>
using namespace std;

#define M 110

int n,m,A[M],B[M],Right[110],Left[110],used[110];
vector<int>edge[M];

void init()
{
    for(int i=0;i<M;i++){
        edge[i].clear();
        Right[i]=-1;
        Left[i]=-1;
        used[i]=0;
    }
}

int match(int u)
{
    if(used[u]==1) return 0;
    used[u]=1;
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if(Left[v]==-1 || match(Left[v])){
            Left[v]=u;
            Right[u]=v;
            return 1;
        }
    }
    return 0;
}

int BPM()
{
    int ans=0,path=1;
    while(path){
        path=0;
        memset(used,0,sizeof(used));
        for(int i=0;i<n;i++){
            if(!used[i] && Right[i]==-1){
                path+=match(i);
            }
        }
    }
    for(int i=0;i<n;i++) if(Right[i]!=-1) ans++;
    return ans;
}

int main()
{
    int i,j,t,kase=0;
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&A[i]);
        scanf("%d",&m);
        for(i=0;i<m;i++) scanf("%d",&B[i]);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++) if(A[i] && B[j]%A[i]==0) {
                edge[i].push_back(j);
            }
        }
        printf("Case %d: %d\n",++kase,BPM());
    }
    return 0;
}
