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
#define M 100000

int main()
{
    //freopen("highways.in","r",stdin);
    //freopen("highways.out","w",stdout);
	int i,j,k,l,t,sum=0;
	int n,a,ara[M],b,in1,in2,diff[M];
	while(scanf("%d",&n)==1){
        sum=0;
        for(i=1;i<n;i++) scanf("%d",&ara[i]);
        if(n<4) {
            printf("0\n");
            continue;
        }
        diff[1]=ara[1];
        for(i=2;i<n;i++){
            diff[i]=ara[i]-ara[i-1];
        }
        //for(i=1;i<n;i++) printf("%d ",ara[i]);
        //printf("\n");
        //for(i=1;i<n;i++) printf("%d ",diff[i]);
        int Min=INT_MAX;
        for(i=1;i<n;i++){
            sum+=diff[i];
            if(diff[i]<Min){
                Min=diff[i];
                in1=i;
                in2=i+1;
            }
        }
        sum+=Min;
        printf("%d\n",sum);
        printf("%d %d %d %d\n",in2,1,n,in1);
	}
	return 0;
}

