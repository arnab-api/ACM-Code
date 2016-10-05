#include<bits/stdc++.h>
using namespace std;
#define M 100110

int tree[3*M+50],ara[M],n,C[M];

void init(int node,int b,int e)
{
    if(b==e){
        tree[node]=C[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}

void update(int node,int b,int e,int pos,int val)
{
    if(e<pos || b>pos) return;
    if(b==e && b==pos){ tree[node]=val; return;}
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,pos,val);
    update(right,mid+1,e,pos,val);
    tree[node]=tree[left]+tree[right];
}

int query(int node,int b,int e,int i,int j)
{
    if(b>=i && e<=j) return tree[node];
    if(b>j || e<i) return 0;
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}

int find_val(int node,int b,int e,int x)
{
    if(tree[node]==x && b==e) return b;
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    if(tree[left]>=x) return find_val(left,b,mid,x);
    else return find_val(right,mid+1,e,x-tree[left]);
}

int main()
{
    int t,n,ans,i,a,kase=0,b,in[M];
    for(i=1;i<M;i++) ara[i]=i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(C,0,sizeof(C));
        for(i=1;i<=n;i++) C[i]=1;
        init(1,1,M);
        //cout<<tree[1]<<" "<<query(1,1,M,1,M)<<endl;;
        for(i=1;i<=n;i++) scanf("%d",&in[i]);
        for(i=n;i>1;i--){
            a=in[i];
            if(i-a>query(1,1,M,1,M)) continue;
            b=find_val(1,1,M,i-a);
            //cout<<i-a<<" "<<b<<" "<<query(1,1,M,1,M)<<endl;
            if(b<=query(1,1,M,1,M)) update(1,1,M,b,0);
        }
        b=find_val(1,1,M,1);
        printf("Case %d: %d\n",++kase,ara[b]);
    }
    return 0;
}

/*
3

3

0 1 2

3

0 1 0
*/
