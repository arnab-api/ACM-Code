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
#define M 7
#define oo 1<<30
#define lli long long int
lli F[M][M],MAT[M][M],a1,b1,c1,a2,b2,c2,mod,Fn,Gn;
lli f0,f1,f2;
lli g0,g1,g2;

void init()
{
    memset(F,0,sizeof(F));
    memset(MAT,0,sizeof(MAT));
    F[0][0] = MAT[0][0] = a1;
    F[0][1] = MAT[0][1] = b1;
    F[0][5] = MAT[0][5] = c1;
    F[1][0] = MAT[1][0] = 1;
    F[2][1] = MAT[2][1] = 1;
    F[3][2] = MAT[3][2] = c2;
    F[3][3] = MAT[3][3] = a2;
    F[3][4] = MAT[3][4] = b2;
    F[4][3] = MAT[4][3] = 1;
    F[5][4] = MAT[5][4] = 1;
    /*cout<<endl;
    for(int i=0;i<6;i++) {
        for(int j=0; j<6; j++) printf("%d ",F[i][j]);
        printf("\n");
    }*/
}

void multiply(lli A[M][M],lli B[M][M],lli modulo)
{
    lli mul[M][M];
    int d = 7;
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

int main()
{
    int test,kase=0,q,n;
    scanf("%d",&test);
    while(test--){
        scanf("%lld%lld%lld",&a1,&b1,&c1);
        scanf("%lld%lld%lld",&a2,&b2,&c2);
        scanf("%lld%lld%lld",&f0,&f1,&f2);
        scanf("%lld%lld%lld",&g0,&g1,&g2);
        scanf("%lld",&mod);
        scanf("%d",&q);
        printf("Case %d:\n",++kase);
        while(q--){
            scanf("%d",&n);
            //cerr<<"---------------------->";
            if(n==0) printf("%lld %lld\n",f0%mod,g0%mod);
            else if(n==1) printf("%lld %lld\n",f1%mod,g1%mod);
            else if(n==2) printf("%lld %lld\n",f2%mod,g2%mod);
            else{
                init();
                get_pow(n-3+1,mod);
                Fn = F[0][0]*f2 + F[0][1]*f1 + F[0][2]*f0 + F[0][3]*g2 + F[0][4]*g1 + F[0][5]*g0;
                Gn = F[3][0]*f2 + F[3][1]*f1 + F[3][2]*f0 + F[3][3]*g2 + F[3][4]*g1 + F[3][5]*g0;
                printf("%lld %lld\n",Fn%mod,Gn%mod);
            }
        }
    }
    return 0;
}
