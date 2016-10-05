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

vector<int>G[M];
int depth,belong[M],scc,low[M],dfn[M];
stack<int>st;

void init()
{
    for(int i=0;i<M;i++){
        G[i].clear();
        belong[i]=-1;
        low[i]=-1;
        dfn[i]=-1;
    }
    depth=0;
    scc=0;
    while(!st.empty()) st.pop();
}

void addEdge(int a,int b)
{
    G[a^1].push_back(b);
    G[b^1].push_back(a);
}

void tarjan(int u)
{
    low[u] = dfn[u] = depth++;
    st.push(u);
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if(dfn[v]==-1){
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(belong[v]==-1) low[u] = min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        int v;
        do{
            v = st.top();
            belong[v] = scc;
            st.pop();
        }while(v!=u);
        scc++;
    }
}


int main()
{
	int i,j,k,l,t,S,A,m;
	int s1,a1,s2,a2;
	scanf("%d",&t);
	while(t--){
        init();
        scanf("%d%d%d",&S,&A,&m);
        while(m--){
            scanf("%d%d%d%d",&s1,&a1,&s2,&a2);
            s1-- ; a1--;
            s2-- ; a2--;
            /// making space for complements :p;
            s1 <<= 1; a1 <<= 1;
            s2 <<= 1; a2 <<= 1;
            if(s1 > s2) a1^=1, a2^=1;
            if(a1 > a2) s1^=1, s2^=1;
            a1+=(2*S);
            a2+=(2*S);
            if(s1 == s2) {
                G[s1^1].push_back(s1);
                continue;
            }
            if(a1 == a2) {
                G[a1^1].push_back(a1);
                continue;
            }
            /// solve (s1 and a2) or (s2 and a1)
            addEdge(s1,a1);
            addEdge(s2,a2);
            addEdge(a1,a2);
            addEdge(s1,s2);
        }
        for(i=0;i<(S+S+A+A);i++) if(dfn[i]==-1) tarjan(i);
        bool flag = true;
        for(i=0;i<(S+S+A+A);i++) if(belong[i] == belong[i^1]){
            flag = false ; break;
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
	}
	return 0;
}

