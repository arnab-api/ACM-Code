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

lli M[2][2],F[2][2],a,b,n,m,mod;

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

void get_pow(lli power,lli modulo)
{
    if(power==1) return;
    get_pow(power/2,modulo);
    multiply(F,F,modulo);
    if(power & 1) multiply(F,M,modulo);
}

lli MAT_EXPO(lli n)
{
    if(n==0) return a;
    if(n==1) return b;
    init();
    get_pow(n-2+1,mod);
    return (F[0][0]*b + F[0][1]*a)%mod;
}

int main()
{
	int i,j,k,l,t,kase=0;
	scanf("%d",&t);
	while(t--){
        scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
        mod = 1;
        for(i=1;i<=m;i++) mod*=10;
        lli ans = MAT_EXPO(n);
        printf("Case %d: %lld\n",++kase,ans);
	}
	return 0;
}

