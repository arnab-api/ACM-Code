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
#define M 15

int n,k,adj[M][M],taken[M],flag;
vector<int>v;

void call()
{
    if(v.size()==k+1){
        flag=1;
        printf("(");
        for(int i=0;i<k;i++) printf("%d,",v[i]);
        printf("%d)\n",v[k]);
        return;
    }
    int x=v[v.size()-1];
    for(int i=1;i<=n;i++){
        if(adj[x][i]==1 && !taken[i]){
            v.push_back(i); taken[i]=1;
            call();
            v.pop_back(); taken[i]=0;
        }
    }
}

int main()
{
	int i,j,t;
	while(scanf("%d",&n)==1){
        if(n==-9999) {printf("\n"); continue;}
        scanf("%d",&k);
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++) scanf("%d",&adj[i][j]);
        }
        v.clear();
        for(i=0;i<M;i++) taken[i]=0;
        flag=0;
        taken[1]=1;
        v.push_back(1);
        call();
        if(!flag) printf("no walk of length %d\n",k);
	}
	return 0;
}

