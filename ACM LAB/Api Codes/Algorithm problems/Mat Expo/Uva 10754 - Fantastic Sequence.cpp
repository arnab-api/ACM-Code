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
#define M 25
#define oo 1<<30
#define lli long long int

lli F[M][M],c[M],a[M],k,m,n,MAT[M][M],C;

void init()
{
    memset(F,0,sizeof(F));
    memset(MAT,0,sizeof(MAT));
    for(int i=0;i<=k;i++) MAT[0][i] = F[0][i] = c[i];
    for(int i=1;i<k;i++) MAT[i][i-1] = F[i][i-1] = 1;
    F[0][k] = MAT[0][k] = 1;
    F[k][k] = MAT[k][k] = 1;
}

void multiply(lli A[M][M],lli B[M][M],lli modulo)
{
    lli mul[M][M];
    int d = k+1;
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

lli A[25];

int main()
{
    lli i,j,ans,x,t;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld",&k,&m,&n);
        for(i=0;i<=k;i++) {
            scanf("%lld",&x);
            if(x<0) x = m - ((-x)%m);
            else x = x%m;
            c[i] = x;
        }
        for(i=0;i<k;i++) {
            scanf("%lld",&x);
            if(x<0) x = m - ((-x)%m);
            else x = x%m;
            a[i] = x;
        }
        //cout<<"=====>\n";
        init();
        /*for(i=0;i<k+1;i++){
            for(j=0;j<k+1;j++) printf("%lld ",MAT[i][j]);
            printf("\n");
        }*/
        //cout<<"=====>\n";
        if(n<k) ans = a[n];
        else if(n==0) ans = c[0];
        else{
            int d = k+1;
            init();
            ans=0;
            get_pow(n-(k-1),m);
            /*for(i=0;i<d;i++){
                for(j=0;j<d;j++) printf("%lld ",F[i][j]);
                printf("\n");
            }*/
            A[0] = c[k];
            for(i=0;i<k;i++) A[i+1] = a[i];
            //for(i=0;i<d;i++) printf(">>%d ",A[i]);
            //printf("\n");
            for(i=0;i<d;i++) ans = (ans+(F[0][i]*A[d-1-i]))%m;
            ans%=m;
        }
        //cerr<<"------------------->";
        printf("%lld\n",ans);
        if(t) printf("\n");
    }
	return 0;
}

