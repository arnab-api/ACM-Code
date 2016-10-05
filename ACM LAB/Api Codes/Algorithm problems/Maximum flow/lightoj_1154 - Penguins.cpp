#include<bits/stdc++.h>
using namespace std;
#define M 222
#define oo 111111111

struct pos
{
    double x,y;
    pos(double a,double b)
    {
        x=a;
        y=b;
    }
};

vector<pos>V;
vector<int>ans;

int CF[M][M],cap[M][M];

/// N th node is considered SUPER SOURCE

double calcDIS(pos A,pos B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

struct edge{
    int u,v;
    edge(int a,int b){
        u=a; v=b;
    }
};
vector<edge>E;
int level[M],parent[M],taken[M];

void init()
{
    V.clear();
    ans.clear();
    E.clear();
    memset(cap,0,sizeof(cap));
}

int BFS(int n,int srce,int dest)
{
    //printf("===========================>>>>>>>> %d %d %d\n",n,srce,dest);
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
        for(i=0;i<=2*n+1;i++) if(CF[u][i]>0){
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
    for(i=0;i<E.size();i++) ret=min(ret,CF[E[i].u][E[i].v]);
    return ret;
}

int MAX_flow(int n,int source,int sink)
{
    int totalflow=0,i,j,mini;
    for(i=0;i<=2*n+1;i++){
        for(j=0;j<=2*n+1;j++) CF[i][j]=cap[i][j];
    }
    while(1){
        E.clear();
        mini=BFS(n,source,sink);
        if(mini==0) break;
        totalflow+=mini;
        for(i=0;i<E.size();i++){
            //printf("****====> %d %d %d\n",E[i].u,E[i].v,CF[E[i].u][E[i].v]);
            CF[E[i].u][E[i].v]-=mini;
            CF[E[i].v][E[i].u]+=mini;
        }
        //cout<<">>>>>>>>>>>>>>>"<<mini<<endl;
    }
    return totalflow;
}

int main()
{
    int N,sum,i,j,n,m,t,kase=0;
    double x,y,d,D;
    scanf("%d",&t);
    while(t--)
    {
        init();
        sum=0;
        scanf("%d %lf",&N,&D);
        for(i=0; i<N; i++)
        {
            scanf("%lf%lf",&x,&y);
            V.push_back(pos(x,y));
            scanf("%d%d",&n,&m);
            sum+=n;
            cap[N][i]=n;
            cap[N+1+i][N]=n;
            cap[i][N+1+i]=m;
            cap[N+1+i][i]=m;
        }
        for(i=0;i<N;i++){
            for(j=i+1;j<N;j++){
                d=calcDIS(V[i],V[j]);
                if(d<=D){
                    //printf("---->%d %d %lf %d %d\n",i,j,d,N+1+i,N+1+j);
                    cap[N+1+i][j]=INT_MAX;
                    cap[N+1+j][i]=INT_MAX;
                }
            }
        }
        /*for(i=0;i<=2*N+1;i++){
            printf("%d -->",i);
            for(j=0;j<=2*N+1;j++){
                printf("%4d",cap[i][j]);
            }
            printf("\n");
        }*/
        for(i=0;i<N;i++){
            int mf=MAX_flow(N,N,i);
            //cout<<"=============>>>>>>>>>>---------->"<<mf<<endl;
            if(mf==sum) ans.push_back(i);
        }
        //cerr<<"-------------------->";
        printf("Case %d: ",++kase);
        if(ans.empty()) printf("-1");
        else{
            for(i=0;i<ans.size();i++){
                if(i) printf(" ");
                printf("%d",ans[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
