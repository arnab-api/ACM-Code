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
	int i,j,k,l,t,n,r,c,s,a,b,val,kase=0;
	scanf("%d",&t);
	while(t--){
        scanf("%d%d",&r,&c);
        val=0;
        for(i=0;i<r;i++){
            s=0;
            for(j=0;j<c;j++){
                scanf("%d",&a);
                s+=a;
            }
            val^=s;
        }
        printf("Case %d: ",++kase);
        if(val) printf("Alice\n");
        else printf("Bob\n");
	}
	return 0;
}



