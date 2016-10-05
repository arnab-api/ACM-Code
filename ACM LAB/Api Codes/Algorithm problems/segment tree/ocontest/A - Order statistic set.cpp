#include<bits/stdc++.h>
using namespace std;
#define M 200100

struct Query{
    char dit;
    int num;
};
Query Q[M];

int val[M],tree[4*M];

void update(int node,int b,int e,int pos,int val)
{
    if(e<pos || b>pos) return;
    if(b==e && b==pos) {tree[node]=val; return;}
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,pos,val);
    update(right,mid+1,e,pos,val);
    tree[node]=tree[left]+tree[right];
}

int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b) return 0;
    if(b>=i && e<=j) return tree[node];
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}

int find_pos(int node,int b,int e,int x)
{
    if(tree[node]==x && b==e) return val[b];
    int mid=(b+e)/2;
    int left=node*2;
    int right=node*2+1;
    //printf("%d %d %d %d %d\n",x,tree[left],tree[right],b,e);
    if(x>tree[left]) return find_pos(right,mid+1,e,x-tree[left]);
    else return find_pos(left,b,mid,x);
}

int main()
{
    int q,i,x,m_in;
    char ch;
    while(scanf("%d",&q)==1){
        memset(tree,0,sizeof(tree));
        for(i=1;i<=q;i++){
            scanf(" %c",&ch);
            scanf("%d",&x);
            Q[i].dit=ch;
            val[i]=x;
            Q[i].num=x;
        }
        sort(val+1,val+q+1);
        //for(i=1;i<=q;i++) cerr<<val[i]<<" ";
        //printf("\n");
        for(i=1;i<=q;i++) {
            if(Q[i].dit!='K') Q[i].num=lower_bound(val+1,val+q+1,Q[i].num)-val;
        }
        //for(i=1;i<=q;i++) printf("===>%c %d\n",Q[i].dit,Q[i].num);
        for(i=1;i<=q;i++){
            if(Q[i].dit=='I') update(1,1,q,Q[i].num,1);
            else if(Q[i].dit=='D') update(1,1,q,Q[i].num,0);
            else if(Q[i].dit=='C') printf("%d\n",query(1,1,q,1,Q[i].num-1));
            else if(Q[i].dit=='K') {
                if(Q[i].num>query(1,1,q,1,q)) printf("invalid\n");
                else printf("%d\n",find_pos(1,1,q,Q[i].num));
            }
        }
    }
    return 0;
}
