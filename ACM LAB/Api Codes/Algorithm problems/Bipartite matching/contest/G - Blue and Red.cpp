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
#define M 222
#define oo 1<<30

vector<int>E[M];
set<int>st;
set<int> :: iterator it;
int Right[M],Left[M],G[M];
void init()
{
    st.clear();
    for(int i=0;i<M;i++){
        E[i].clear();
        Right[i]=-1;
        Left[i]=-1;
        G[i]=-1;
    }
}

int used[M];

int match(int u)
{
    if(used[u]) return 0;
    used[u]=1;
    for(int i=0;i<E[u].size();i++){
        int v=E[u][i];
        if(Left[v]==-1 || match(Left[v])){
            Right[u]=v;
            Left[v]=u;
            return 1;
        }
    }
    return 0;
}

int BPM(int N)
{
    int path=1,ret=0;
    while(path){
        path=0;
        memset(used,0,sizeof(used));
        for(int i=0;i<N;i++) if(!used[i] && Right[i]==-1) path+=match(i);
    }
    for(int i=0;i<N;i++) if(Right[i]!=-1){
        st.insert(min(i,Right[i]));
        ret++;
    }
    for(int i=0;i<N;i++) printf("%d --> %d %d\n",i,Left[i],Right[i]);
    return ret;
}

int main()
{
	int i,j,k,l,t,a,b,n,m;
	scanf("%d",&t);
	while(t--){
        init();
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%d",&a);
            G[i]=a;
        }
        while(m--){
            scanf("%d%d",&a,&b);
            if(G[a]==G[b]) continue;
            E[a].push_back(b);
        }
        a=BPM(n);
        //cerr<<"--------------->";
        printf("%d",st.size());
        for(it=st.begin();it!=st.end();it++) printf(" %d",*it);
        printf("\n");
	}
	return 0;
}

