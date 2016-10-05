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
#define M 505
#define oo 1<<30

int Left[M], Right[M], used[M],Grid[M][M];

void init()
{
    memset(Grid,0,sizeof(Grid));
	for (int i = 0; i < M; i++) {
		Left[i] = -1;
		Right[i] = -1;
		used[i] = 0;
	}
}

int match(int u,int N)
{
	if (used[u]) return 0;
	used[u] = 1;
	for (int i = 1; i <= N; i++) {
        if(Grid[u][i]==0) continue;
		int v = i;
		if (Left[v] == -1 || match(Left[v],N)) {
			Right[u] = v;
			Left[v] = u;
			return 1;
		}
	}
	return 0;
}

int BPM(int N)
{
	int ret = 0, path = 1;
	while (path) {
		path = 0;
		memset(used, 0, sizeof(used));
		for (int i = 1; i <= N; i++) if (used[i] == 0 && Right[i] == -1) path += match(i,N);
	}
	//for (int i = 0; i <= N; i++) printf("%d %d %d\n", i, Left[i], Right[i]);
	for (int i = 1; i <= N; i++) if (Right[i] != -1)  ret++;
	return ret;
}

int main()
{
	int i,j,k,l,t;
	int n,m,a,b,ans;
	while(scanf("%d%d",&n,&m)==2){
        if(n==0 && m==0) break;
        init();
        while(m--){
            scanf("%d%d",&a,&b);
            Grid[a][b]=1;
        }
        for(k=1;k<=n;k++){
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    if(j==i) continue;
                    Grid[i][j]|=(Grid[i][k]&Grid[k][j]);
                }
            }
        }
        ans=n-BPM(n);
        //cerr<<"----------------->";
        printf("%d\n",ans);
	}
	return 0;
}

