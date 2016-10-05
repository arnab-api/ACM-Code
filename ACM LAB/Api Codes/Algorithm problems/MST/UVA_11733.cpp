#include<bits/stdc++.h>
using namespace std;
#define N 10100

int n,m,A,n_A;
//n=number of nodes
//m=number of edges
struct edge{
    int u,v,w;
    edge(int a,int b,int c){
        u=a; v=b; w=c;
    }
};
vector<edge>E,save;
vector<int>path;
vector<edge> :: iterator it;

bool con(edge a, edge b)
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
    return p[a]=find_set(p[a]);
}

bool frst;
int MST()
{
    int a,b,c,sum=0;
    for(int i=0;i<E.size() && E[i].w<A ; i++){
        a=E[i].u; b=E[i].v; c=E[i].w;
        if(find_set(a)!=find_set(b)){
            p[find_set(a)]=find_set(b);
            sum+=c;
        }
    }
    set<int>st;
    for(int i=1;i<=n;i++) st.insert(find_set(i));
    n_A=st.size();
    sum+=n_A*A;
    return sum;
}

int main()
{
    int t,a,b,c,kase=0,i,j,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&A);
        E.clear();
        save.clear();
        n_A=0;
        for(i=0;i<=n;i++) make_set(i);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            save.push_back(edge(a,b,c));
        }
        sort(save.begin(),save.end(),con);
        for(i=0;i<save.size();i++) E.push_back(save[i]);
        ans=MST();
        int s=n_A;
        printf("Case #%d: ",++kase);
        printf("%d %d\n",ans,s);
    }
    return 0;
}
