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
#define M 400040
#define oo 1<<30

char str[M];
int lps[M];
vector<int>ans;

void calcLPS()
{
    int i,j,len=strlen(str);
    i=1; j=0;
    lps[0]=0;
    while(i<len){
        if(str[i]==str[j]){
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

int main()
{
	int i,j,k,l,t,len,x;
	while(gets(str)){
        calcLPS();
        len=strlen(str);
        ans.clear();
        x=len;
        while(x!=0){
            ans.push_back(x);
            x=lps[x-1];
        }
        for(i=ans.size()-1;i>0;i--) printf("%d ",ans[i]);
        printf("%d\n",ans[0]);
	}
	return 0;
}

