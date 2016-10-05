#include<bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
    lli lev,n,pre,k;
    while(scanf("%lld",&n)==1){
        pre = 2;
        for(lev = 1 ; lev<=n; lev++){
            k = lev*(lev+1)*(lev+1) - pre/lev;
            pre = lev*(lev+1);
            printf("%lld\n",k);
        }
    }
    return 0;
}
