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

vector<char>v;
int l,taken[100],n,a=1,lit;
char ara[100];
void call()
{
    if(v.size()==n){
        for(int i=0;i<n;i++) printf("%c",v[i]);
        printf("\n");
        return;
    }
    for(int i=0;i<l;i++){
        //if(v.size()>0 && v[v.size()-1]>ara[i]) continue;
        for(int j=0;j<i;j++) if(taken[j]==1) return;
        if(!taken[i]){
            taken[i]=1; v.push_back(ara[i]);
            call();
            taken[i]=0; v.pop_back();
            //while(ara[i]==ara[i+1] && i+1<l) i++;
        }
    }
}

int main()
{
    while(scanf(" %s",&ara)==1){
        scanf("%d",&n);
        l=strlen(ara);
        sort(ara,ara+l);
        v.clear();
        for(int i=0;i<l;i++) taken[i]=0;
        call();
        //printf("\n");
    }
	return 0;
}
