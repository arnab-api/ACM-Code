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
#define M 35


int taken[M],Max=0,mp[M][M],vis[M][M],c,fix,row,col;
vector<int>v;

void init()
{
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++) vis[i][j]=0;
        taken[i]=0;
    }
    v.clear();
    c=0;
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

int in=0;
vector<int>save[100];

void call()
{
    if(v.size()==8){
        /*if(v[col-1]==row-1){
            printf("%2d      ",++c);
            for(int i=0;i<7;i++) printf("%d ",v[i]+1);
            printf("%d\n",v[7]+1);
        }
        */
        for(int i=0;i<8;i++) save[in].push_back(v[i]);
        in++;
        return;
    }
    for(int i=0;i<8;i++){
        if(!vis[v.size()][i]){
            mod(v.size(),i); v.push_back(i);
            call();
            v.pop_back(); antimod(v.size(),i);
        }
    }
}

int main()
{
	int i,j,k,l,t,fst=1;
	scanf("%d",&t);
	while(t--){
        scanf("%d%d",&row,&col);
        init();
        if(fst) fst=0;
        else printf("\n");
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        call();
        for(i=0;i<in;i++){
            if(save[in][col-1]==row-1){
                printf("%2d      ",++c);
                for(int j=0;j<7;j++) printf("%d ",save[i][j]+1);
                printf("%d\n",save[i][7]+1);
            }
        }
	}
	return 0;
}


