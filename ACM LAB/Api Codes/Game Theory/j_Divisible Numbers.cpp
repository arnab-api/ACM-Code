#include<bits/stdc++.h>
using namespace std;
#define MX 100000+7

int bitOn(int N,int pos) { return N | (1<<pos);}
int bitOff(int N,int pos){ return N & ~(1<<pos);}
bool bitcheck(int N,int pos) { return N & (1<<pos);}

int main()
{
    int N,Q,t,i,j,a,msk,b,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&N,&Q);
        int mask[N+7],pre[515][N+7];
        memset(mask,0,sizeof(mask));
        for(i=1;i<=N;i++) {
            scanf("%d",&a);
            msk = 0;
            for(j=2;j<=10;j++) if(a%j == 0) msk = bitOn(msk,j-2);
            mask[i] = msk;
        }
        memset(pre,0,sizeof(pre));
        for(j=1;j<512;j++){
            for(i=1;i<=N;i++) pre[j][i] = pre[j][i-1] + ((mask[i] & j) > 0);
        }
        while(Q--){
            scanf("%d%d%d",&a,&b,&msk);
            if(msk&1) ans = b - a + 1;
            else {
                msk>>=1;
                ans = pre[msk][b] - pre[msk][a - 1];
            }
            //cerr<<"------------------->>> ";
            printf("%d\n",ans);
        }
    }
    return 0;
}

