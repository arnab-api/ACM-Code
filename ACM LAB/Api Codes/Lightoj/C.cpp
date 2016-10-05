#include<bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
    lli pre,nl,n,m,lev,mod;
    while(scanf("%lld",&nl)==1){
        pre = 2;
        for(lev=1;lev<=nl;lev++){
            n = pre%lev;
            n = n*n;
            m = (n*(lev+1)*(lev+1) - pre)/lev;
            pre = n*(lev+1)*(lev+1);
            printf("%lld\n",m);
        }
    }
    return 0;
}
