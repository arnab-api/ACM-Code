#include<bits/stdc++.h>
using namespace std;
#define M 100000

int tree_min[3*M],ara[M],tree_max[3*M];
void init_max(int node,int b,int e)
{
    if(b==e){ tree_max[node]=ara[b]; return;}
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init_max(left,b,mid);
    init_max(right,mid+1,e);
    tree_max[node]=max(tree_max[left],tree_max[right]);
}

int query_max(int node,int b,int e,int i,int j)
{
    if(i>e || j<b) return -INT_MAX;
    if(b>=i && e<=j) return tree_max[node];
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query_max(left,b,mid,i,j);
    int p2=query_max(right,mid+1,e,i,j);
    return max(p1,p2);
}

void init_min(int node,int b,int e)
{
    if(b==e){ tree_min[node]=ara[b]; return;}
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init_min(left,b,mid);
    init_min(right,mid+1,e);
    tree_min[node]=min(tree_min[left],tree_min[right]);
}

int query_min(int node,int b,int e,int i,int j)
{
    if(i>e || j<b) return INT_MAX;
    if(b>=i && e<=j) return tree_min[node];
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query_min(left,b,mid,i,j);
    int p2=query_min(right,mid+1,e,i,j);
    return min(p1,p2);
}

int main()
{
    int n,q,l,r,i,rin_min,rin_max,rout_max;
    double val1,val2;
    while(scanf("%d",&n)==1){
        for(i=1;i<=n;i++) scanf("%d",&ara[i]);
        init_max(1,1,n);
        init_min(1,1,n);
        scanf("%d",&q);
        while(q--){
            scanf("%d%d",&l,&r);
            rin_min=query_min(1,1,n,l+1,r+1);
            rin_max=query_max(1,1,n,l+1,r+1);
            rout_max=max(query_max(1,1,n,1,l),query_max(1,1,n,r+2,n));
            //printf("==>%d %d %d\n",rin_min,rin_max,rout_max);
            val1=rin_min+rout_max;
            val2=rin_min+(rin_max-rin_min)/2.0;
            //printf("%lf %lf\n",val1,val2);
            printf("%.1lf\n",max(val1,val2));
        }
    }
    return 0;
}
