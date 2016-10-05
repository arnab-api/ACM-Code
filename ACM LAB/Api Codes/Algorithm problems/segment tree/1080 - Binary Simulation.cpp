#include<bits/stdc++.h>
using namespace std;
#define M 100010

struct info
{
    int data,prop;
};

info tree[M*3];
char ara[M];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].data=ara[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].data=tree[left].data+tree[right].data;
}

void update(int node,int b,int e,int i,int j,int x)
{
    if(i>e || j<b) return;
    if(b>=i && e<=j)
    {
        tree[node].data+=(e-b+1)*x;
        tree[node].prop+=x;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].data=tree[left].data+tree[right].data+(e-b+1)*tree[node].prop;
}

int query(int node,int b,int e,int i,int j,int carry=0)
{
    if(i>e || j<b) return 0;
    if(b>=i && e<=j) return tree[node].data+(e-b+1)*carry;
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j,carry+tree[node].prop);
    int p2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return p1+p2;
}

int main()
{
    //freopen("0file.txt","r",stdin);
    int l,t,n,q,i,j,it,kase=0;
    char dit;
    scanf("%d",&t);
    while(t--){
        getchar();
        gets(ara);
        //printf("==>");
        //puts(ara);
        l=strlen(ara);
        for(i=0;i<3*M;i++){
            tree[i].data=0;
            tree[i].prop=0;
        }
        printf("Case %d:\n",++kase);
        scanf("%d",&q);
        while(q--){
            scanf(" %c",&dit);
            if(dit=='I') {
                scanf("%d%d",&i,&j);
                update(1,1,l+1,i,j,1);
                //for(i=1;i<20;i++) printf("%d=>%d %d\n",i,tree[i].data,tree[i].prop);
            }
            if(dit=='Q'){
                scanf("%d",&i);
                //printf("--->(%d)",query(1,1,l+1,i,i,0));
                if(query(1,1,l+1,i,i,0)%2==0) printf("%c\n",ara[i-1]);
                else{
                    if(ara[i-1]=='1') printf("0\n");
                    else printf("1\n");
                }
            }
        }
    }
    return 0;
}
