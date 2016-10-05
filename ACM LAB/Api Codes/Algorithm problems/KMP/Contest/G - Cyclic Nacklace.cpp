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
#define M 100010

char pat[M];
int lps[M];

int calcLPS()
{
	int i=1,j=0,ret;
	lps[0]=0;
	int len=strlen(pat);
	while(i<len){
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
	ret=len-lps[len-1];
	if(ret!=len && len%ret==0) return 0;
	return ret-len%ret;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        scanf(" %s",&pat);
        printf("%d\n",calcLPS());
    }
    return 0;
}
