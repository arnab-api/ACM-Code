#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define ui unsigned int

lli n,k,d;
lli a[55];
lli nCr[55][55];

struct Matrix{
    ui mat[55][55];
    Matrix operator*(const Matrix &m)const{
        Matrix tmp;
        for(int i = 0 ; i < d ; i++){
            for(int j = 0 ; j < (k+2) ; j++){
                tmp.mat[i][j] = 0;
                for(int t = 0 ; t < d ; t++)
                    tmp.mat[i][j] += mat[i][t]*m.mat[t][j];
            }
        }
        return tmp;
    }
};

Matrix M,F;

lli calc_nCr(int n,int r)
{
    if(r>n) return 0;
    if(r==0) return 1;
    if(n==r) return 1;
    if(nCr[n][r]!=-1) return nCr[n][r] ;
    return nCr[n][r] = (calc_nCr(n-1,r)+calc_nCr(n-1,r-1)) ;
}


void init()
{
    memset(M.mat,0,sizeof(M.mat));
    memset(F.mat,0,sizeof(F.mat));
    for(int i=0; i<=k+1; i++)
    {
        ui r = 0;
        ui n;
        if(i<=1) n = k;
        else n = k-(i-1);
        for(int j=i; j<=k+1; j++)
        {
            if(i==0 && j==0) M.mat[i][j] = F.mat[i][j] = 1;
            else
            {
                M.mat[i][j] = F.mat[i][j] = calc_nCr(n,r);
                r++;
            }
        }
    }
    ui r = 0;
    for(int i=0; i<=k; i++)
    {
        a[i] = 1;
        r+=a[i];
    }
    a[k+1] = 1;
}


void get_pow(lli power)
{
    if(power==1) return;
    get_pow(power/2);
    F = F*F;
    if(power & 1) F = F*M;
}

ui MatExpo(lli n)
{
    ui ans;
    d = k+2;
    init();
    if(n==1) return 1;
    ans=0;
    get_pow(n-1);
    for(lli i=0; i<d; i++)
    {
        ans += (F.mat[0][i]*a[d-1-i]);
    }
    return ans;
}

int main()
{
    //cout<<mod<<endl;
    memset(nCr,-1,sizeof(nCr));
    //while(scanf("%lld%lld",&n,&k)==2) printf("------------> %lld\n",calc_nCr(n,k));
    lli kase=0,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&k);
        printf("Case %lld: %u\n",++kase,MatExpo(n));
    }
    return 0;
}
