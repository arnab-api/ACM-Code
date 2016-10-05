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
#define M 5
#define oo 1<<30
#define lli long long int
lli F[M][M],MAT[M][M],a,b,c;

void init()
{
    memset(F,0,sizeof(F));
    memset(MAT,0,sizeof(MAT));
    F[0][0] = MAT[0][0] = a;
    F[0][2] = MAT[0][2] = b;
    F[0][3] = MAT[0][3] = 1;
    F[1][0] = MAT[1][0] = 1;
    F[2][1] = MAT[2][1] = 1;
    F[3][3] = MAT[3][3] = 1;

    /*for(int i=0;i<4;i++) {
        for(int j=0; j<4; j++) printf("%d ",F[i][j]);
        printf("\n");
    }*/
}

void multiply(lli A[M][M],lli B[M][M],lli modulo)
{
    lli mul[M][M];
    int d = 4;
    for(int i=0;i<d;i++){
        for(int j=0;j<d;j++){
            mul[i][j]=0;
            for(int k=0;k<d;k++) mul[i][j] = (mul[i][j]+(A[i][k]*B[k][j]))%modulo;
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
    if(power & 1) multiply(F,MAT,modulo);
}

lli MAT_Expo(lli n)
{
    if(n<=2) return 0;
    init();
    get_pow(n-3+1,10007);
    /*for(int i=0;i<4;i++) {
        for(int j=0; j<4; j++) printf("%d ",F[i][j]);
        printf("===>\n");
    }*/
    return (F[0][3]*c)%10007;
}

int main()
{
    int test,kase=0;
    scanf("%d",&test);
    while(test--){
        lli n;
        scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
        lli ans = MAT_Expo(n);
        printf("Case %d: %lld\n",++kase,ans);
    }
    return 0;
}
