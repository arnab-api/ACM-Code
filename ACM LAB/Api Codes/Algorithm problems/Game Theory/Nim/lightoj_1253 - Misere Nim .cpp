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
	int i,j,k,l,t,n,flag,val,a,kase=0;
	scanf("%d",&t);
	while(t--){
        scanf("%d",&n);
        val=0;
        flag=1;
        for(i=0;i<n;i++){
            scanf("%d",&a);
            if(a>1) flag=2;
            val^=a;
        }
        printf("Case %d: ",++kase);
        if((flag==1 && n%2!=0) || (flag==2 && val==0)) printf("Bob\n");
        else printf("Alice\n");
	}
	return 0;
}

