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
#define M 1010
#define oo 1<<30

vector<int>E[M];
int Left[M], Right[M], used[M],flag[M];

void init()
{
	for (int i = 0; i < M; i++) {
		E[i].clear();
		Left[i] = -1;
		Right[i] = -1;
		used[i] = 0;
		flag[i]=0;
	}
}

int match(int u)
{
	if (used[u] || flag[u]) return 0;
	used[u] = 1;
	for (int i = 0; i < E[u].size(); i++) {
		int v = E[u][i];
		if(flag[v]) continue;
		if (Left[v] == -1 || match(Left[v])) {
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
	for(int i=0;i<=N;i++){
        Right[i]=-1;
        Left[i]=-1;
	}
	while (path) {
		path = 0;
		memset(used, 0, sizeof(used));
		for (int i = 1; i <= N; i++) if (flag[i]==0 && used[i] == 0 && Right[i] == -1) path += match(i);
	}
	//for (int i = 0; i <= N; i++) printf("%d %d %d\n", i, Left[i], Right[i]);
	for (int i = 0; i <= N; i++) if (Right[i] != -1)  ret++;
	return ret /2;
}

int find_essen_node(int N)
{
    int curBPM=BPM(N),val,ret=0;
    for(int i=1;i<=N;i++){
        //printf("------> %d\n",curBPM);
        flag[i]=1;
        val=BPM(N);
        if(val<curBPM){
            ret++;
            //printf("---> %d\n",i);
            curBPM=val;
        }
        else flag[i]=0;
    }
    return ret;
}

int main()
{
	int i, j, l, t, ans;
	int n, k, a, b;
	while (scanf("%d%d", &n, &k) == 2) {
		init();
		for (i = 0; i < k; i++) {
			scanf("%d%d", &a, &b);
			b += n;
			E[a].push_back(b);
			E[b].push_back(a);
		}
		/*for (i = 1; i <= n + n; i++) {
			printf("%d --->", i);
			for (j = 0; j < E[i].size(); j++) printf(" %d", E[i][j]);
			printf("\n");
		}*/
		//ans = BPM(n + n);
		ans=find_essen_node(n+n);
		//cerr << "---------------->";
		printf("%d\n", ans);
	}
	return 0;
}
