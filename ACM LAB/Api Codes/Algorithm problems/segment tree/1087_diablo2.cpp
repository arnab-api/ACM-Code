#include<bits/stdc++.h>
using namespace std;
#define M 200110

struct info{
    int data,id=-1;
};
info tree[3*M+60];
int ara[M+20],C[M+20],n;

void init(int node,int b,int e)
{
    if(b==e) {
        tree[node].data=C[b];
        tree[node].id=ara[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].data=tree[left].data+tree[right].data;
}

void update(int node,int b,int e,int pos,int val)
{
    if(e<pos || b>pos) return;
    if(b==e && b==pos) {tree[node].data=val; return;}
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,pos,val);
    update(right,mid+1,e,pos,val);
    tree[node].data=tree[left].data+tree[right].data;
}

int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b) return 0;
    if(b>=i && e<=j) return tree[node].data;
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}

int find_val(int node,int b,int e,int x)
{
    if(tree[node].data==x && b==e) {
        update(1,1,M,b,0);
        C[b]=0;
        //printf("------------<>%d %d\n",b,x);
        return ara[b];
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    if(tree[left].data>=x) return find_val(left,b,mid,x);
    else return find_val(right,mid+1,e,x-tree[left].data);
}

int main()
{
    /*n=14;
    for(int i=1;i<15;i++) ara[i]=i, C[i]=1;
    init(1,1,n);
    printf("%d\n",query(1,1,n,1,n));
    printf("%d\n",query(1,1,n,7,13));
    update(1,1,n,5,0);
    printf("%d\n",query(1,1,n,1,7));
    printf("%d\n",query(1,1,n,5,12));*/
    int t,q,a,i,kase=0,ans;
    char ch;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        memset(C,0,sizeof(C));
        for(i=1;i<=n;i++) {
            scanf("%d",&ara[i]);
            C[i]=1;
        }
        init(1,1,M);
        printf("Case %d:\n",++kase);
        while(q--){
            scanf(" %c",&ch);
            scanf("%d",&a);
            if(ch=='a'){
                n++;
                C[n]=1;
                ara[n]=a;
                update(1,1,M,n,1);
            }
            else if(ch=='c'){
                //cout<<"=------>"<<query(1,1,M,1,M)<<endl;
                if(query(1,1,M,1,M)<a) printf("none\n");
                else{
                    ans=find_val(1,1,M,a);
                    printf("%d\n",ans);
                }
            }
        }
    }
    return 0;
}

