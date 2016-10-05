//#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<climits>
#include<cstring>
#include<cstdlib>

#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>

#include<vector>
#include<map>
#include<string>
#include<queue>
#include<set>
#include<iterator>
#include<numeric>
#include<stack>
#include<list>
using namespace std;
#define pi acos(-1)
#define M 2000010
#define ll long long int

ll phi[M],depth[M],sodf[M];

void call()
{
    ll p,k,sum=0;
    phi[1]=1;
    depth[2]=1;
    for(p=2;p<M;p++){
        if(!phi[p]){
            for(k=p;k<M;k+=p){
                if(!phi[k]) phi[k]=k;
                phi[k]=phi[k]*(p-1)/p;
            }
        }
        if(p>2) depth[p]=1+depth[phi[p]];
        sum+=depth[p];
        sodf[p]=sum;

    }
    /*depth[2]=1;
    for(p=3;p<M;p++) depth[p]=1+depth[phi[p]];
    ll sum=0;
    for(p=2;p<M;p++){
        sum+=depth[p];
        sodf[p]=sum;
    }*/
}

int main()
{
	ll i,n,a,b;
	call();
	//for(i=1;i<=20;i++) printf("%lld --> %lld %lld %lld\n",i,phi[i],depth[i],sodf[i]);
	scanf("%lld",&n);
	while(n--){
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",sodf[b]-sodf[a-1]);
	}
	return 0;
}

