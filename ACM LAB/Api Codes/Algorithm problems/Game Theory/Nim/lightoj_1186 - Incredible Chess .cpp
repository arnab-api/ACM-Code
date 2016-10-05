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

int main()
{
	int i,j,k,l,t,n,B[110],W[110],val,kase=0;
	scanf("%d",&t);
	while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&W[i]);
        for(i=0;i<n;i++) scanf("%d",&B[i]);
        val=0;
        for(i=0;i<n;i++) val^=B[i]-W[i]-1;
        printf("Case %d: ",++kase);
        if(val==0) printf("black wins\n");
        else printf("white wins\n");
	}
	return 0;
}

