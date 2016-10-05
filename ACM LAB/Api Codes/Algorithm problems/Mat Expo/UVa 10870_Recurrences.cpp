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
#define lli long long int
#define oo 1<<30

lli n,m,a[17],f[17],d;
lli F[17][17],M[17][17];

void init()
{
    memset(F,0,sizeof(F));
    memset(M,0,sizeof(M));
    for(int i=0;i<d;i++) F[0][i] = M[0][i] = a[i];
    for(int i=1;i<d;i++) F[i][i-1] = M[i][i-1] = 1;
}

void multiply(lli A[17][17],lli B[17][17],lli modulo)
{
    lli mul[17][17];
    for(int i=0;i<d;i++){
        for(int j=0;j<d;j++){
            mul[i][j]=0;
            for(int k=0;k<d;k++) mul[i][j] += (A[i][k]*B[k][j]);
        }
    }
    for(int i=0;i<d;i++){
        for(int j=0;j<d;j++) A[i][j] = (mul[i][j]%modulo);
    }
}

void get_pow(lli power,lli modulo)
{
    if(power==1) return;
    get_pow(power/2,modulo);
    multiply(F,F,modulo);
    if(power & 1) multiply(F,M,modulo);
}

int main()
{
	lli i,j,k,l,t,ans;
	while(scanf("%lld%lld%lld",&d,&n,&m)==3){
        if(d==0 && n==0 && m==0) break;
        for(i=0;i<d;i++) scanf("%lld",&a[i]);
        for(i=0;i<d;i++) scanf("%lld",&f[i]);

        if(n<=d) ans = f[n-1]%m;
        else{
            init();
            ans=0;
            get_pow(n-d,m);
            for(i=0;i<d;i++) ans += (F[0][i]*f[d-1-i])%m;
            ans%=m;
        }
        //cerr<<"------------------->";
        printf("%lld\n",ans);
	}
	return 0;
}

/**
2 11 111111
1 1
1 1

2 10 111111
1 1
1 1
**/
