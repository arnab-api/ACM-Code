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

int pat[M],text[M],ara[M];
int lps[M];

void calcLPS(int len)
{
    int i,j;
    i=1; j=0;
    lps[0]=0;
    while(i<len){
        if(pat[i]==pat[j]){
            lps[i]=j+1;
            i++; j++;
        }
        else{
            if(j!=0) j=lps[j-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    //for(i=0;i<len;i++) printf("%d ",lps[i]);
    //printf("\n");
}

int KMP(int lenW,int lenT)
{
    calcLPS(lenW);
    int i,j;
    i=0; j=0;
    int cnt=0;
    while(i<lenT){
        if(text[i]==pat[j]){
            i++;
            j++;
        }
        if(j==lenW){
            cnt++;
            //printf("pattern found at %d\n",i-j);
            j=lps[j-1];
        }
        else if(i<lenT && text[i]!=pat[j]){
            if(j!=0) j=lps[j-1];
            else i++;
        }
    }
    return cnt;
}

int main()
{
    int n,m,i,j,ans;
    while(scanf("%d%d",&n,&m)==2){
        for(i=0;i<n;i++) scanf("%d",&ara[i]);
        for(i=1;i<n;i++) text[i-1]=ara[i]-ara[i-1];

        for(i=0;i<m;i++) scanf("%d",&ara[i]);
        for(i=1;i<m;i++) pat[i-1]=ara[i]-ara[i-1];

        /*for(i=0;i<n-1;i++) printf("%d ",text[i]);
        printf("\n");
        for(i=0;i<m-1;i++) printf("%d ",pat[i]);
        printf("\n");*/
        if(m>n) ans=0;
        else if(m==1) ans=n;
        else ans=KMP(m-1,n-1);

        //cerr<<"------------>";
        printf("%d\n",ans);
    }
    return 0;
}
