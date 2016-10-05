#include<bits/stdc++.h>
using namespace std;
#define ul unsigned long long

ul p,q,n,d = 3;
ul M[3][3],F[3][3],f[3];

void init()
{
    memset(M,0,sizeof(M));
    memset(F,0,sizeof(F));
    M[0][0] = p;
    M[0][1] = -q;
    M[1][0] = 1;
    M[2][1] = 1;

    F[0][0] = p;
    F[0][1] = -q;
    F[1][0] = 1;
    F[2][1] = 1;


    f[0] = 2;
    f[1] = p;
    f[2] = p*p-2*q;
}


void multiply(ul A[3][3],ul B[3][3])
{
    ul mul[3][3];
    d = 3;
    for(ul i=0; i<d; i++)
    {
        for(ul j=0; j<d; j++)
        {
            mul[i][j]=0;
            for(ul k=0; k<d; k++) mul[i][j] += (A[i][k]*B[k][j]);
        }
    }
    for(ul i=0; i<d; i++)
    {
        for(ul j=0; j<d; j++) A[i][j] = (mul[i][j]);
    }
}

void get_pow(ul power)
{
    //cout<<"==========>"<<power<<endl;
    if(power==1) return;
    get_pow(power/2);
    multiply(F,F);
    if(power & 1) multiply(F,M);
}

ul MatExpo(ul n)
{
    ul ans;
    init();
    if(n<d) ans = f[n];
    else
    {
        /*for(ul i=0;i<d;i++){
            for(ul j=0;j<d;j++) printf("   %llu",F[i][j]);
            printf("\n");
        }
        printf("=====>\n");*/
        ans=0;
        get_pow(n-d+1);
        ///*** if a0,a1,a2,a3…..ad is given then get_pow(n-d+1,m);
        /*for(ul i=0;i<d;i++){
            for(ul j=0;j<d;j++) printf("   %llu",F[i][j]);
            printf("\n");
        }*/
        for(ul i=0;i<d;i++) ans += (F[0][i]*f[d-1-i]);
    }
    return ans;
}

int main()
{
    ul t,kase=0;
    scanf("%llu",&t);
    while(t--)
    {
        scanf("%llu%llu%llu",&p,&q,&n);
        printf("Case %llu: %llu\n",++kase,MatExpo(n));
    }
    return 0;
}
/**
2
10 16 2

7 12 3
*/
