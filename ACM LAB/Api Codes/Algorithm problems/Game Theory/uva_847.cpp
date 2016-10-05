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
#define oo 1<<30
#define ll long long int

ll ara[100],n,in=0;

ll call(ll p)
{
    printf("--->%lld\n",p);
    if(p*9>n) return 1;
    else if(p*18>n) return 0;
    for(int i=2;i<=9;i++) if(call(p*i)==0) return 1;
    //return 0;
}

int main()
{
	ll i,j,k,l,t,ret;
	for(i=2;i<=9;i++){
        for(j=2;j<=9;j++) ara[in++]=i*j;
	}
	while(scanf("%lld",&n)==1){
        ret=call(1);
        cout<<"--------------->"<<ret<<endl;
        //if(ret==1) printf("Stan wins.\n");
        //else printf("Ollie wins.\n");
	}
	return 0;
}

