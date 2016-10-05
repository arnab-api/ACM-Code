#include<bits/stdc++.h>
using namespace std;
#define M 100010
#define oo INT_MAX

struct info{
    int data,index;
};

info tree[3*M],ara[M];
int n;

void init(int node,int b,int e)
{
    if(b==e){tree[node]=ara[b]; return;}
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    if(tree[left].data<tree[right].data) tree[node]=tree[left];
    else tree[node]=tree[right];
}

info query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b) return ara[0];
    if(i<=b && j>=e) return tree[node];
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    info p1=query(left,b,mid,i,j);
    info p2=query(right,mid+1,e,i,j);
    if(p1.data<p2.data) return p1;
    else return p2;
}

int maxi,maxb,maxe,cnt=0;

void recur(int b,int e)
{
    //if(cnt==20) return;
    if(b>e) return;
    info mini=query(1,1,n,b,e);
    if(mini.data*(e-b+1)>maxi){
        maxi=mini.data*(e-b+1);
        maxb=b;
        maxe=e;
    }
    int pos=mini.index;
    //printf("%d-->%d %d (%d %d %d %d %d)\n",++cnt,mini,pos,maxi,maxb,maxe,b,e);
    recur(b,pos-1);
    recur(pos+1,e);
}

int main()
{
    int i,j,l,t,r,val,ans,kase=0,a;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ara[0].data=oo;
        ara[0].index=0;
        for(i=1;i<=n;i++) {
            scanf("%d",&a);
            ara[i].data=a;
            ara[i].index=i;
        }
        init(1,1,n);
        /*for(i=0;i<v.size();i++) printf("%d(%d) ",v[i].data,v[i].index);
        printf("\n");
        for(i=1;i<20;i++) printf("%d-->%d\n",i,tree[i]);
        while(scanf("%d%d",&i,&j)==2){
            val=query(1,1,n,i,j);
            printf("min=%d && pos=%d\n",val,bin_search(i,j,val));
        }*/
        maxi=0;//query(1,1,n,1,n)*n;
        maxb=1;
        maxe=n;
        recur(1,n);
        printf("Case %d: %d\n",++kase,maxi);
    }
    return 0;
}
/*
9
44 33 77 11 22 99 55 66 88
*/
