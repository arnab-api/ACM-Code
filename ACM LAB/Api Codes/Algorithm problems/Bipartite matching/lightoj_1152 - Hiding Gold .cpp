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
#define M 700
#define oo 1<<30

struct jora{
    int x,y;
};

int fx[]={-1,0,1,0};
int fy[]={0,1,0,-1};


int n,m,grid[M][M],in,val[M][M],Right[M],Left[M],used[M],par[M];
vector<int>edge[M];
jora ara[M];

void init()
{
    memset(val,0,sizeof(val));
    in=1;
    for(int i=0;i<M;i++) {
        edge[i].clear();
        Right[i]=-1;
        Left[i]=-1;
        par[i]=-1;
    }
}

int match(int u)
{
    if(used[u]==1) return 0;
    used[u]=1;
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if(Left[v]==-1 || match(Left[v])){
            //if(Right[v]!=-1) continue;
            Left[v]=u;
            Right[u]=v;
            return 1;
        }
    }
    return 0;
}

int BPM()
{
    int ans=0, path=1;
    while(path){
        path=0;
        memset(used,0,sizeof(used));
        for(int i=1;i<in;i++){
            if(!used[i] && Right[i]==-1){
            //if(!Right[i] && match(i)){
                path+=match(i);
            }
        }
    }
    //for(int i=1;i<in;i++) printf("----->%d %d %d\n",i,Left[i],Right[i]);
    for(int i=1;i<in;i++) if(Right[i]!=-1) ans++;
    //for(int i=1;i<in;i++) if(Right[i]==-1 && Left[i]==-1) ans++;
    return ans/2;
}


int main()
{
    //freopen("0A1.txt","w",stdout);
    jora A,B;
    int i,j,k,l,t,kase=0;
	scanf("%d",&t);
	char ch;
	while(t--){
        init();
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf(" %c",&ch);
                if(ch=='*') {
                    grid[i][j]=1;
                    val[i][j]=in;
                    A.x=i; A.y=j;
                    ara[in]=A;
                    in++;
                }
                else grid[i][j]=0;
            }
        }
        for(i=1;i<in;i++) {
            A=ara[i];
            //printf("%d-->(%d %d) ",i,A.x,A.y);
            for(k=0;k<4;k++){
                int nx=A.x+fx[k];
                int ny=A.y+fy[k];
                if(nx>=1 && nx<=n && ny>=1 && ny<=m && val[nx][ny]>0){
                    for(j=1;j<in;j++){
                        if(j==i) continue;
                        B=ara[j];
                        if(B.x==nx && B.y==ny){
                            //printf(" %d(%d %d)",j,ara[j].x,ara[j].y);
                            edge[i].push_back(j);
                            //printf("(%d)(%d)",i,j);
                            break;
                        }
                    }
                }
            }
            //printf("\n");
        }
        /*for(i=1;i<in;i++){
            printf("%d --> ",i);
            for(j=0;j<edge[i].size();j++) printf(" %d",edge[i][j]);
            printf("\n");
        }*/
        //cout<<"------------------------------->";
        //printf("Case %d: %d\n",++kase,BPM());
        printf("Case %d: %d\n",++kase,in-1-BPM());
	}
	return 0;
}

