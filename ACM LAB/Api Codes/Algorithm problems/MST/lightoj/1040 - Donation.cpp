#include<bits/stdc++.h>
using namespace std;
#define M 55

struct edge{
    int u,v,w;
    edge(int a,int b,int c){
        u=a; v=b; w=c;
    }
    bool operator < (const edge & p)const{
        return w < p.w;
    }
};

vector<edge>E;
int par[M];

void init(int N)
{
    E.clear();
    for(int i=0;i<N;i++){
        par[i]=i;
    }
}

int find_set(int u)
{
    if(u==par[u]) return u;
    return par[u]=find_set(par[u]);
}

int MST(int N)
{
    int ret=0;
    sort(E.begin(),E.end());
    for(int i=0;i<E.size();i++){
        int u=E[i].u;
        int v=E[i].v;
        int w=E[i].w;
        if(find_set(u)!=find_set(v)){
            ret+=w;
            par[find_set(u)]=find_set(v);
        }
    }
    int cnt=0;
    for(int i=0;i<N;i++) if(i==par[i]) cnt++;
    if(cnt>1) return -1;
    return ret;
}

int main()
{
    int t,n,i,j,kase=0,sum,a,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        init(n);
        sum=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&a);
                sum+=a;
                if(a!=0 && i!=j) E.push_back(edge(i,j,a));
            }
        }
        ans=MST(n);
        printf("Case %d: ",++kase);
        if(ans==-1) printf("-1\n");
        else printf("%d\n",sum-ans);
    }
    return 0;
}
