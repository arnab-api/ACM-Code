#include<bits/stdc++.h>
using namespace std;
#define M 111

int flag[M],par[M],Big[M],dis[M],level[M];
vector<int>E[M];

int N,D;

void init(int lim)
{
    for(int i=0;i<lim;i++){
        E[i].clear();
        par[i]=-1;
        flag[i]=0;
    }
}

bool BFS(int srce,int dest)
{
    queue<int>q;
    memset(level,0,sizeof(level));
    memset(par,-1,sizeof(par));
    level[srce]=1;
    q.push(srce);
    while(!q.empty()){
        int u=q.front(); q.pop();
        int ucost=level[u];
        for(int i=0;i<E[u].size();i++){
            int v=E[u][i];
            if(flag[v]) continue;
            if(level[v]==0){
                level[v]=ucost+1;
                par[v]=u;
                q.push(v);
            }
        }
    }
    if(level[dest]>0) return true;
    return false;
}

void Build_graph(int d)
{
    init(N+5);
    int srce=0,des=N+1,j;
    for(int i=srce;i<=des;i++){
        j=i-1;
        while(j>=srce){
            if(dis[i]-dis[j]<=d) {
                E[i].push_back(j);
                j--;
            }
            else break;
        }
        j=i+1;
        while(j<=des){
            if(dis[j]-dis[i]<=d) {
                E[i].push_back(j);
                j++;
            }
            else break;
        }
    }
}

bool call(int srce,int dest,int mid)
{
    Build_graph(mid);
    bool fl=BFS(srce,dest);
    if(fl==false) return false;
    int node=dest;
    while(node!=-1){
        //cout<<"----->"<<node<<endl;
        if(!Big[node]) flag[node]=1;
        node=par[node];
    }
    fl=BFS(srce,dest);
    return fl;
}

int Bin_search()
{
    int lo=0,hi=D,mid,ans;
    bool fl;
    while(lo<=hi){
        mid=(lo+hi)/2;
        //printf("===>%d %d %d\n",lo,mid,hi);
        fl=call(0,N+1,mid);
        if(fl) {
            ans=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    return ans;
}

int main()
{
    int t,i,j,k,l,in,d,kase=0,ans;
    scanf("%d",&t);
    char ch;
    while(t--){
        scanf("%d%d",&N,&D);
        in=0;
        Big[0]=1;
        dis[0]=0;
        for(i=1;i<=N;i++){
            scanf(" %c",&ch);
            getchar();
            scanf("%d",&d);
            if(ch=='B') Big[i]=1;
            else Big[i]=0;
            dis[i]=d;
        }
        Big[N+1]=1;
        dis[N+1]=D;

        /*for(i=0;i<=N+1;i++) printf("%5d",flag[i]);
        printf("\n");
        for(i=0;i<=N+1;i++) printf("%5d",Big[i]);
        printf("\n");
        for(i=0;i<=N+1;i++) printf("%5d",dis[i]);
        printf("\n");*/

        ans=Bin_search();
        //cerr<<"---------------->";
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}
