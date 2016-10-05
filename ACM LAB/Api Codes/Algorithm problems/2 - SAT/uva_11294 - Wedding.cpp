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
#define M 100100
#define oo 1<<30

vector<int>G[M];
int depth,belong[M],scc,low[M],dfn[M],taken[M],n;
stack<int>st;
vector<int>seq;
map<int,int>mp;
int status[M];

int neg(int idx)
{
    if(idx>=n) return idx - n;
    return idx+n;
}

void init(int N)
{
    for(int i=0;i<N;i++){
        G[i].clear();
        belong[i]=-1;
        low[i]=-1;
        dfn[i]=-1;
        status[i]=0;
        taken[i]=0;
    }
    depth=0;
    scc=0;
    while(!st.empty()) st.pop();
    seq.clear();
    mp.clear();
}

void addEdge(int a,int b)
{
    G[neg(a)].push_back(b);
    G[neg(b)].push_back(a);
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

void topSort(int u)
{
    if(taken[u]) return;
    taken[u]=1;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        topSort(v);
    }
    seq.push_back(u);
}

int main()
{
	int i,j,k,l,t;
	int m;
	int a,b;
	char cha,chb;
	while(scanf("%d%d",&n,&m)==2){
        if(n==0 && m==0) break;
        init(n+n+5);
        while(m--){
            scanf("%d",&a);
            scanf(" %c",&cha);
            scanf("%d",&b);
            scanf(" %c",&chb);

            //printf("%d(%c) %d(%c) ==> ",a,cha,b,chb);
            //a-- ; b--;
            if(cha=='w') a = neg(a);
            if(chb=='w') b = neg(b);
            //printf("%d %d\n",a,b);
            addEdge(a,b);
        }
        //n--;
        G[neg(0)].push_back(0);
        /*for(i=0;i<n;i++){
            //addEdge(i,i);
            G[neg(i)].push_back(i);
        }*/
        for(i=0;i<2*n;i++) if(dfn[i]==-1) tarjan(i);
        bool flag = true;

        /*for(i=0;i<2*n;i++){
            printf("%d ---> ",i);
            for(j=0;j<G[i].size();j++) printf(" %d",G[i][j]);
            printf("\n");
        }*/

        for(i=0;i<2*n;i++) if(belong[i] == belong[neg(i)]){
            //printf("%d(%d) -- %d(%d)\n",i,belong[i],neg(i),belong[neg(i)]);
            flag = false;
            break;
        }
        if(!flag) printf("bad luck\n");
        else{
            for(i=0;i<2*n;i++) if(!taken[i]) topSort(i);
            reverse(seq.begin(),seq.end());
            for(i=0;i<seq.size();i++){
                //printf("%d ",seq[i]);
                mp[seq[i]] = i;
            }
            //printf("\n");
            ///If ¬xi is after xi in topological sort, xi should be FALSE
            for(i=0;i<n;i++){
                if(mp[i] < mp[neg(i)]){
                    status[belong[i]] = 0;
                    status[belong[neg(i)]] = 1;
                }
                else {
                    status[belong[i]] = 1;
                    status[belong[neg(i)]]=0;
                }
                //printf("%d(%d) ",i,status[i]);
            }
            //printf("\n");
            for(i=1;i<n;i++){
                if(i>1) printf(" ");
                printf("%d",i);
                if(status[belong[i]]) printf("h");
                else printf("w");
            }
            printf("\n");
            /*for(i=1;i<n;i++){
                if(i>1) printf(" ");
                printf("%d",i);
                if(status[belong[i]]) printf("w");
                else printf("h");
            }
            printf("\n");*/
        }
	}
	return 0;
}

