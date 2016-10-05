#include<bits/stdc++.h>
using namespace std;
#define M 100100
int ara[M],tree[3*M];

void init(int node,int b,int e)
{
    if(b==e){
        if(ara[b]>0) tree[node]=1;
        else if(ara[b]<0) tree[node]=-1;
        else tree[node]=0;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]*tree[right];
}

void update(int node,int b,int e,int p,int val)
{
    if(b>p || e<p) return;
    if(b==e && b==p){
        if(val==0) tree[node]=0;
        else if(val>0) tree[node]=1;
        else if(val<0) tree[node]=-1;
        //printf("-->%d %d %d--->>>%d\n",node,b,e,tree[node]);
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,p,val);
    update(right,mid+1,e,p,val);
    tree[node]=tree[left]*tree[right];
}

int query(int node,int b,int e,int i,int j)
{
    if(b>j || e<i) return 1;
    if(b>=i && e<=j) {
        return tree[node];
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1*p2;
}

int main()
{
    int n,q,x,y,i,val;
    char dit;
    string ans;
    while(scanf("%d%d",&n,&q)==2){
        ans="";
        memset(tree,0,sizeof(tree));
        for(i=1;i<=n;i++) scanf("%d",&ara[i]);
        //for(i=1;i<=n;i++) printf("%d ",ara[i]);
        init(1,1,n);
        while(q--){
            scanf(" %c",&dit);
            scanf("%d%d",&x,&y);
            if(dit=='C') update(1,1,n,x,y);
            else if(dit=='P'){
                val=query(1,1,n,x,y);
                if(val==1) ans+="+";//printf("+");
                else if(val==-1) ans+="-";//printf("-");
                else ans+="0";//printf("0");
            }
        }
        //cout<<"---->.........................";
        cout<<ans<<endl;
    }
    return 0;
}
/*
4 6
-2 6 0 -1
C 1 10
P 1 4
C 3 7
P 2 2
C 4 -5
P 1 4
5 9
1 5 -2 4 3
P 1 2
P 1 5
C 4 -5
P 1 5
P 4 5
C 3 0
P 1 5
C 4 -5
C 4 -5
*/
