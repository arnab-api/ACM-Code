#include<bits/stdc++.h>
using namespace std;
#define M 100100
#define ll long long int

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

int main()
{
    //freopen("0file.txt","r",stdin);
    ll i,t,n,c,p,q,v,dit,kase=0;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&c);
        for(i=1;i<=n;i++) ara[i]=0;
        for(i=0; i<4*M; i++)
        {
            tree[i].data=0;
            tree[i].prop=0;
        }
        printf("Case %lld:\n",++kase);
        while(c--)
        {
            scanf("%lld",&dit);
            if(dit==0)
            {
                scanf("%lld%lld%lld",&p,&q,&v);
                update(1,1,n,p+1,q+1,v);
                for(i=0;i<3*n;i++) if(tree[i].prop!=0) cout<<"-->"<<i<<"==>"<<tree[i].prop<<endl;
            }
            else if(dit==1)
            {
                scanf("%lld%lld",&p,&q);
                cout<<"==========================>";
                printf("%lld\n",query(1,1,n,p+1,q+1));
            }
        }
    }
    return 0;
}
