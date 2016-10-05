#include<bits/stdc++.h>
using namespace std;
#define M 5050

vector<int>G[M];
int T[M],P[M][22],L[M];

void init()
{
    for(int i=0; i<M; i++)
    {
        G[i].clear();
        T[i]=-1;
        L[i]=-1;
    }
}

void DFS(int from,int u,int dep)
{
    T[u]=from;
    L[u]=dep;
    for(int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        if(v==from) continue;
        DFS(u,v,dep+1);
    }
}

void LCA_init(int N)
{
    memset(P,-1,sizeof(P));
    int i,j;
    for(i=0; i<N; i++) P[i][0]=T[i];
    for(j=1; (1<<j)<N; j++)
    {
        for(i=0; i<N; i++)
        {
            if(P[i][j-1]==-1) continue;
            P[i][j]=P[P[i][j-1]][j-1];
        }
    }
}

int LCA_query(int N,int x,int y)
{
    if(L[x]<L[y]) swap(x,y);
    int log=1,next,i,j;
    while(1)
    {
        next=log+1;
        if((1<<log) > L[x]) break;
        log++;
    }
    for(i=log; i>=0; i--)
    {
        if(L[x]-(1<<i)>=L[y]) x=P[x][i];
    }
    if(x==y) return x;
    for(i=log; i>=0; i--)
    {
        if(P[x][i]!=-1 && P[x][i]!=P[y][i])
        {
            x=P[x][i];
            y=P[y][i];
        }
    }
    return T[x];
}

int find_pos(int k,int a,int b,int lca)
{
    int llv=L[a]-L[lca]+1,node,cnt,ans;
    //cerr<<"===============>";
    if(k==llv) ans=lca;
    else if(k<llv)
    {
        node=a;
        cnt=1;
        while(1)
        {
            if(cnt==k) break;
            node=T[node];
            cnt++;
        }
        ans=node;
    }
    else
    {
        k=L[a]-L[lca]+L[b]-L[lca]+1-k+1;
        node=b;
        cnt=1;
        while(1)
        {
            if(cnt==k) break;
            node=T[node];
            cnt++;
        }
        ans=node;
    }
    return ans+1;
}

int main()
{
    int n,q,a,b,m,lca,i,j,d,node,cnt,x,y;
    while(scanf("%d",&n)==1)
    {
        if(n==0) break;
        m=n-1;
        init();
        while(m--)
        {
            scanf("%d%d",&a,&b);
            a--;
            b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        DFS(0,0,0);
        LCA_init(n);
        /*for(i=0; i<n; i++)
        {
            printf("%d(%d) --> ",i,L[i]);
            for(j=0; j<6; j++) printf("%4d",P[i][j]);
            printf("\n");
        }*/
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d",&a,&b);
            a--;
            b--;
            lca=LCA_query(n,a,b);
            //cout<<"----------------->";
            //printf("%d\n",lca);
            d=L[a]-L[lca]+L[b]-L[lca]+1;
            //cout<<d<<endl;
            if(d%2==0)
            {
                d=d/2;
                cnt=1;
                x=find_pos(d,a,b,lca);
                y=find_pos(d,b,a,lca);
                if(x>y) swap(x,y);
                printf("The fleas jump forever between %d and %d.\n",x,y);
            }
            else{
                d=(d/2)+1;
                x=find_pos(d,a,b,lca);
                printf("The fleas meet at %d.\n",x);
            }
        }
    }
    return  0;
}
