#include<bits/stdc++.h>
using namespace std;
#define M 100010

struct info
{
    int data,prop;
};

info tree[M*3];
int ara[M];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].data=ara[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].data=tree[left].data+tree[right].data;
}

void update(int node,int b,int e,int i,int j,int x)
{
    if(i>e || j<b) return;
    if(b>=i && e<=j)
    {
        tree[node].data+=(e-b+1)*x;
        tree[node].prop+=x;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].data=tree[left].data+tree[right].data+(e-b+1)*tree[node].prop;
}

int query(int node,int b,int e,int i,int j,int carry=0)
{
    if(i>e || j<b) return 0;
    if(b>=i && e<=j) return tree[node].data+(e-b+1)*carry;
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j,carry+tree[node].prop);
    int p2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return p1+p2;
}


/*int query(int node,int b,int e,int i,int j,int carry=0)
{
    if (i > e || j < b) return 0;
    if(b>=i and e<=j) return tree[node].data+carry*(e-b+1);
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;
    int p1 = query(Left, b,mid, i, j, carry+tree[node].prop);
    int p2 = query(Right, mid+1, e, i, j,carry+tree[node].prop);
    return p1+p2;
}
*/

int main()
{
    int n,i,j,q,k,l,t,dit,it;
    while(scanf("%d",&n)){
        for(i=1;i<=n;i++) scanf("%d",&ara[i]);
        for(i=0;i<=3*n;i++){
            tree[i].data=0;
            tree[i].prop=0;
        }
        init(1,1,n);
        for(i=1;i<20;i++) printf("%d-->%d %d\n",i,tree[i].data,tree[i].prop);
        update(1,1,n,3,7,3);
        update(1,1,n,3,7,2);
        while(scanf("%d%d",&i,&j)==2) printf("%d->%d==>%d\n",i,j,query(1,1,n,i,j));
    }
    return 0;
}
/*
9
1 2 3 4 5 6 7 8 9
*/
