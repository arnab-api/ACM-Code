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
#define M 100100

struct edge{
    int to,prev,cost;
};
edge Ed[3*M];
int D[M],last[M],edge;

void addEdge(int u,int v,int w)
{
    Ed[edge].to=v;
    Ed[edge].prev=last[u];
    Ed[edge].cost=w;
    last[u]=edge++;

    Ed[edge].to=u;
    Ed[edge].prev=last[v];
    Ed[edge].cost=w;
    last[v]=edge++;
}

void init()
{
    edge=0;
    memset(last,-1,sizeof(last));
    memset(Ed,-1,sizeof(Ed));
    memset(D,-1,sizeof(D));
}

void BFS(int srce)
{
    queue<int>q;
    q.push(srce);
    D[srce]=0;
    while(!q.empty())
    {
        int u=q.front(); q.pop();
        int ucost=D[u];
        for(int i=last[u];i>-1;i=Ed[i].prev){
            int v=Ed[i].to;
            if(D[v]==-1){
                D[v]=ucost^Ed[i].cost;
                q.push(v);
            }
        }
    }
}

struct node
{
    int right,left;
    //bool found;
};

node trie[35*M];
int t_in,root;

void Insert(int N)
{
    int cur=root;
    for(int i=32;i>=0;i--){
        int id = (N>>i) & 1;
        if(id) {
            if(trie[cur].right == 0) trie[cur].right=++t_in;
            cur=trie[cur].right;
        }
        else {
            if(trie[cur].left == 0) trie[cur].left=++t_in;
            cur=trie[cur].left;
        }
    }
}

int Search(int N)
{
    int cur=root;
    int num=0;
    for(int i=32;i>=0;i--){
        int id = (N>>i) & 1;
        num<<=1;
        if(id){
            if(trie[cur].left!=0){
                cur=trie[cur].left;
            }
            else{
                cur=trie[cur].right;
                num+=1;
            }
        }
        else{
            if(trie[cur].right!=NULL){
                cur=trie[cur].right;
                num+1;
            }
            else{
                cur=trie[cur].left;
            }
        }
    }
    return N^num;
}

int main()
{
    int n,m,a,b,c,ans,i;
    while(scanf("%d",&n)==1){
        m=n-1;
        init();
        memset(trie,0,sizeof(trie));
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            addEdge(a,b,c);
        }
        BFS(0);
        root=1;
        t_in=1;
        ans=0;
        Insert(0);
        for(i=0;i<n;i++) {
            Insert(D[i]);
            //cout<<"--->"<<D[i]<<endl;
            //ans=max(ans,Search(D[i]));
        }
        for(i=0;i<n;i++) ans=max(ans,Search(D[i]));
        //cerr<<"-------------------->";
        printf("%d\n",ans);
    }
    return 0;
}
/**
4
0 1 0
1 2 1
1 3 2
**/

