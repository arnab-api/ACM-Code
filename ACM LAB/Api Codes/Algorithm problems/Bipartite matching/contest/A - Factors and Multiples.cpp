#include<bits/stdc++.h>
using namespace std;
#define M 220

vector<int>E[M];
int Left[M],Right[M],A[M],B[M],n,m;

void init()
{
    for(int i=0;i<M;i++){
        E[i].clear();
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
    int i,j,n,m,t,a,b,ans,kase=0;
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&A[i]);
        scanf("%d",&m);
        for(i=0;i<m;i++) scanf("%d",&B[i]);
        for(i=0;i<n;i++){
            a=i;
            for(j=0;j<m;j++){
                b=j+n;
                if(B[j]%A[i]==0) E[a].push_back(b);
            }
        }
        ans=BPM(n+m);
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}
