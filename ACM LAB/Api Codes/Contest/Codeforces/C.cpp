#include<bits/stdc++.h>
using namespace std;
#define MAX 100000+7
#define ll long long int
#define oo 10010010010010

struct info
{
    ll data,prop;
    info(){
        data = 0;
        prop = 0;
    }
};

info tree[4*MAX];
ll arr[MAX],n;

void refresh(ll node,ll b,ll e,ll val)
{
    tree[node].data += val;
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
    //if(i>j) return;
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
    //tree[node].data=tree[left].data+tree[right].data;
    //tree[node].data = max(tree[left].data,tree[right].data);
    if(tree[left].data > tree[right].data) tree[node] = tree[left];
    else tree[node] = tree[right];
}

void build_tree()
{
    for(int i=1;i<=n;i++) update(1,1,n,i,i,arr[i]);
}

ll query(ll node,ll b,ll e,ll i,ll j)
{
    //if(i>j) return -oo;
    if(tree[node].prop!=0) refresh(node,b,e,tree[node].prop);
    if(i>e || j<b) return 0;

    if(i<=b && j>=e) return tree[node].data;
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;
    ll p1=query(left,b,mid,i,j);
    ll p2=query(right,mid+1,e,i,j);
    return max(p1,p2);
}


int main()
{
    ll q,err,ans;
    set<ll>st;
    set<ll> :: iterator it;
    while(scanf("%lld",&n)==1){
        memset(tree,0,sizeof(tree));
        for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
        for(int i=2;i<=n;i++) arr[i] += arr[i-1];
        build_tree();
        q = n;
        while(q--){
            scanf("%lld",&err);
            it = st.upper_bound(err);
            ll beg = err+1;
            ll end;
            if(it == st.end()) end = n;
            else end = *it - 1;
            //printf(">>>>> %lld -----> %lld\n",beg,end);
            st.insert(err);
            ll getval = query(1,1,n,err,err);
            update(1,1,n,err,err,-oo);
            update(1,1,n,beg,end,-getval);
            ans = query(1,1,n,1,n);
            //for(ll i=1;i<=n;i++) printf("(%lld)%lld ",i,query(1,1,n,i,i));
            //cerr<<"------------------------------------------>>> ";
            if(q) printf("%lld\n",ans);
            else printf("0\n");
        }
    }
    return 0;
}
