#include<bits/stdc++.h>
using namespace std;
#define M 100010
#define ll long long int

struct info
{
    ll data,prop;
};

info tree[M*3];
ll ara[M];

void init(ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node].data=ara[b];
        return;
    }
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].data=tree[left].data+tree[right].data;
}

void update(ll node,ll b,ll e,ll i,ll j,ll x)
{
    if(i>e || j<b) return;
    if(b>=i && e<=j)
    {
        tree[node].data+=(e-b+1)*x;
        tree[node].prop+=x;
        return;
    }
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].data=tree[left].data+tree[right].data+(e-b+1)*tree[node].prop;
}

ll query(ll node,ll b,ll e,ll i,ll j,ll carry=0)
{
    if(i>e || j<b) return 0;
    if(b>=i && e<=j) return tree[node].data+(e-b+1)*carry;
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;
    ll p1=query(left,b,mid,i,j,carry+tree[node].prop);
    ll p2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return p1+p2;
}

int main()
{
    ll i,t,n,c,p,q,v,dit;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&c);
        //for(i=1;i<=n;i++) ara[i]=0;
        for(i=0;i<3*M;i++){
            tree[i].data=0;
            tree[i].prop=0;
        }
        //init(1,1,n);
        while(c--){
            scanf("%lld",&dit);
            if(dit==0){
                scanf("%lld%lld%lld",&p,&q,&v);
                update(1,1,n,p,q,v);
            }
            else if(dit==1){
                scanf("%lld%lld",&p,&q);
                printf("%lld\n",query(1,1,n,p,q,0));
            }
        }
    }
    return 0;
}
