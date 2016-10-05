#include<bits/stdc++.h>
using namespace std;
#define M 100100

int ara[M];
int tree[4*M];

void build(int node,int b,int e)
{
    if(b==e){tree[node]=ara[b]; return;}
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=max(tree[left],tree[right]);
}

int query(int node,int b,int e,int i,int j)
{
    if(b>j || e<i) return 0;
    if(b>=i && e<=j) return tree[node];
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return max(p1,p2);
}

void update(int node,int b,int e,int p,int x)
{
    if(b>p || e<p) return;
    if(b==e && b==p){tree[node]=x; return;}
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,p,x);
    update(right,mid+1,e,p,x);
    tree[node]=max(tree[left],tree[right]);
}

int main()
{
    int t,n,dit,x;
    while(scanf("%d",&t)==1){
        memset(tree,0,sizeof(tree));
        n=0;
        while(t--){
            scanf("%d",&dit);
            if(dit==1){
                n++;
                scanf("%d",&x);
                update(1,1,M,n,x);
            }
            else if(dit==2){
                update(1,1,M,n,0);
                n--;
            }
            else if(dit==3){
                cerr<<"------------->";
                printf("%d\n",query(1,1,M,1,M));
            }
        }
    }
    return 0;
}
