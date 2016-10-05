#include<bits/stdc++.h>
using namespace std;
#define M 100100

int par[M],val[M];

int main()
{
    int i,t,n,q,a,b,kase=0,node,v;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        //memset(par,-1,sizeof(par));
        //memset(val,-1,sizeof(val));
        par[0]=0;
        val[0]=1;
        for(i=1;i<=n-1;i++){
            printf("%d --> ",i);
            scanf("%d%d",&a,&b);
            par[i]=a;
            val[i]=b;
        }
        printf("Case %d:\n",++kase);
        while(q--){
            scanf("%d%d",&a,&b);
            node=a;
            while(1){
                if(val[par[node]]<b) break;
                if(node==0) break;
                node=par[node];
            }
            cerr<<"----------->";
            printf("%d\n",node);
        }
    }
    return 0;
}
