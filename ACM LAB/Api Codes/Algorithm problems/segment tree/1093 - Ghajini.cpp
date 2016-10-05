#include<bits/stdc++.h>
using namespace std;
#define M 100100
#define oo INT_MAX
#define _oo -INT_MAX

struct info{
    int mini,maxi;
    int prop;
};

info tree[4*M];
int ara[M];

void init(int node,int b,int e)
{
    if(b==e){
        tree[node].mini=ara[b];
        tree[node].maxi=ara[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].mini=min(tree[left].mini,tree[right].mini);
    tree[node].maxi=max(tree[left].maxi,tree[right].maxi);
}

int query_min(int node,int b,int e,int i,int j)
{
    if(i>e || j<b) return oo;
    if(i<=b && j>=e) return tree[node].mini;
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query_min(left,b,mid,i,j);
    int p2=query_min(right,mid+1,e,i,j);
    return min(p1,p2);
}

int query_max(int node,int b,int e,int i,int j)
{
    if(i>e || j<b) return _oo;
    if(i<=b && j>=e) return tree[node].maxi;
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query_max(left,b,mid,i,j);
    int p2=query_max(right,mid+1,e,i,j);
    return max(p1,p2);
}

int main()
{
    int n,i,j,d,t,kase=0,n_c;
    scanf("%d",&n_c);
    while(n_c--){
        scanf("%d%d",&n,&d);
        for(i=1;i<=n;i++) scanf("%d",&ara[i]);
        init(1,1,n);
        //for(i=1;i<20;i++)printf("%d--> max=%d & min=%d\n",i,tree[i].maxi,tree[i].mini);
        //while(scanf("%d%d",&i,&j)) printf("min=%d & max=%d\n",query_min(1,1,n,i,j),query_max(1,1,n,i,j));
        int max_diff=0;
        for(i=1;i<=n-d+1;i++){
            t=query_max(1,1,n,i,i+d-1)-query_min(1,1,n,i,i+d-1);
            if(t>max_diff) max_diff=t;
        }
        printf("Case %d: %d\n",++kase,max_diff);
    }
    return 0;
}
