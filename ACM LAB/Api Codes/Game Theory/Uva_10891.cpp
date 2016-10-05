#include<bits/stdc++.h>
using namespace std;
#define MAX 110
#define lli long long int

lli DP[MAX][MAX],n,arr[MAX];

lli bestMove(lli i,lli j)
{
    //cout<<"------------------->> called  "<<i<<"  "<<j<<endl;
    if(i>j) return 0;
    if(i == j) return arr[i];
    lli &ret = DP[i][j];
    if(ret!=-1) return ret;
    lli move1 = -INT_MAX;
    lli move2 = -INT_MAX;
    lli k;
    lli sum = 0;
    for(k = 0;k<=j-i;k++) {
        sum += arr[i+k];
        move1 = max(move1,sum - bestMove(i+k+1,j));
    }
    sum = 0;
    for(k = 0;k<=j-i;k++) {
        sum += arr[j-k];
        move2 = max(move2,sum - bestMove(i,j-k-1));
    }
    return ret = max(move1,move2);
}

int main()
{
    while(scanf("%lld",&n)==1){
        if(n == 0) break;
        for(lli i=0;i<n;i++) scanf("%lld",&arr[i]);
        memset(DP,-1,sizeof(DP));
        //cout<<n<<endl;
        lli ans = bestMove(0,n-1);
        //cerr<<"--------------- >  ";
        printf("%lld\n",ans);
    }
    return 0;
}
/**
4
4 -10 -20 7
4
1 2 3 4
0
*/
