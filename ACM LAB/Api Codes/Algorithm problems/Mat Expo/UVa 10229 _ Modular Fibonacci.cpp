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
#define oo 1<<30
#define lli long long int

lli M[2][2],F[2][2];

void init()
{
    M[0][0] = F[0][0] = 1;
    M[0][1] = F[0][1] = 1;
    M[1][0] = F[1][0] = 1;
    M[1][1] = F[1][1] = 0;
}

void multiply(lli A[2][2] , lli B[2][2] , lli modulo)
{
    lli mul[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            mul[i][j]=0;
            for(int k=0;k<2;k++) {
                mul[i][j]+=(A[i][k]*B[k][j]);
            }
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++) A[i][j] = (mul[i][j]%modulo);
    }
}

lli get_pow(lli power,lli modulo)
{
    if(power==1) return 1;
    get_pow(power/2,modulo);
    multiply(F,F,modulo);
    if(power & 1) multiply(F,M,modulo);
    return F[0][0]%modulo;
}

lli Mat_Expo(lli n,lli mod)
{
    if(n==0 || n==1) return n;
    init();
    return get_pow(n-2+1,mod);
}

int main()
{
	lli i,j,k,l,t,ans;
	lli n,m;
	while(scanf("%lld%lld",&n,&m)==2){
        m = (1<<m);
        //printf("%lld %lld\n",n,m);
        ans = Mat_Expo(n,m);
        //cerr<<"---------------------->";
        printf("%lld\n",ans);
	}
	return 0;
}

