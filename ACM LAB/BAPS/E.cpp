#include<bits/stdc++.h>
using namespace std;
#define lli long long int
const lli mod =  1000000007;

lli bigmod(lli base,lli power,lli modulo)
{
    lli r=1;
    while(power>0){
        if(power%2==1) r=(r*base)%modulo;
        power/=2;
        base=(base*base)%modulo;
    }
    return r;
}

int main()
{
    //freopen("0in.txt","r",stdin);
    //freopen("0out.txt","w",stdout);
    lli t,n,m,ans;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&m,&n);
        if(m<2){
            ans = n*(n-1)%mod;
        }
        else{
            ans = n*(n-1);
            ans %= mod;
            lli val = n*(n-1) - (n-1)*(n-2);
            ans = ans*(bigmod(val,m-2,mod));
            ans = ans%mod;
        }
        cerr<<"--------------->  ";
        printf("%lld\n",ans);
    }
    return 0;
}


