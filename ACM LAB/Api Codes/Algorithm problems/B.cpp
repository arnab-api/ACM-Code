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
#define M 30
#define oo 1<<30

int ara[M];

int main()
{
	int i,j,k,l,t;
	char str[M];
	while(scanf("%d",&t)==1){
        memset(ara,0,sizeof(ara));
        while(t--){
            scanf(" %s",&str);
            l=strlen(str);
            for(i=0;i<l;i++) ara[str[i]-'a']++;
        }
        for(i=0;i<26;i++) if(ara[i]!=0) printf("%c",i+'a');
        printf("\n");
	}
	return 0;
}

