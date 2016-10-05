#include<bits/stdc++.h>
using namespace std;
#define N 510
int n,m;
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
bool con2(edge a,edge b)
{
    return a.w>b.w;
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
        a=E[i].u; b=E[i].v; c=E[i].w;
        if(find_set(a)!=find_set(b)){
            p[find_set(a)]=find_set(b);
            r+=c;
        }
    }
    return r;
}

int main()
{
    int t,a,b,c,ans1,ans2,ans,kase=0;
    scanf("%d",&t);
    while(t--){
        E.clear();
        scanf("%d",&n);
        while(1){
            scanf("%d%d%d",&a,&b,&c);
            if(a==0 && b==0 && c==0) break;
            E.push_back(edge(a,b,c));
        }
        printf("Case %d: ",++kase);
        sort(E.begin(),E.end(),con);
        //printf("==>\n");
        //for(int i=0;i<E.size();i++) printf("%d %d %d\n",E[i].u,E[i].v,E[i].w);
        for(int i=0;i<=n;i++) make_set(i);
        ans1=MST();
        sort(E.begin(),E.end(),con2);
        //printf("==>\n");
        //for(int i=0;i<E.size();i++) printf("%d %d %d\n",E[i].u,E[i].v,E[i].w);
        for(int i=0;i<=n;i++) make_set(i);
        ans2=MST();
        ans=ans1+ans2;
        if(ans%2==0) printf("%d\n",ans/2);
        else printf("%d/2\n",ans);
    }
    return 0;
}

