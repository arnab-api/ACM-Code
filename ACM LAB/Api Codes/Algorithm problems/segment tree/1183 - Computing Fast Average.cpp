
#include<bits/stdc++.h>
using namespace std;
#define M 100100

struct info{
    int data,prop;
};

info tree[3*M];
int ara[M],n;

void refresh(int node,int b,int e)
{
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    tree[left].data=(mid-b+1)*tree[node].prop;
    tree[right].data=(e-mid)*tree[node].prop;
    tree[left].prop=tree[node].prop;
    tree[right].prop=tree[node].prop;
    tree[node].prop=-1;
}

void init(int node,int b,int e)
{
    if(b==e){ tree[node].data=ara[b]; return;}
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].data=tree[left].data+tree[right].data;
}

void update(int node,int b,int e,int i,int j,int val)
{
    if(i>e || j<b) return;
    if(i<=b && j>=e){
        tree[node].data=(e-b+1)*val;
        tree[node].prop=val;
        return;
    }
    if(tree[node].prop!=-1) refresh(node,b,e);
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);
    tree[node].data=tree[left].data+tree[right].data;
}

int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b) return 0;
    if(i<=b && j>=e) return tree[node].data;
    if(tree[node].prop!=-1) refresh(node,b,e);
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}

int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    int i,j,q,k,l,t,dit,it,v,kase=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        //for(i=1;i<=n;i++) scanf("%d",&ara[i]);
        for(i=0;i<=3*n;i++){
            tree[i].data=0;
            tree[i].prop=-1;
        }
        //init(1,1,n);
        /*for(i=1;i<20;i++) printf("%d-->%d %d\n",i,tree[i].data,tree[i].prop);
        update(1,1,n,3,7,5);
        while(scanf("%d%d",&i,&j)==2) printf("%d->%d==>%d\n",i,j,query(1,1,n,i,j));*/
        printf("Case %d:\n",++kase);
        while(q--){
            scanf("%d",&dit);
            if(dit==1){
                scanf("%d%d%d",&i,&j,&v);
                update(1,1,n,i+1,j+1,v);
            }
            else if(dit==2){
                scanf("%d%d",&i,&j);
                int sum=query(1,1,n,i+1,j+1);
                int div=j-i+1;
                if(sum%div==0) printf("%d\n",sum/div);
                else{
                    int GCD=gcd(sum,div);
                    printf("%d/%d\n",sum/GCD,div/GCD);
                }
            }
        }
    }
    return 0;
}
/*
9
1 2 3 4 5 6 7 8 9
*/
