#include<bits/stdc++.h>
using namespace std;
#define M 100100

vector<int>E[M];
int n,e,low[M],dfn[M],parent[M],depth,BCCcnt,api[M];
struct edge{
    int u,v;
    edge(){}
    edge(int a,int b){
        u = a;
        v = b;
    }
};

stack<edge>st;

void init()
{
    for(int i=0;i<M;i++){
        E[i].clear();
        parent[i]=-1;
        low[i]=-1;
        dfn[i]=-1;
        api[i]=0;
    }
    while(!st.empty()) st.pop();
    depth=0;
    BCCcnt=0;
}

void tarjanBCC(int u)
{
    low[u] = dfn[u] = depth++;
    int children = 0;
    for(int i=0;i<E[u].size();i++){
        int v = E[u][i];
        if(dfn[v]==-1){
            parent[v]=u;
            children++;
            st.push(edge(u,v));
            tarjanBCC(v);
            low[u] = min(low[u],low[v]);
            if((parent[u]==-1 && children>1) || (parent[u]!=-1 && low[v]>=dfn[u])){
                /// articulation point found!!!
                api[u]=1;
                while(st.top().u!=u || st.top().v!=v){
                    printf("(%d--%d) ",st.top().u,st.top().v);
                    st.pop();
                }
                printf("(%d--%d)\n",st.top().u,st.top().v);
                st.pop();
                BCCcnt++;
            }
        }
        else if(v!=parent[u] && dfn[v] < low[u]){
            low[u] = dfn[v];
            st.push(edge(u,v));
        }
    }
}

void find_BCC()
{
    int i;
    for(i=0;i<n;i++){
        if(dfn[i]==-1) tarjanBCC(i);
        if(!st.empty()){
            while(!st.empty()){
                printf("(%d--%d) ",st.top().u,st.top().v);
                st.pop();
            }
            printf("\n");
            BCCcnt++;
        }
    }
}

int main()
{
    int i,j,k,l,u,v;
    while(scanf("%d%d",&n,&e)==2){
        init();
        for(i=0;i<e;i++){
            scanf("%d%d",&u,&v);
            E[u].push_back(v);
            E[v].push_back(u);
        }
        find_BCC();
        for(i=0;i<n;i++) printf("%d(%d)\n",i,api[i]);
    }
    return 0;
}
/**
12 14
4 2
4 3
2 3
2 1
3 1
1 5
5 7
7 8
5 8
8 9
1 0
0 6
5 6
10 11
**/
