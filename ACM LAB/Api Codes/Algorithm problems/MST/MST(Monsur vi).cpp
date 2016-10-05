

#include<bits/stdc++.h>

#define inf 0x7fffffff
#define ll long long
#define fs first
#define sc second
#define oo (1<<30)
#define SZ(x) (int)x.size()
#define re(i,a,b) for(int i=a;i<b;i++)
#define gint(n) scanf("%d",&n)
#define clr(a,n) (memset(a,n,sizeof(a)))
#define msv(a,v,n) for(int _a;_a<=n;_a++) a[_a]=v;
#define all(res) res.begin(),res.end()
#define mp(a,b) (make_pair(a,b))
#define pb(n) push_back(n)
#define loop1(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define mod 100007
#define N 1000100

using namespace std;

typedef vector< int> VI;
typedef vector< vector<int> > VVI;
typedef pair< int, int> PII;
typedef map< string, int> MSI;

int m,n,P[N],R[N];
struct dataT
{
    int to, w;
    dataT(int a, int b)
    {
        to=a, w=b;
    }
};
vector<dataT>v[N];
struct edge
{
    int u,v,w;
    edge(int a, int b, int c)
    {
        u=a, v=b, w=c;
    }
};
vector<edge>E;
bool com(edge a, edge b)
{
    return a.w<b.w;
}
void make_set(int a)
{
    P[a]=a;
    R[a]=0;
    return;
}
int find_set(int a)
{
    if(P[a]==a) return a;
    return find_set(P[a]);
}
int T[N];
void link(int a, int b)
{
    if(R[a]==R[b]) R[a]++,T[b]=a;
    if(R[a]>R[b]) T[b]=a;
    else T[a]=b;
}
void Union(int &a, int &b)
{
    link(a=find_set(a),b=find_set(b));
    return;
}
int mst()
{
    re(i,0,n) make_set(i),v[i].clear();
    sort(all(E),com);
    int sum=0;
    re(i,0,n+2)
    {
        int a=E[i].u, b=E[i].v, c=E[i].w;
        if(find_set(a)!=find_set(b))
        {
            printf("%d %d %d\n",a,b,c);
            Union(a,b);
            P[a]=b;
            printf("%d %d %d\n",a,b,c);
            //v[a].pb(dataT(b,c));
            //v[b].pb(dataT(a,c));
            printf("==>");
            for(int i=1;i<=m;i++) printf("%d ",find_set(i));
            printf("\n");
            sum+=c;
        }
    }
    return sum;
}
int main()
{
    int a,b,c,sum,ans;
    while(scanf("%d%d",&m,&n)==2 && (m+n))
    {
        E.clear();
        sum=0;
        re(i,0,n)
        {
            scanf("%d%d%d",&a,&b,&c);
            E.pb(edge(a,b,c));
            E.pb(edge(b,a,c));

            sum+=c;
        }

        ans=mst();


        printf("%d\n",ans);
        int vis[m+3],cnt=0,pass=4,q;
        for(int i=0;i<m+3;i++) vis[i]=0;
        /*for(int i=1;i<=m;i++){
            printf("\n==>%d \n",i);
            for(int j=0;j<v[i].size();j++) printf("%d \n",v[i][j].to);
        }*/
        //printf("==>%d ",pass);
        //vis[pass]=1;
        /*while(cnt!=m-1){
            for(int j=0;j<v[pass].size();j++){
                q=v[pass][j].to;
                if(!vis[q]){
                    printf("%d ",q);
                    vis[q]=1;
                    cnt++;
                    pass=q;
                    break;
                }
            }
        }*/
        printf("\n");
    }
    return 0;
}





