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
#define M 50

int ara[M],taken[M],n,k;
vector<int>v;

void init()
{
    for(int i=0;i<M;i++) taken[i]=0;
    v.clear();
}

void call()
{
    if(v.size()==6){
        for(int i=0;i<5;i++) printf("%d ",v[i]);
        printf("%d\n",v[5]);
        return;
    }
    for(int i=0;i<k;i++){
        int flag=1;
        for(int j=i+1;j<k;j++) if(taken[j]==1){ flag=0; break;}
        if(flag==0) continue;
        if(!taken[i]){
            v.push_back(ara[i]); taken[i]=1;
            call();
            v.pop_back(); taken[i]=0;
        }
    }
}

int main()
{
	int i,j,l,t,fst=1;
	while(scanf("%d",&k)==1){
        if(k==0) break;
        for(i=0;i<k;i++) scanf("%d",&ara[i]);
        if(fst) fst=0;
        else printf("\n");
        call();
	}
	return 0;
}
