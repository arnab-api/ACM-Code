#include<bits/stdc++.h>
using namespace std;
#define M 100100
#define ll long long int

struct Query{
    ll l,r,d,cnt;
};
Query Q[M];

struct info
{
    ll data,prop;
};

info tree[4*M];
ll ara[M],n;

void refresh(ll node,ll b,ll e,ll val)
{
    tree[node].data+=(e-b+1)*val;
    if(b!=e)
    {
        ll left=node*2;
        ll right=node*2+1;
        tree[left].prop+=val;
        tree[right].prop+=val;
    }
    tree[node].prop=0;
}

void init(ll node,ll beg,ll end)
{
    if(beg==end){tree[node].data=ara[beg]; return;}

    ll mid=(beg+end)/2;
    ll left=node*2;
    ll right=left+1;
    init(left,beg,mid);
    init(right,mid+1,end);

    tree[node].data=tree[left].data+tree[right].data;
}


void update(ll node,ll b,ll e,ll i,ll j,ll val)
{
    if(tree[node].prop!=0) refresh(node,b,e,tree[node].prop);
    if(i>e || j<b) return;

    if(i<=b && j>=e)
    {
        refresh(node,b,e,val);
        return;
    }
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;
    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);
    tree[node].data=tree[left].data+tree[right].data;
}

ll query(ll node,ll b,ll e,ll i,ll j)
{
    if(tree[node].prop!=0) refresh(node,b,e,tree[node].prop);
    if(i>e || j<b) return 0;

    if(i<=b && j>=e) return tree[node].data;
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;
    ll p1=query(left,b,mid,i,j);
    ll p2=query(right,mid+1,e,i,j);
    return p1+p2;
}
int arr2[M];
int main()
{
    ll n,m,k,l,r,d,i,j;
    while(scanf("%I64d%I64d%I64d",&n,&m,&k)==3){
        for(i=1;i<=n;i++) scanf("%I64d",&ara[i]);
        init(1,1,n);
        for(i=1;i<=m;i++){
            scanf("%I64d%I64d%I64d",&l,&r,&d);
            Q[i].l=l;
            Q[i].r=r;
            Q[i].d=d;
            Q[i].cnt=0;
        }
        memset(arr2,0,sizeof(arr2));
        for(i=1;i<=k;i++){
            scanf("%I64d%I64d",&l,&r);
            arr2[l]++; arr2[r+1]--;
        }
        for(i=1;i<=m;i++){
            arr2[i]+=arr2[i-1];
            Q[i].cnt=arr2[i];
        }
        for(i=1;i<=m;i++) update(1,1,n,Q[i].l,Q[i].r,Q[i].d*Q[i].cnt);
        for(i=1;i<n;i++) printf("%I64d ",query(1,1,n,i,i));
        printf("%I64d\n",query(1,1,n,n,n));
    }
    return 0;
}
