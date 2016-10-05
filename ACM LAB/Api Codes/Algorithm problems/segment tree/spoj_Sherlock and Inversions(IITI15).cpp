#include<bits/stdc++.h>
using namespace std;
#define M 20200

int ara[M],mp[M],tree[65537],out[M],sq,n,val;

/*void init(int node,int b,int e)
{
    if(b==e) {tree[node]=ara[b]; return;}
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}*/

void update(int node,int b,int e,int p,int newval)
{
    if(b>p || e<p) return;
    if(b>=p && e<=p) {tree[node]+=newval; return;}
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,p,newval);
    update(right,mid+1,e,p,newval);
    tree[node]=tree[left]+tree[right];
}

int query(int node,int b,int e,int i,int j)
{
    if(b>j || e<i || i>j) return 0;
    if(b>=i && e<=j) return tree[node];
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}

struct Query{
    int l,r,index;
    bool operator < (const Query & p) const{
        if((l/sq) == (p.l/sq)) return (r/sq) < (p.r/sq);
        return (l/sq) < (p.l/sq);
    }
};

Query Q[M];

void Add(int pos,int l,int r)
{
    update(1,1,n,ara[pos],1);
    val+=query(1,1,n,l,r);
}

void Remove(int pos,int l,int r)
{
    update(1,1,n,ara[pos],-1);
    val-=query(1,1,n,l,r);
}

int main()
{
    int q,l,r,i,j,lp,rp;
    while(scanf("%d",&n)==1){
        for(i=1;i<=n;i++) {
            scanf("%d",&ara[i]);
            mp[i]=ara[i];
        }
        //for(i=1;i<=n;i++) printf("%d ",ara[i]);
        //printf("\n");
        sort(mp+1,mp+n+1);
        for(i=1;i<=n;i++) ara[i]=lower_bound(mp+1,mp+n+1,ara[i])-mp;
        //for(i=1;i<=n;i++) printf("%d ",ara[i]);
        //printf("\n");
        memset(tree,0,sizeof(tree));

        sq=(int)sqrt(n);
        if(sq*sq<n) sq++;
        scanf("%d",&q);
        for(i=1;i<=q;i++){
            scanf("%d%d",&l,&r);
            Q[i].l=l;
            Q[i].r=r;
            Q[i].index=i;
        }
        sort(Q+1,Q+q+1);
        val=0;
        lp=1; rp=0;
        for(i=1;i<=q;i++){
            while(lp<Q[i].l){
                Remove(lp,1,ara[lp]-1);
                lp++;
            }
            while(lp>Q[i].l){
                lp--;
                Add(lp,1,ara[lp]-1);
            }
            while(rp<Q[i].r){
                rp++;
                Add(rp,ara[rp]+1,n);
            }
            while(rp>Q[i].r){
                Remove(rp,ara[rp]+1,n);
                rp--;
            }
            out[Q[i].index]=val;
        }
        for(i=1;i<=q;i++) printf("%d\n",out[i]);

    }
    return 0;
}
