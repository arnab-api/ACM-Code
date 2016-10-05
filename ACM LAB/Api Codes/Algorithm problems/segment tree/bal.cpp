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
    int n,i,j,d,t,kase=0,n_c;
    scanf("%d",&n_c);
    while(n_c--){
        scanf("%d%d",&n,&d);
        for(i=1;i<=n;i++) scanf("%d",&ara[i]);
        init_min(1,1,n);
        init_max(1,1,n);
        int max_diff=0;
        for(i=1;i<=n-d+1;i++){
            t=query_max(1,1,n,i,i+d-1)-query_min(1,1,n,i,i+d-1);
            if(t>max_diff) max_diff=t;
        }
        printf("Case %d: %d\n",++kase,max_diff);
    }
    return 0;
}
