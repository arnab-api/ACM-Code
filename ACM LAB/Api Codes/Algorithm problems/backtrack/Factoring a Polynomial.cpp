
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
#define M  1010

int prime[M],in=0;
bool con[M];

void select(int p)
{
    for(int i=p+p;i<M;i+=p) con[i]=true;
}

void sieve()
{
    con[0]=con[1]=true;
    con[2]=false;
    select(2);
    for(int i=3;i*i<=M;i+=2) if(!con[i]) select(i);
    for(int i=0;i<M;i++) if(!con[i]) prime[in++]=i;
}

int main()
{
    sieve();
    for(int i=0;i<in;i++) printf("%d--> %d\n",i,prime[i]);
	int i,j,k,l,t;
	return 0;
}
