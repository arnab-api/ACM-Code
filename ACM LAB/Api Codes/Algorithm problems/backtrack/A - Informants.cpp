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

int main()
{
	int i,j,k,l,t,x,y,status[M],cnt,n,m;
	while(scanf("%d%d",&n,&m)==2){
        if(n==0 && m==0) break;
        cnt=n;
        for(i=1;i<=n;i++) status[i]=1;
        for(i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            if(y<0 && status[abs(y)]==1){
                status[abs(y)]=-1;
                cnt--;
            }
        }
        //cout<<"===>";
        printf("%d\n",cnt);
	}
	return 0;
}

