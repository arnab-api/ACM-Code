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
#define M

int ara[10],taken[10],stat[10],flag=0;

void call(int cnt,int val)
{
    if(cnt==5){
        if(abs(val)==23) flag=1;
        return;
    }
    for(int i=0;i<5;i++){
        if(!taken[i]){
            taken[i]=1;
            call(cnt+1,val+ara[i]);
            call(cnt+1,val-ara[i]);
            call(cnt+1,val*ara[i]);
            taken[i]=0;
        }
    }
}

int main()
{
	int i,j,k,l,t;
	while(scanf("%d%d%d%d%d",&ara[0],&ara[1],&ara[2],&ara[3],&ara[4])){
        if(ara[0]==0 && ara[1]==0 && ara[2]==0 && ara[3]==0 && ara[4]==0) break;
        flag=0;
        //call(0,0);
        for(i=0;i<5;i++){
            taken[i]=1;
            call(1,ara[i]);
            taken[i]=0;
        }
        if(!flag) printf("Impossible\n");
        else printf("Possible\n");
	}
	return 0;
}

