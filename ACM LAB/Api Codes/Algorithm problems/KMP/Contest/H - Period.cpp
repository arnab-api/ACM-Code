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
#define M 1000100
#define oo 1<<30

char str[M];
int lps[M];

void calcLPS()
{
    int len=strlen(str),i,j;
    i=1;
    j=0;
    lps[0]=0;
    while(i<len){
        if(str[i]==str[j]){
            lps[i]=j+1;
            i++;
            j++;
        }
        else{
            if(j!=0) j=lps[j-1];
            else {
                lps[i]=0;
                i++;
            }
        }
    }
}

int main()
{
	int i,j,k,l,t,n,kase=0,x,y;
	while(scanf("%d",&n)==1){
        if(n==0) break;
        for(i=0;i<n;i++) scanf(" %c",&str[i]);
        calcLPS();
        printf("Test case #%d\n",++kase);
        for(i=1;i<n;i++){
            x=i+1;
            y=x-lps[i];
            if(x%y==0 && x/y!=1) printf("%d %d\n",x,x/y);
        }
        printf("\n");
	}
	return 0;
}

