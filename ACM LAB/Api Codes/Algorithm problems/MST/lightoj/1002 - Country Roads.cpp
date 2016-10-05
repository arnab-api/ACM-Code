#include<bits/stdc++.h>
using namespace std;
#define N 510
int n,m,srce,dst;
struct edge{
    int u,v,w;
    edge(int a,int b,int c){
        u=a; v=b; w=c;
    }
};
vector<edge>E;
bool con(edge a,edge b)
{
    return a.w<b.w;
}
int p[N];
void make_set(int a)
{
    p[a]=a;
}

int find_set(int a)
{
    if(p[a]==a) return a;
    else return p[a]=find_set(p[a]);
}

int MST()
{
    int a,b,c,r=0;
    for(int i=0;i<E.size();i++){
        if(find_set(srce)==find_set(dst)) return r;
        a=E[i].u; b=E[i].v; c=E[i].w;
        if(find_set(a)!=find_set(b)){
            p[find_set(a)]=find_set(b);
            if(c>r) r=c;
        }
    }
    if(find_set(srce)==find_set(dst)) return r;
    else return -1;
}

int main()
{
    int t,a,b,c,ans,kase=0;
    scanf("%d",&t);
    while(t--){
        E.clear();
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            E.push_back(edge(a,b,c));
        }
        scanf("%d",&dst);
        printf("Case %d:\n",++kase);
        sort(E.begin(),E.end(),con);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) make_set(j);
            srce=i;
            ans=MST();
            if(ans==-1) printf("Impossible\n");
            else printf("%d\n",ans);
        }
    }
    return 0;
}
