#include<bits/stdc++.h>
using namespace std;
#define M 5050
#define lli long long int
#define oo (1<<30)

lli n;

struct data{
    lli val,pos;
    data(){}
    data(lli v,lli i){
        val=v; pos=i;
    }
    bool operator < (const data & p) const{
        return val < p.val;
    }
};

data ara[M],tree[4*M];

void init(lli node,lli b,lli e)
{
    if(b>e) return;
    if(b==e){
        tree[node]=ara[b];
        return;
    }
    lli mid=(b+e)/2;
    lli Left=node*2;
    lli Right=Left+1;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node]=min(tree[Left],tree[Right]);
}

data query(lli node,lli b,lli e,lli i,lli j)
{
    if(i>e || j<b) return data(oo,-1);
    if(i<=b && j>=e) return tree[node];
    lli mid=(b+e)/2;
    lli Left=node*2;
    lli Right=Left+1;
    data q1=query(Left,b,mid,i,j);
    data q2=query(Right,mid+1,e,i,j);
    return min(q1,q2);
}

lli RMQ(lli lo,lli hi,lli mn)
{
    if(lo>hi) return 0;
    lli ver=hi-lo+1;
    data r_min=query(1,1,n,lo,hi);
    lli hor=r_min.val-mn+RMQ(lo,r_min.pos-1,r_min.val)+RMQ(r_min.pos+1,hi,r_min.val);
    return min(ver,hor);
}

int main()
{
    lli i,a,b;
    while(scanf("%lld",&n)==1){
        for(i=1;i<=n;i++) {
            scanf("%lld",&a);
            ara[i]=data(a,i);
        }
        memset(tree,-1,sizeof(tree));
        init(1,1,n);
        printf("%lld\n",RMQ(1,n,0));
    }
    return 0;
}
/**
8
3 4 3 3 3 3 3 2
**/
