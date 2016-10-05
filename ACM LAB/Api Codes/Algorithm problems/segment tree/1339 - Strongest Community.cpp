#include<bits/stdc++.h>
using namespace std;
#define M 100010

int ara[M];
struct info{
    int lval,lmax;
    int rval,rmax;
    int tmax=0;
};

info tree[3*M],x;

void init(int node,int b,int e)
{
    if(b==e){
        tree[node].lval=tree[node].rval=ara[b];
        tree[node].lmax=tree[node].rmax=tree[node].tmax=1;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].lval=tree[left].lval;
    tree[node].rval=tree[right].rval;
    if(tree[left].lval==tree[right].lval) tree[node].lmax=tree[left].lmax+tree[right].lmax;
    else tree[node].lmax=tree[left].lmax;
    if(tree[left].rval==tree[right].rval) tree[node].rmax=tree[left].rmax+tree[right].rmax;
    else tree[node].rmax=tree[right].rmax;
    tree[node].tmax=max(tree[left].tmax,tree[right].tmax);
    if(tree[left].rval==tree[right].lval) tree[node].tmax=max(tree[node].tmax,tree[left].rmax+tree[right].lmax);
}

info query(int node,int b,int e,int i,int j)
{
    if(b==i && e==j) return tree[node];
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    if(j<=mid) return query(left,b,mid,i,j);
    else if(i>mid) return query(right,mid+1,e,i,j);
    else{
        info L=query(left,b,mid,i,mid);
        info R=query(right,mid+1,e,mid+1,j);
        info res;
        res.lval=L.lval; res.rval=R.rval;
        if(L.lval==R.lval) res.lmax=L.lmax+R.lmax;
        else res.lmax=L.lmax;
        if(L.rval==R.rval) res.rmax=L.rmax+R.rmax;
        else res.rmax=R.rmax;
        res.tmax=max(L.tmax,R.tmax);
        if(L.rval==R.lval) res.tmax=max(res.tmax,L.rmax+R.lmax);
        return res;
    }
}

int main()
{
    int t,n,c,q,i,j,kase=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&c,&q);
        for(i=1;i<=n;i++) scanf("%d",&ara[i]);
        init(1,1,n);
        /*for(i=0;i<30;i++){
            if(tree[i].tmax==0) continue;
            printf("%d ---> %d(%d)  %d(%d) => %d\n",i,tree[i].lval,tree[i].lmax,tree[i].rval,tree[i].rmax,tree[i].tmax);
        }*/
        printf("Case %d:\n",++kase);
        while(q--){
            scanf("%d%d",&i,&j);
            //cout<<"---->";
            info ans=query(1,1,n,i,j);
            printf("%d\n",ans.tmax);
        }
    }
    return 0;
}
