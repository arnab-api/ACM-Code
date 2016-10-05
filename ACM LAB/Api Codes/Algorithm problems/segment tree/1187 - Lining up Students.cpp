#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,ans,i,a,kase=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ans=1;
        scanf("%d",&a);
        for(i=2;i<=n;i++){
            scanf("%d",&a);
            if(i-a <= ans) ans++;
        }
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}
