#include<bits/stdc++.h>
using namespace std;
#define M 80100

int ara[M];

struct info{
    int data,lazy;
};

info tree[3*M];

void init(int node,int b,int e)
{
    if(b==e) {tree[node].data=ara[b]; return;}
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].data=tree[left].data+tree[right].data;
}

void refresh(int node,int b,int e,int val)
{
    tree[node].data=(e-b+1)*val;
    if(b!=e){
        int left=node*2;
        int right=node*2+1;
        tree[left].lazy=val;
        tree[right].lazy=val;
    }
    tree[node].lazy=0;
}

void update(int node,int b,int e,int i,int j,int val)
{
    if(tree[node].lazy!=0) refresh(node,b,e,tree[node].lazy);
    if(e<i || b>j) return;
    if(b>=i && e<=j){
        refresh(node,b,e,val);
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);
    tree[node].data=tree[left].data+tree[right].data;
}

int query(int node,int b,int e,int i,int j)
{
    if(tree[node].lazy!=0) refresh(node,b,e,tree[node].lazy);
    if(e<i || b>j) return 0;
    if(b>=i && e<=j) return tree[node].data;
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}

struct Query{
    int x, y;
};

Query Q[M];

int main()
{
    set<int>st,st2;
    int t,n,x,y,i,j,uniq,L,R,cnt,l;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<M;i++){
            tree[i].data=0;
            tree[i].lazy=0;
        }
        st.clear();
        st2.clear();
        uniq=0;
        for(i=1;i<=n;i++){
            scanf("%d",&x);
            scanf("%d",&y);
            Q[i].x=x;
            Q[i].y=y;
            l=st.size();
            st.insert(x);
            if(st.size()>l) ara[uniq++]=x;
            l=st.size();
            st.insert(y);
            if(st.size()>l) ara[uniq++]=y;
        }
        sort(ara,ara+uniq);
        //for(i=0;i<uniq;i++) printf("%d ",ara[i]);
        //printf("---->\n");
        for(i=1;i<=n;i++){
            L=lower_bound(ara,ara+uniq,Q[i].x)-ara+1;
            R=lower_bound(ara,ara+uniq,Q[i].y)-ara+1;
            //printf("%d %d\n",L,R);
            update(1,1,uniq,L,R,i);
            //for(j=1;j<=uniq;j++) printf("%d ",query(1,1,uniq,j,j));
            //printf("\n");
        }
        for(i=1;i<=uniq;i++){
            x=query(1,1,uniq,i,i);
            //printf("===>%d\n",x);
            if(x!=0) st2.insert(x);
        }
        printf("%d\n",st2.size());
    }
    return 0;
}
