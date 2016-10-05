#include<bits/stdc++.h>
using namespace std;
#define M 1001000

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
    tree[node].data=(end-beg+1)*val;
    if(beg!=end){
        int left=node*2;
        int right=left+1;
        tree[left].lazy=val;
        tree[right].lazy=val;
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
    int t,i,j,n,col,p,kase=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<7*n;i++){
            tree[i].data=0;
            tree[i].lazy=0;
        }
        for(col=1;col<=n;col++){
            scanf("%d%d",&i,&j);
            update(1,1,2*n,i,j,col);
        }
        //for(i=1;i<=2*n;i++) printf("%d(%d) ",i,query(1,1,2*n,i,i));
        //printf("\n");
        set<int>st;
        for(i=1;i<=2*n;i++){
            p=query(1,1,2*n,i,i);
            if(p!=0) st.insert(p);
        }
        //cout<<"========================>";
        printf("Case %d: %d\n",++kase,st.size());
    }
    return 0;
}
