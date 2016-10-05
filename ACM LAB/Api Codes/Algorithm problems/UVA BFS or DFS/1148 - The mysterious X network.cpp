#include<bits/stdc++.h>
using namespace std;
#define M 100010
#define oo INT_MAX

int dis[M],taken[M],n;
vector<int>v[M];

void init(int a)
{
    for(int i=0;i<a;i++){
        v[i].clear();
        dis[i]=oo;
        taken[i]=0;
    }
}

int BFS(int srce,int dest)
{
    taken[srce]=1; dis[srce]=0;
    queue<int>q;
    q.push(srce);
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int i=0;i<v[u].size();i++){
            int n=v[u][i];
            if(!taken[n]){
                taken[n]=1;
                dis[n]=dis[u]+1;
                q.push(n);
            }
        }
        if(taken[dest]==1) return dis[dest];
    }
    return -1;
}

int main()
{
    int t,i,j,a,b,c,nc,srce,dest;
    scanf("%d",&t);
    bool fst=true;
    while(t--)
    {
        scanf("%d",&n);
        init(n);
        for(i=0;i<n;i++){
            scanf("%d%d",&c,&nc);
            for(j=0;j<nc;j++){
                scanf("%d",&b);
                v[b].push_back(c);
                v[c].push_back(b);
            }
        }
        scanf("%d%d",&srce,&dest);
        int ans=BFS(srce,dest);
        if(!fst) printf("\n");
        else fst=false;
        printf("%d %d %d\n",srce,dest,ans-1);
    }
    return 0;
}
