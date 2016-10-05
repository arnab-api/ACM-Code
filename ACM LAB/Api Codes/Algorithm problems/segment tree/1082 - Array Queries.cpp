#include<bits/stdc++.h>
using namespace std;
#define M 100010

int ara[M],tree[3*M];

void init(int node,int b,int e)
{
    if(b==e){tree[node]=ara[b]; return;}
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
}

int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b) return INT_MAX;
    if(b>=i && e<=j) return tree[node];
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return min(p1,p2);
}

/*void update(int node,int b,int e,int i,int newval)
{
    if(b==e) {tree[node]=newval; return;}
    if(i>e || i<b) return;
    int right=2*node+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    update(left,b,mid,i,newval);
    update(right,mid+1,e,i,newval);
    tree[node]=min(tree[left],tree[right]);
}*/

/*int main()
{
    int t,n,q,i,j,kase=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        //memset(ara,0,sizeof(ara));
        for(i=1;i<=n;i++) {
            scanf("%d",&ara[i]);
        }
        init(1,1,n);
        printf("Case %d:\n",++kase);
        while(q--){
            scanf("%d%d",&i,&j);
            printf("%d\n",query(1,1,n,i,j));
        }
    }
    return 0;
}
*/

int main()
{
    int t,n,q,i,j,dit,index,l,r,newval;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++) scanf("%d",&ara[i]);
        init(1,1,n);
        for(i=1;i<16;i++) printf("%d-->%d\n",i,tree[i]);
        /*printf("===>%d\n",query(1,1,n,1,n));
        while(q--){
            scanf("%d",&dit);
            if(dit==1){
                scanf("%d",&index);
                printf("==>%d\n",ara[index]);
                update(1,1,n,index+1,0);
            }
            else if(dit==2){
                scanf("%d%d",&index,&newval);
                update(1,1,n,index+1,ara[index]+newval);
            }
            else if(dit==3){
                scanf("%d%d",&l,&r);
                printf("==>%d\n",query(1,1,n,l+1,r+1));
            }
        }*/
    }
    return 0;
}
