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
#define M 220
#define oo 1<<30

int used[M],A[M],B[M],n,m,par[M],ans;
vector<int>edge[M];

void init()
{
    for(int i=0;i<M;i++){
        used[i]=0;
        par[i]=-1;
        edge[i].clear();
    }
    ans=0;
}

int match(int u)
{
    if(used[u]==1) return 0;
    used[u]=1;
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if(par[v]==-1 || match(par[v])){
            par[u]=v;
            par[v]=u;
            return 1;
        }
    }
    return 0;
}
/*int match(int u){
		if(used[u]==true)
			return false;
		used[u]=true;
		for(int i=0;i<edge[u].size();i++){
			int v=edge[u][i];
			if(par[v]==-1 or match(par[v])){
				par[v]=u; par[u]=v;
				return true;
			}
		}
		return false;
}*/
int BPM()
{
    memset(used,0,sizeof(used));
    memset(par,-1,sizeof(par));
    int path=1,ret=0;
    int cnt=0;
    while(path){
        path=0;
        memset(used,0,sizeof(used));
        for(int i=0;i<n;i++){
            if(!used[i] && par[i]==-1){
                path+=match(i);
                //cout<<".. "<<i<<" "<<path<<endl;
            }
        }
//        for(int i=0;i<n+m;i++) printf("%d(%d)(%d) ",i,par[i],used[i]);
//        printf("\n");
        //cnt++;
        //if(cnt==10) break;
        //printf("----->%d\n",path);
    }
    for(int i=0;i<n;i++) if(par[i]!=-1) ret++;
    return ret;
}


/*

int BPM(void){
		memset(par,-1,sizeof(par));
		int path;
		do{
			memset(used,0,sizeof(used));
			path=0;
			for(int i=0;i<n;i++){
				if(par[i]==-1 and used[i]==0)
					path+=match(i);
			}
		//cout<<path<<endl;
		}
		while(path);
		for(int i=0;i<n+m;i++)
			if(par[i]!=-1)
				ans++;
		return ans;
}*/


int main()
{
	int i,j,k,l,t,kase=0;
	scanf("%d",&t);
	while(t--){
        init();
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&A[i]);
        scanf("%d",&m);
        for(i=0;i<m;i++) scanf("%d",&B[i]);
        for(i=0;i<n;i++){
            int u=A[i];
            for(j=0;j<m;j++){
                int v=B[j];
                if(!v || (u && v%u==0)) {
                    edge[i].push_back(n+j);
                    edge[n+j].push_back(i);
                }
            }
        }
//        for(i=n;i<n+m;i++){
//            printf("%d(%d) -- >",B[i-n],i);
//            for(j=0;j<edge[i].size();j++) printf(" %d(%d)",A[edge[i][j]],edge[i][j]);
//            printf("\n");
//        }
        //cout<<"---------------->";10
        printf("Case %d: %d\n",++kase,BPM());
//        for(int i=0;i<n;i++){
//            cout<<A[i]<<' '<<B[par[i]-n]<<endl;
//        }
//        for(int i=n;i<n+m;i++){
//            cout<<B[i-n]<<' '<<A[par[i]]<<endl;
//        }
	}
	return 0;
}

/*
100
4 2 7 9 5
6 10 12 24 6 16 14
*/
