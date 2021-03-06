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
#define M 100
#define oo 1<<30

char pat[M],text[100010];
int lps[M];
vector<int>ans;

void calcLPS()
{
    int i,j,len=strlen(pat);
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

int KMP()
{
    calcLPS();
    int i,j,lenW,lenT;
    lenW=strlen(pat);
    lenT=strlen(text);
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
            //j=lps[j-1];
            j=0;
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
	int i,j,k,l,t,len,x,r,c,ans;
	while(scanf("%d%d",&r,&c)==2){
        ans=0;
        for(i=0;i<r;i++){
            scanf(" %s",&str);
            calcLPS();
            ans=max(ans,lps[strlen(str)-1]);
        }
        printf("%d\n",ans);
	}
	return 0;
}



