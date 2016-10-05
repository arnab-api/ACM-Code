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
#define M 10

int ara[M][M],cnt,n;
vector<int>v;

void init()
{
    cnt=0;
    v.clear();
}

int check(int x,int r,int c)
{
    for(int i=0;i<n;i++){
        if(ara[r][i]==x) return 0;
        if(ara[i][c]==x) return 0;
    }
    return 1;
}

void call()
{
    //printf("==>%d %d\n",v.size(),cnt);
    /*if(v.size()==cnt){
        cout<<"========>"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) printf("%d ",ara[i][j]);
            printf("\n");
        }
        return;
    }*/
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) if(ara[i][j]==0) c++;
    }
    printf("%d %d %d\n",c,v.size(),cnt);
    if(c==0){
        cout<<"========>"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) printf("%d ",ara[i][j]);
            printf("\n");
        }
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!ara[i][j]){
                for(int k=1;k<=n;k++){
                    if(check(k,i,j)==1){
                        ara[i][j]=k; v.push_back(k);
                        call();
                        ara[i][j]=0; v.pop_back();
                    }
                }
            }
        }
    }
}

int main()
{
	int i,j,k,l,t;
	while(scanf("%d",&n)==1){
        n=n*n;
        init();
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&ara[i][j]);
                if(ara[i][j]==0) cnt++;
            }
        }
        call();
	}
	return 0;
}

