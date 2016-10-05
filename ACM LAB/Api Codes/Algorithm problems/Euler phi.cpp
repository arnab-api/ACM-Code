#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define M 5000000

ll phi[M];

void call()
{
    ll p,k;
    phi[1]=1;
    for(p=2;p<=M;p++){
        if(!phi[p]){
            for(k=p;k<=M;k+=p){
                if(!phi[k]) phi[k]=k;
                phi[k]=phi[k]*(p-1)/p;
            }
        }
    }
}

int main()
{
    ll n,i;
    call();
    for(i=1;i<=500;i++) cout<<i<<"-->"<<phi[i]<<endl;
    while(scanf("%llu",&n)==1){
        cout<<phi[n];
    }
    return 0;
}
