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
#define M 30

struct order{
    int str,dst,pass;
};
order ara[M];
int cap,n,m,avail[M],taken[M],Max=0;
vector<int>v;
void init()
{
    for(int i=0;i<M;i++){
        avail[i]=cap;
        taken[i]=0;
    }
    v.clear();
    Max=0;
}

int con(int x)
{
    for(int i=ara[x].str;i<ara[x].dst;i++) if(avail[i]<ara[x].pass) return 0;
    return 1;
}

void mod(int x)
{
    for(int i=ara[x].str;i<ara[x].dst;i++) avail[i]-=ara[x].pass;
}

void antimod(int x)
{
    for(int i=ara[x].str;i<ara[x].dst;i++) avail[i]+=ara[x].pass;
}

void call()
{
    int sum=0;
    for(int i=0;i<m;i++){
        if(taken[i]==1){
            sum+=(ara[i].dst-ara[i].str)*ara[i].pass;
        }
    }
    printf(" %d ----->",sum);
    for(int i=0;i<v.size();i++) printf("%d",v[i]);
    printf("\n");
    if(sum>Max) Max=sum;
    for(int i=0;i<m;i++){
        int flag=1;
        for(int j=i+1;j<m;j++) if(taken[j]==1){ flag=0; break;}
        if(flag==0) continue;
        if(!taken[i] && con(i)==1){
            taken[i]=1; mod(i);
            v.push_back(i);
            call();
            taken[i]=0; antimod(i);
            v.pop_back();
        }
    }
}

int main()
{
	int i,j,k,l,t;
	order A;
	while(scanf("%d%d%d",&cap,&n,&m)){
        if(cap==0 && n==0 && m==0) break;
        for(i=0;i<m;i++){
            scanf("%d%d%d",&A.str,&A.dst,&A.pass);
            ara[i]=A;
        }
        init();
        //for(int i=0;i<m;i++) printf("%d==> %d %d %d\n",i,ara[i].str,ara[i].dst,ara[i].pass);
        call();
        //cout<<"====>";
        printf("%d\n",Max);
	}
	return 0;
}

