#include<bits/stdc++.h>
using namespace std;
#define M 100100

struct info{
    int data,lazy;
};

info tree[3*M];
int ara[M],n;

void init(int node,int beg,int end)
{
    if(beg==end){tree[node].data=ara[beg]; return;}

    int mid=(beg+end)/2;
    int left=node*2;
    int right=left+1;
    init(left,beg,mid);
    init(right,mid+1,end);

    tree[node].data=tree[left].data+tree[right].data;
}

void refresh(int node,int beg,int end,int val)
{
    tree[node].data+=(end-beg+1)*val;
    if(beg!=end){
        int left=node*2;
        int right=left+1;
        tree[left].lazy+=val;
        tree[right].lazy+=val;
    }
    tree[node].lazy=0;
}

void update(int node,int beg,int end,int i,int j,int val)
{
    if(tree[node].lazy!=0) refresh(node,beg,end,tree[node].lazy);
    if(i>end || j<beg) return;
    if(i<=beg && j>=end){
        refresh(node,beg,end,val);
        return;
    }
    int mid=(beg+end)/2;
    int left=node*2;
    int right=left+1;
    update(left,beg,mid,i,j,val);
    update(right,mid+1,end,i,j,val);
    tree[node].data=tree[left].data+tree[right].data;
}

int query(int node,int beg,int end,int i,int j)
{
    if(tree[node].lazy!=0) refresh(node,beg,end,tree[node].lazy);
    if(i>end || j<beg) return 0;
    if(i<=beg && j>=end) return tree[node].data;

    int mid=(beg+end)/2;
    int left=node*2;
    int right=left+1;
    int p1=query(left,beg,mid,i,j);
    int p2=query(right,mid+1,end,i,j);
    return p1+p2;
}

int main()
{
    int i,j,q,k,l,t,dit,it;
    while(scanf("%d",&n)){
        for(i=1;i<=n;i++) scanf("%d",&ara[i]);
        for(i=0;i<=3*n;i++){
            tree[i].data=0;
            tree[i].lazy=0;
        }
        init(1,1,n);
        for(i=1;i<20;i++) printf("%d-->%d %d\n",i,tree[i].data,tree[i].lazy);
        update(1,1,n,3,7,5);
        update(1,1,n,3,7,-7);
        while(scanf("%d%d",&i,&j)==2) printf("%d->%d==>%d\n",i,j,query(1,1,n,i,j));
    }
    return 0;
}
/*
9
1 2 3 4 5 6 7 8 9
*/

