#include<bits/stdc++.h>
using namespace std;
#define M 10

int DP[1<<10];
int Set(int N,int pos) {return N=N|(1<<pos);}
bool Check(int N,int pos) {return (bool)(N & (1<<pos));}
int lim,n,ara[M+5];

int call(int mask,int *ara,int in)
{
    if(mask>=lim-1){
        for(int i=0;i<in;i++) printf("%d ",ara[i]);
        printf("\n");
        return 1;
    }
    //if(DP[mask]!=-1) return DP[mask];
    int s;
    for(int i=0;i<n;i++){
        if(!Check(mask,i)){
            ara[in]=i;
            s+=call(Set(mask,i),ara,in+1);
        }
    }
    return DP[mask]=s;
}

int main()
{
    while(scanf("%d",&n)==1){
        lim=(1<<n);
        memset(DP,-1,sizeof(DP));
        call(0,ara,0);
    }
    return 0;
}
