#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;

int taken[20],n,p;
vector<int>v;
int prime[]={1,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0};

void call()
{
    if(!v.empty() && v[0]!=1) return;
    int r=1,p;
    if(v.size()==n){
        for(int i=1;i<n;i++) if(prime[v[i]+v[i-1]]==0){
            r=0;
            break;
        }
        if(prime[v[0]+v[n-1]]==0) r=0;
        if(r==1){
            for(int i=0;i<n-1;i++) printf("%d ",v[i]);
            printf("%d\n",v[n-1]);
        }
        return ;
    }
    int a=1;
    for(int i=1;i<=n;i++){
        if(v.size()>1) for(int j=1;j<v.size();j++) if(prime[v[j]+v[j-1]]==0){
            a=0;
            break;
        }
        if(!taken[i] && a==1){
            taken[i]=1; v.push_back(i);
            call();
            taken[i]=0; v.pop_back();
        }
    }
}
int main()
{
    int c=0;
    while(scanf("%d",&n)==1){
        if(c!=0)printf("\n");
        c++;
        printf("Case %d:\n",c);
        call();
    }
	return 0;
}
