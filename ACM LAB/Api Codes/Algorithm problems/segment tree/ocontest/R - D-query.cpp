#include<bits/stdc++.h>
using namespace std;
#define M 30100

int tree[3*M],ara[M],last[1000100],next[M];

struct Query{
    int from,to,next,ans;
};

Query Q[200100];

void init(int node,int b,int e)
{
    if(b==e) tree[node]=ara[b];
    int mid=(b+e)/2;
    int left=node*2;
    int right=node*2+1;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}

int query(int node,int b,int e,int from,int to)
{
    if(b>to || e<from) return 0;
    if(b>=from && e<=to) return tree[node];
    int mid=(b+e)/2;
    int left=node*2;
    int right=node*2+1;
    int p1=query(left,b,mid,from,to);
    int p2=query(right,mid+1,e,from,to);
    return p1+p2;
}

void update(int node,int b,int e,int p,int newval)
{
    if(b>p || e<p) return;
    if(b>=p && e<=p) {tree[node]+=newval; return;}
    int mid=(b+e)/2;
    int left=node*2;
    int right=node*2+1;
    update(left,b,mid,p,newval);
    update(right,mid+1,e,p,newval);
    tree[node]=tree[left]+tree[right];
}

int main()
{
    int n,q,i,j,from,to,x;
    while(scanf("%d",&n)==1){
        memset(tree,0,sizeof(tree));
        memset(last,-1,sizeof(last));
        memset(next,-1,sizeof(next));
        for(i=1;i<=n;i++) scanf("%d",&ara[i]);
        scanf("%d",&q);
        for(i=1;i<=q;i++){
            scanf("%d%d",&Q[i].from,&Q[i].to);
            Q[i].next=next[Q[i].to];
            next[Q[i].to]=i;
        }
        //for(i=1;i<=q;i++) printf("-->%d %d %d\n",Q[i].from,Q[i].to,Q[i].next);
        for(i=1;i<=n;i++){
            x=ara[i];
            if(last[x]!=-1) update(1,1,n,last[x],-1);
            last[x]=i;
            update(1,1,n,i,1);
            for(j=next[i];j!=-1;j=Q[j].next) {
                //printf("--->%d %d\n",Q[j].from,Q[j].to);
                Q[j].ans=query(1,1,n,Q[j].from,Q[j].to);
            }
        }
        for(i=1;i<=q;i++) printf("%d\n",Q[i].ans);
    }
    return 0;
}
/*
10
1 7 3 6 1 7 6 3 5 2
5
9 10
2 5
4 8
1 5
8 9
*/
