#include<bits/stdc++.h>
using namespace std;
#define M 100100

int ara[M],tree[3*M];

void init(int node,int b,int e)
{
    if(b==e) {tree[node]=ara[b];return;}
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
}

int query(int node,int b,int e,int i,int j)
{
    if(b>j || e<i ) return INT_MAX;
    if(b>=i && e<=j) return tree[node];
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return min(p1,p2);
}

int main()
{
    int t,n,q,i,j,a,b,kase=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++) scanf("%d",&ara[i]);
        init(1,1,n);
        printf("Case %d:\n",++kase);
        while(q--){
            scanf("%d%d",&a,&b);
            //cerr<<"--------------->";
            printf("%d\n",query(1,1,n,a,b));
        }
    }
    return 0;
}
