#include<bits/stdc++.h>
using namespace std;
#define M 555

int ara[M][M],tree[M][4*M];

void init(int N,int node,int b,int e)
{
    if(b==e) {tree[N][node]=ara[N][b];return;}
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(N,left,b,mid);
    init(N,right,mid+1,e);
    tree[N][node]=max(tree[N][left],tree[N][right]);
}

int query(int N,int node,int b,int e,int i,int j)
{
    if(b>j || e<i ) return -INT_MAX;
    if(b>=i && e<=j) return tree[N][node];
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(N,left,b,mid,i,j);
    int p2=query(N,right,mid+1,e,i,j);
    return max(p1,p2);
}

int main()
{
    int t,n,q,I,J,S,i,j,ans,kase=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                scanf("%d",&ara[i][j]);
            }
            init(i,1,1,n);
        }
        printf("Case %d:\n",++kase);
        while(q--){
            scanf("%d%d%d",&I,&J,&S);
            ans=-INT_MAX;
            for(i=I;i<=I+S-1;i++) ans=max(ans,query(i,1,1,n,J,J+S-1));
            //cerr<<"--------------->";
            printf("%d\n",ans);
        }
    }
    return 0;
}
