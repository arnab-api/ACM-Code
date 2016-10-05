#include<bits/stdc++.h>
using namespace std;
#define M 100100
#define ll long long int

struct info
{
    int zero,one,two,prop;
};

info tree[4*M];
int ara[M],n;

void refresh(int node,int b,int e,int val)
{
    int t0=tree[node].zero,t1=tree[node].one,t2=tree[node].two;
    if(val%3==1){
        tree[node].zero=t2;
        tree[node].one=t0;
        tree[node].two=t1;
    }
    if(val%3==2){
        tree[node].zero=t1;
        tree[node].one=t2;
        tree[node].two=t0;
    }
    if(b!=e)
    {
        int left=node*2;
        int right=node*2+1;
        tree[left].prop+=val;
        tree[right].prop+=val;
    }
    tree[node].prop=0;
}

void init(int node,int b,int e)
{
    if(b==e){ tree[node].zero=1; return;}
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].zero=tree[left].zero+tree[right].zero;
    tree[node].one=tree[left].one+tree[right].one;
    tree[node].two=tree[left].two+tree[right].two;
}

void update(int node,int b,int e,int i,int j,int val)
{
    if(tree[node].prop%3!=0) refresh(node,b,e,tree[node].prop);
    if(i>e || j<b) return;

    if(i<=b && j>=e)
    {
        refresh(node,b,e,val);
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);
    tree[node].zero=tree[left].zero+tree[right].zero;
    tree[node].one=tree[left].one+tree[right].one;
    tree[node].two=tree[left].two+tree[right].two;
}

int query(int node,int b,int e,int i,int j)
{
    if(tree[node].prop%3!=0) refresh(node,b,e,tree[node].prop);
    if(i>e || j<b) return 0;

    if(i<=b && j>=e) return tree[node].zero;
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}

int main()
{
    int n,t,q,i,j,dit,a,b,kase=0;
    while(scanf("%d%d",&n,&q)==2){
        for(i=0;i<=3*n;i++){
            tree[i].zero=0;
            tree[i].one=0;
            tree[i].two=0;
            tree[i].prop=0;
        }
        init(1,1,n);
        //for(i=0;i<3*n;i++) if(tree[i].prop!=0) cout<<"==>"<<i<<"==>"<<tree[i].prop%3<<endl;
        while(q--){
            scanf("%d",&dit);
            if(dit==0){
                scanf("%d%d",&i,&j);
                update(1,1,n,i+1,j+1,1);
            }
            else if(dit==1){
                scanf("%d%d",&a,&b);
                //cout<<"===================>";
                printf("%d\n",query(1,1,n,a+1,b+1));
            }
        }
    }
    return 0;
}

