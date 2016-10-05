#include<bits/stdc++.h>
using namespace std;
#define M 1810
#define oo 1111111

int cf[M][M],r,c,p,n;
char grid[35][35],ch;

int fx[]={0,0,1,-1};
int fy[]={-1,1,0,0};

struct edge{
    int u,v;
    edge(int a,int b){
        u=a; v=b;
    }
};

vector<edge>E;

void init()
{
    memset(cf,0,sizeof(cf));
    n=r*c;
    E.clear();
}

int level[M],parent[M],taken[M];

int BFS(int srce,int dest)
{
    memset(taken,0,sizeof(taken));
    memset(parent,-1,sizeof(parent));
    int ret=oo,i;
    taken[srce]=1;
    level[srce]=0;
    queue<int>q;
    q.push(srce);
    while(!q.empty()){
        int u=q.front(); q.pop();
        int ucost=level[u];
        for(i=0;i<=2*n+1;i++) if(cf[u][i]>0){
            int v=i;
            if(!taken[v]){
                level[v]=ucost+1;
                parent[v]=u;
                taken[v]=1;
                q.push(v);
            }
        }
    }
    if(taken[dest]==0) return 0;
    int node=dest;
    while(node!=srce){
        E.push_back(edge(parent[node],node));
        node=parent[node];
    }
    for(i=0;i<E.size();i++) ret=min(ret,cf[E[i].u][E[i].v]);
    return ret;
}

int max_flow(int source,int sink)
{
    int totalflow=0,i,j,mini;
    while(1){
        E.clear();
        mini=BFS(source,sink);
        if(mini==0) break;
        totalflow+=mini;
        for(i=0;i<E.size();i++){
            cf[E[i].u][E[i].v]-=mini;
            cf[E[i].v][E[i].u]+=mini;
        }
    }
    return totalflow;
}

int main()
{
    int i,j,k,l,m_in=1,a,b,c,d,s_source,s_sink,ux,uy,ans;
    map<pair<int,int>,int>mp;
    for(i=1;i<=70;i++){
        for(j=1;j<=70;j++) mp[make_pair(i,j)]=m_in++;
    }
    //for(i=1;i<=5;i++){
    //    for(j=1;j<=5;j++) printf(" %d %d --> %d\n",i,j,mp[make_pair(i,j)]);
    //}
    while(scanf("%d%d%d",&r,&c,&p)==3){
        init();
        s_source=0; s_sink=(r*c)+1;
        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                scanf(" %c",&grid[i][j]);
            }
        }
        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                ch=grid[i][j];
                if(ch=='~') continue;
                a=mp[make_pair(i,j)];
                if(ch=='*') cf[s_source][a]=1;
                if(ch=='#') cf[a][s_sink]=11111;
                ux=i; uy=j;
                if(ch=='.'){
                    ux=r*c+i; uy=j;
                    b=mp[make_pair(ux,uy)];
                    cf[a][b]=1;
                }
                a=mp[make_pair(i,j)];
                for(k=0;k<4;k++){
                    int ni=ux+fx[k];
                    int nj=uy+fy[k];
                    if(ni>0 && ni<=r && nj>0 && nj<=c){
                        if(grid[ni][nj]=='~') continue;
                        b=mp[make_pair(ni,nj)];
                        cf[a][b]=1;
                    }
                }
            }
        }
        ans=max_flow(s_source,s_sink);
        cout<<"------------------>";
        printf("%d\n",ans);
    }
    return 0;
}
