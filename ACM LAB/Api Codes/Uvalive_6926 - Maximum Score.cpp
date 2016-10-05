#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007

map<lli,lli>mp;
map<lli,lli>:: iterator it;

int main()
{
    lli t,kase=0,p,a,f;
    lli Max,per,sum;
    scanf("%lld",&t);
    while(t--){
        mp.clear();
        scanf("%lld",&p);
        while(p--){
            scanf("%lld%lld",&a,&f);
            if(mp.find(a)==mp.end()) mp[a] = f;
            else mp[a]+=f;
        }
        per = 1;
        Max = 0;
        sum = 0;
        for(it = mp.begin() ; it!=mp.end() ; it++){
            sum += it -> second;
            Max += (it->second)*sum;
            per = (per*(it->second + 1))%MOD;
        }
        printf("Case %lld: %lld %lld\n",++kase,Max,per%MOD);
    }
    return 0;
}
