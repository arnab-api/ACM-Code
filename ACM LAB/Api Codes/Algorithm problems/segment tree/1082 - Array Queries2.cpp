#include<bits/stdc++.h>
using namespace std;
#define M 100010

int arr[M],tree[3*M];
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node]=tree[Left]+tree[Right];
    //tree[node]=min(tree[Left],tree[Right]);
}
int query(int node,int b,int e,int i,int j)
{
    if (i > e || j < b) return 0;
    if (b >= i && e <= j) return tree[node];
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(Left,b,mid,i,j);
    int p2=query(Right,mid+1,e,i,j);
    return p1+p2;
    //return min(p1,p2);
}
void update(int node,int b,int e,int i,int newvalue)
{
    if (i > e || i < b) return;
    if (b >= i && e <= i)
    {
        tree[node]=newvalue;
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,newvalue);
    update(Right,mid+1,e,i,newvalue);
    tree[node]=tree[Left]+tree[Right];
    //tree[node]=min(tree[Left],tree[Right]);
}

int main()
{
    int t,n,q,i,j,dit,index,l,r,newval;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++) scanf("%d",&arr[i]);
        init(1,1,n);
        //for(i=1;i<10;i++) printf("%d-->%d\n",i,tree[i]);
        //while(scanf("%d%d",&i,&j)==2) printf("(%d->%d)==>%d\n",i,j,query(1,1,n,i,j));
        //update(1,1,n,3,7);
        //for(i=1;i<10;i++) printf("%d-->%d\n",i,tree[i]);
        //printf("===>%d\n",query(1,1,n,1,n));
        while(q--){
            scanf("%d",&dit);
            if(dit==1){
                scanf("%d",&index);
                printf("==>%d\n",arr[index+1]);
                update(1,1,n,index+1,0);
            }
            else if(dit==2){
                scanf("%d%d",&index,&newval);
                update(1,1,n,index+1,arr[index+1]+newval);
            }
            else if(dit==3){
                scanf("%d%d",&l,&r);
                printf("==>%d\n",query(1,1,n,l+1,r+1));
            }
        }
    }
    return 0;
}
