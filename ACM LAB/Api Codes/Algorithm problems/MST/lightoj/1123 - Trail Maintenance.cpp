#include<bits/stdc++.h>
using namespace std;
#define M 210

struct edge{
    int u,v,w;
    bool operator < (const edge & p)const{
        return w < p.w;
    }
};

edge tmp[6005],E[6005];
int par[M],n,w;

int find_set(int u)
{
    if(u==par[u]) return u;
    return par[u]=find_set(par[u]);
}

bool enough;
int done;

void MST(int sizee)
{
    int ret=0,i;
    for(i=1;i<=n;i++) par[i]=i;
    sort(E,E+sizee);
    done=0;
    for(i=0;i<sizee;i++){
        int u=E[i].u;
        int v=E[i].v;
        int w=E[i].w;
        if(find_set(u)!=find_set(v)){
            ret+=w;
            par[find_set(u)]=find_set(v);
            tmp[done++]=E[i];
        }
    }
    for(i=0;i<done;i++) E[i]=tmp[i];
    //cerr<<"------------------>";
    if(done==n-1){
        printf("%d\n",ret);
        enough=true;
    }
    else printf("-1\n");
}

int main()
{
    int t,i,j,kase=0,a,b,c,ans;
    scanf("%d",&t);
    while(t--){

        enough=false;
        done=0;

        printf("Case %d:\n",++kase);
        scanf("%d%d",&n,&w);
        while(w--){
            scanf("%d%d%d",&a,&b,&c);
            if(enough){
                E[n-1].u=a;
                E[n-1].v=b;
                E[n-1].w=c;
                MST(n);
            }
            else{
                E[done].u=a;
                E[done].v=b;
                E[done].w=c;
                MST(done+1);
            }
        }
    }
    return 0;
}
