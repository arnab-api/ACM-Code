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
#define M 8


int taken[M],Max=0,mp[M][M],vis[M][M];

void init()
{
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++) vis[i][j]=0;
        taken[i]=0;
    }

    Max=0;
}

void mod(int x,int y)
{
    vis[x][y]+=1;
    for(int i=0;i<8;i++){
        vis[x][i]+=1;
        vis[i][y]+=1;
    }
    int a,b;
    a=x-1; b=y-1;
    while(a>=0 && b>=0){
        vis[a][b]+=1;
        a--; b--;
    }
    a=x+1; b=y+1;
    while(a<8 && b<8){
        vis[a][b]+=1;
        a++; b++;
    }
    a=x-1; b=y+1;
    while(a>=0 && b<8){
        vis[a][b]+=1;
        a--; b++;
    }
    a=x+1; b=y-1;
    while(a<8 && b>=0){
        vis[a][b]+=1;
        a++; b--;
    }
}

void antimod(int x,int y)
{
    vis[x][y]-=1;
    for(int i=0;i<8;i++){
        vis[x][i]-=1;
        vis[i][y]-=1;
    }
    int a,b;
    a=x-1; b=y-1;
    while(a>=0 && b>=0){
        vis[a][b]-=1;
        a--; b--;
    }
    a=x+1; b=y+1;
    while(a<8 && b<8){
        vis[a][b]-=1;
        a++; b++;
    }
    a=x-1; b=y+1;
    while(a>=0 && b<8){
        vis[a][b]-=1;
        a--; b++;
    }
    a=x+1; b=y-1;
    while(a<8 && b>=0){
        vis[a][b]-=1;
        a++; b--;
    }
}

void call(int cnt,int val)
{
    if(cnt==8){
        //printf("%d\n",val);
        if(val>Max) Max=val;
        return;
    }
    for(int i=0;i<8;i++){
        if(!vis[cnt][i]){
            mod(cnt,i);
            call(cnt+1,val+mp[cnt][i]);
            antimod(cnt,i);
        }
    }
}

int main()
{
	int i,j,k,l,t;
	scanf("%d",&t);
	while(t--){
        for(i=0;i<8;i++){
            for(j=0;j<8;j++) scanf("%d",&mp[i][j]);
        }
        init();
        call(0,0);
        //cout<<"====>";
        printf("%5d\n",Max);
	}
	return 0;
}

