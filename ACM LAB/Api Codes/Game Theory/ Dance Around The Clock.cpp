#include<bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
    lli D,K,N,c,cc;
    while(scanf("%lld%lld%lld",&D,&K,&N)==3){
        N = N % D;
        if(K & 1){
            K = K + 2*N;
            if(K>D) K%=D;
            c = K+1;
            cc = K-1;
            if(c>D) c = c - D;
            if(cc==0) cc = D;
        }
        else{
            K = K - 2*N;
            if(K<=0) {
                K = K%D;
                K+=D;
            }
            cc = K-1;
            c = K+1;
            if(c>D) c = c - D;
            if(cc==0) cc = D;
        }
        printf("%lld %lld\n",c,cc);
    }
    return 0;
}
