#include<bits/stdc++.h>
using namespace std;
#define M 2000010

int tree[4*M];
bool flag[M];

void init(int node,int b,int e)
{
    if(b==e){
        if(b%2) {tree[node]=1; flag[b]=true;}
        else tree[node]=0;
        return ;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=node*2+1;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}

int query(int node,int b,int e,int i,int j)
{
    if(b>j || e<i) return 0;
    if(b>=i && e<=j) return tree[node];
    int mid=(b+e)/2;
    int left=node*2;
    int right=node*2+1;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}

void update(int node,int b,int e,int pos,int val)
{
    if(b>pos || e<pos) return;
    if(b==e && b==pos) {
        tree[node]=val;
        if(val==0) flag[b]=false;
        return;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=node*2+1;
    update(left,b,mid,pos,val);
    update(right,mid+1,e,pos,val);
    tree[node]=tree[right]+tree[left];
}

int find_val(int node,int b,int e,int x)
{
    if(b==e && tree[node]==x) return b;
    int mid=(b+e)/2;
    int left=node*2;
    int right=node*2+1;
    if(x>tree[left]) return find_val(right,mid+1,e,x-tree[left]);
    else return find_val(left,b,mid,x);
}

int main()
{
    init(1,1,M);
    //for(int i=1;i<=10;i++) printf("%d --> %d\n",i,query(1,1,M,i,i));
    int i,j,k,l,x,y;
    for(i=2;i<M;i++){
        l=query(1,1,M,1,M);
        if(i>l) break;
        x=find_val(1,1,M,i);
        //printf("%d\n",x);
        k=x*(l/x);
        for(j=k;j>0;j-=x){
            y=find_val(1,1,M,j);
            update(1,1,M,y,0);
        }
    }
    int lucky[500000],l_in=0;
    for(i=1;i<M;i++) if(flag[i]) lucky[l_in++]=i;
    //for(i=0;i<20;i++) printf("%d --> %d\n",i,lucky[i]);
    //printf("===>%d\n",l_in);
    int n,pos;
    bool fl;
    while(scanf("%d",&n)==1){
        if(n&1) printf("%d is not the sum of two luckies!\n",n);
        else{
            pos=lower_bound(lucky,lucky+l_in,n/2)-lucky;
            //printf("%d %d\n",pos,lucky[pos]);
            if(lucky[pos]!=n/2) pos--;
            fl=false;
            while(!fl && pos>-1){
                if(flag[n-lucky[pos]]==true) fl=true;
                else pos--;
            }
            if(!fl) printf("%d is not the sum of two luckies!\n",n);
            else printf("%d is the sum of %d and %d.\n",n,lucky[pos],n-lucky[pos]);
        }
    }
    return 0;
}
