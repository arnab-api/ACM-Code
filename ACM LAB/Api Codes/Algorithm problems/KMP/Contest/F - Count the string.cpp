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
#define M 200100
#define oo 1<<30
#define lli long long int

char pat[M];
lli n,lps[M],cnt,vis[M];

void computeLPS()
{
    memset(lps,-1,sizeof(lps));
    lli i,j;
    lps[0]=0;
    i=1; j=0;
    while(i<n){
        if(pat[i]==pat[j]){
            lps[i]=j+1;
            i++;
            j++;
        }
        else{
            if(j!=0) j=lps[j-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    //for(i=0;i<n;i++) printf("%lld",lps[i]);
    //printf("\n");
}

int main()
{
    lli ans,cnt,i,x,y,j,t;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        scanf(" %s",pat);
        cnt=0;
        ans=n;
        computeLPS();
        memset(vis,0,sizeof(vis));
        for(i=n-1;i>=0;i--){
            if(vis[i]) continue;
            vis[i]=1;
            cnt=0;
            j=i+1;
            //printf("%lld",i);
            while(j!=0){
                //printf(" >> %lld ",j);
                j=lps[j-1];
                vis[j-1]=1;
                cnt++;
            }
            cnt--;
            ans+=(cnt*(cnt+1))/2;
            ans%=10007;
            //printf("\n");
        }
        //cerr<<"--------------------->";
        printf("%lld\n",ans);
    }
    return 0;
}
