#include<bits/stdc++.h>
using namespace std;
#define M 100000

int ara[M],tree[3*M];
void init(int node,int b,int e)
{
    if(b==e) {tree[node]=ara[b]; return;}
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}

int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b) return 0;
    if(i<=b && j>=e) return tree[node];
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}

void update(int node,int b,int e,int i,int newval)
{
    if(i>e || i<b) return;
    if(b==e) {tree[node]=newval; return;}
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,newval);
    update(right,mid+1,e,i,newval);
    tree[node]=tree[left]+tree[right];
}

int main()
{
    int t,n,q,i,j,dit,index,l,r,newval,kase=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++) scanf("%d",&ara[i]);
        init(1,1,n);
        //for(i=1;i<10;i++) printf("%d-->%d\n",i,tree[i]);
        //while(scanf("%d%d",&i,&j)==2) printf("(%d->%d)==>%d\n",i,j,query(1,1,n,i,j));
        //update(1,1,n,3,7);
        //for(i=1;i<10;i++) printf("%d-->%d\n",i,tree[i]);
        //printf("===>%d\n",query(1,1,n,1,n));
        printf("Case %d:\n",++kase);
        while(q--){
            scanf("%d",&dit);
            if(dit==1){
                scanf("%d",&index);
                printf("%d\n",query(1,1,n,index+1,index+1));
                update(1,1,n,index+1,0);
            }
            else if(dit==2){
                scanf("%d%d",&index,&newval);
                int val=query(1,1,n,index+1,index+1);
                //printf("==>%d==>\n",val);
                update(1,1,n,index+1,val+newval);
                //val=query(1,1,n,index+1,index+1);
                //printf("==>%d==>\n",val);
            }
            else if(dit==3){
                scanf("%d%d",&l,&r);
                printf("%d\n",query(1,1,n,l+1,r+1));
            }
        }
    }
    return 0;
}
