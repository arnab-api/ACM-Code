//#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<climits>
#include<cstring>
#include<cstdlib>

#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>

#include<vector>
#include<map>
#include<string>
#include<queue>
#include<set>
#include<iterator>
#include<numeric>
#include<stack>
#include<list>
using namespace std;
#define M 10010

vector<int>adj[M],Costs[M],conn[M];

/// LCA
int P[M][14],T[M],L[M],n,m;
int subSize[M]; /// saves the size of tree with root i
int otherEnd[M]; /// saves the child node of the connection(not the parent)
void DFS(int from,int u,int dep)
{
    T[u] = from;
    L[u] = dep;
    subSize[u] = 1;

    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(v == from) continue;
        otherEnd[conn[u][i]] = v;
        DFS(u,v,dep+1);
        //subSize[u] = max(subSize[u],subSize[v]+1);   /// child tree is a part of parent tree
        subSize[u] += subSize[v]+1;   /// child tree is a part of parent tree
    }
}

/// make peerse table
void LCA_init()
{
    memset(P,-1,sizeof(P));
    int i,j;
    for(i=0; i<n; i++) P[i][0] = T[i];
    for(j=1; (1<<j)<=n; j++)
    {
        for(i=0; i<n; i++)
        {
            if(P[i][j-1]!=-1) P[i][j] = P[P[i][j-1]][j-1];
        }
    }
}

int LCA_query(int x,int y)
{
    int log,i,j;
    if(L[x]<L[y]) swap(x,y);
    /// determine log2(L[x])
    log = 1;
    while(1)
    {
        int next = log+1;
        if((1 << next) > L[x]) break;
        log++;
    }
    /// jump to level the level :)
    for(i=log; i>=0; i--)
    {
        if(L[x] - (1<<i) >= L[y]) x = P[x][i];
    }
    if(x==y) return  x;
    /// eksathe jump
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

/// HLD
int baseArr[M],chainHead[M],chainInd[M],chainNo,ptr,posInBase[M];
void HLD(int curNode, int cost, int prev)
{
    if(chainHead[chainNo] == -1) chainHead[chainNo] = curNode; /// Assign chain head
    chainInd[curNode] = chainNo;
    posInBase[curNode] = ptr; /// Position of this node in baseArr which we will use in Segment tree
    baseArr[ptr++] = cost;  /// assign the cost needed to come to this node from its parent(only this problem)

    int sc = -1, ncost = -1;  /// sc  =  special child (child with maximum grandchild)
    /// Loop to find special child
    for(int i=0; i<adj[curNode].size(); i++)  if(adj[curNode][i] != prev)
        {
            if(sc == -1 || subSize[sc] < subSize[adj[curNode][i]])
            {
                sc = adj[curNode][i];
                ncost = Costs[curNode][i];
            }
        }

    if(sc != -1)
    {
        /// Expand the chain
        HLD(sc, ncost, curNode);
    }

    for(int i=0; i<adj[curNode].size(); i++) if(adj[curNode][i] != prev)
        {
            if(sc != adj[curNode][i])
            {
                /// New chains at each normal node
                chainNo++;
                HLD(adj[curNode][i], Costs[curNode][i], curNode);
            }
        }
}

int tree[4*M];

void build_tree(int node,int b,int e)
{
    if(b == e) {tree[node] = baseArr[b]; return;}
    int left = node*2;
    int right = left+1;
    int mid = (b+e)/2;
    build_tree(left,b,mid);
    build_tree(right,mid+1,e);
    tree[node] = (tree[left] > tree[right]) ? tree[left] : tree[right];
}

int query_max(int node,int b,int e,int l,int r)
{
    if(l>r) swap(l,r);
    if(r<b || l>e) return -1;
    if(b>=l && e<=r) return tree[node];
    int left = node*2;
    int right = left+1;
    int mid = (b+e)/2;
    int p1 = query_max(left,b,mid,l,r);
    int p2 = query_max(right,mid+1,e,l,r);
    return (p1>p2) ? p1 : p2;
}

void update_tree(int node,int b,int e,int pos,int val)
{
    if(pos<b || pos>e) return;
    if(b==pos && b==e) {tree[node] = val ; return;}
    int left = node*2;
    int right = left+1;
    int mid = (b+e)/2;
    update_tree(left,b,mid,pos,val);
    update_tree(right,mid+1,e,pos,val);
    tree[node] = (tree[left] > tree[right]) ? tree[left] : tree[right];
}

int query_up(int u,int v)
{
    if(u==v) return  0; /// obvious case!!
    if(L[u] < L[v]) swap(u,v) ; /// v must be in upper chain
    int vchain = chainInd[v],uchain,ans = -1,tmp;
    while(1){
        int uchain = chainInd[u];
        if(uchain == vchain){
            if(u==v) return ans;
            tmp = query_max(1,1,ptr,posInBase[v]+1,posInBase[u]);  /// posInBase[v]+1 ///
            if(tmp > ans) ans = tmp;
            return ans;
        }
        tmp = query_max(1,1,ptr,posInBase[chainHead[uchain]],posInBase[u]);
        if(tmp > ans) ans = tmp;
        u = chainHead[uchain]; /// move to chainHead
        u = T[u]; ///shift chain
    }
}

int query(int u,int v)
{
    int lca = LCA_query(u,v);
    int p1 = query_up(u,lca);
    int p2 = query_up(v,lca);
    return (p1 > p2) ? p1 : p2;
}

void init(int N)
{
    for(int i=0; i<N; i++)
    {
        adj[i].clear();
        Costs[i].clear();
        conn[i].clear();
        T[i]=-1;

        baseArr[i] = -1;
        chainHead[i] = -1;
        chainInd[i] = -1;
        subSize[i] = -1;
        otherEnd[i] = -1;
        posInBase[i] = -1;
    }
    memset(tree,-1,sizeof(tree));
    ptr = 1; /// my segment tree is 1 based
    chainNo = 1;
}

int main()
{
    int t,a,b,c;
    scanf("%d",&t);
    char QQ[10];
    while(t--)
    {
        scanf("%d",&n);
        init(n+5);
        for(int i=1; i<n; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            a-- ; b--;
            adj[a].push_back(b);
            Costs[a].push_back(c);
            conn[a].push_back(i);

            adj[b].push_back(a);
            Costs[b].push_back(c);
            conn[b].push_back(i);
        }
        //cerr<<" === X ===\n";
        DFS(-1,0,0);
        LCA_init();
        HLD(0,-1,-1);
        build_tree(1,1,ptr);
        //cerr<<" === X ===\n";
        while(scanf(" %s",&QQ)==1){
            if(QQ[0] == 'D') break;
            scanf("%d%d",&a,&b);
            if(QQ[0] == 'C') update_tree(1,1,ptr,posInBase[otherEnd[a]],b);
            else{
                //cerr<<"--------------> ";
                printf("%d\n",query(a-1,b-1));
            }
            //cout<<"--->\n";
        }
        //cerr<<"Yeyyyyy\n";
    }
    return 0;
}

/**
4

3
1 2 1
2 3 2
QUERY 1 2
CHANGE 1 3
QUERY 1 2
DONE

3
1 2 1
2 3 2
QUERY 1 2
CHANGE 1 4
QUERY 1 2
DONE

3
1 2 1
2 3 2
QUERY 1 2
CHANGE 1 2
QUERY 1 2
DONE



*/
