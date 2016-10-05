#include<bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
    //freopen("0in.txt","r",stdin);
    //freopen("0out.txt","w",stdout);
    double m,o,d,p,rn;
    int t,kase=0,k,c1,c2,i,j;
    long long int ans,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&c1,&c2);
        ans = 0;
        for(i=1;i<c1;i++){
            scanf("%lld",&a);
            ans += a;
        }
        scanf("%lld",&a);
        for(i=1;i<c2;i++){
            scanf("%lld",&b);
            ans += b;
        }
        scanf("%lld",&b);
        ans += min(a,b);
        printf("Case %d: %lld\n",++kase,ans);
    }
    return 0;
}

