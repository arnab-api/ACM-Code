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
#define M 25

int ara[M],taken[M],n,t,Min;
vector<int>v,ans;

void init()
{
    for(int i=0;i<M;i++) taken[i]=0;
    v.clear();
    ans.clear();
    Min=n;
}

void call()
{
    int sum=0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
        if(sum>n) return;
    }
    if(Min>n-sum){
        Min=n-sum;
        ans.clear();
        for(int i=0;i<v.size();i++) ans.push_back(v[i]);
    }
    for(int i=0;i<t;i++){
        int flag=1;
        for(int j=i+1;j<t;j++) if(taken[j]==1){ flag=0; break;}
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
	int i,j,l,fst=1,sum;
	while(scanf("%d",&n)==1){
        scanf("%d",&t);
        for(i=0;i<t;i++) scanf("%d",&ara[i]);
        init();
        call();
        sum=0;
        for(int i=0;i<ans.size();i++) {
            printf("%d ",ans[i]);
            sum+=ans[i];
        }
        printf("sum:%d\n",sum);
	}
	return 0;
}
