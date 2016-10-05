#include<bits/stdc++.h>
using namespace std;
#define M 111

vector<int>E[M];
int Left[M],Right[M],used[M],m,n;

void init()
{
    for(int i=0;i<M;i++){
        E[i].clear();
        Right[i]=-1;
        Left[i]=-1;
    }
}

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
        for(int i=0;i<N;i++) if(!used[i] && Right[i]==-1) path+=match(i);
    }
    for(int i=0;i<N;i++) if(Right[i]!=-1) ans++;
    return ans;
}

struct data
{
    int hit,age,div;
};

bool con(data A,data B)
{
    if(abs(A.hit-B.hit)>12) return false;
    if(abs(A.age-B.age)>5)  return false;
    if(A.div!=B.div) return false;;
    return true;
}

data Men[M],Women[M];

int main()
{
    int i,j,k,l,a,b,t,kase=0,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        init();
        for(i=0;i<m;i++){
            scanf("%d%d%d",&Men[i].hit,&Men[i].age,&Men[i].div);
        }
        for(i=0;i<n;i++){
            scanf("%d%d%d",&Women[i].hit,&Women[i].age,&Women[i].div);
        }
        for(i=0;i<m;i++){
            a=i;
            for(j=0;j<n;j++){
                b=j+m;
                if(con(Men[i],Women[j])) E[a].push_back(b);
            }
        }
        ans=BPM(n+m);
        //cerr<<"------------------->";
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}
