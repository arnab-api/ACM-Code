#include<bits/stdc++.h>
using namespace std;
#define lli long long int

lli t,m,a,b,arr[210];

lli sum_arr[4040],s_cnt;

int main()
{
    //freopen("0in.txt","r",stdin);
    //freopen("0out.txt","w",stdout);
    lli kase = 0,ans,i,sum,maxi;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&m);
        maxi = -1;
        for(i=0;i<m;i++){
            scanf("%lld",&arr[i]);
            maxi = max(maxi,arr[i]);
        }
        scanf("%lld%lld",&a,&b);
        if(a>4*maxi) ans = 0;
        else{
            s_cnt = 0;
            a = min(a,4*maxi);
            b = min(b,4*maxi);
            mp.clear();
            for(i=0; i<m; i++){
                for(j = i ; j<m ; j++){
                    sum = arr[i]+arr[j];
                    sum_arr[s_cnt++] = sum;
                }
            }
            sort(sum_arr,sum_arr+s_cnt);
            ans = 0;
            for(i=0;i<s_cnt;i++){

            }
        }
        printf("Case %lld: %lld\n",++kase,ans);
    }
    return 0;
}


