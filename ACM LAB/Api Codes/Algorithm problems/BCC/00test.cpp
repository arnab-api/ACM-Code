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
#define oo 1<<30

#define M 255

vector<int>E[M],reg[M+M];
set<int>region[M];
set<int>:: iterator it;

int n,e,b,low[M],dfn[M],parent[M],depth,BCCcnt,reg_cnt,skip[M+M];
int energy[M],need[M],total[M],api[M],taken[M],vis[M];
struct edge{
    int u,v;
    edge(){}
    edge(int a,int b){
        u = a;
        v = b;
    }
};

stack<edge>st;

void init()
{
    for(int i=0;i<M;i++){
        E[i].clear();
        reg[i].clear();
        region[i].clear();
        parent[i]=-1;
        low[i]=-1;
        dfn[i]=-1;
        total[i]=0;
        api[i]=0;
        taken[i]=0;
        vis[i]=0;
        skip[i]=0;
    }
    while(!st.empty()) st.pop();
    depth=0;
    BCCcnt=0;
    reg_cnt=0;
}

void tarjanBCC(int u)
{
    low[u] = dfn[u] = depth++;
    int children = 0;
    for(int i=0;i<E[u].size();i++){
        int v = E[u][i];
        if(dfn[v]==-1){
            parent[v]=u;
            children++;
            st.push(edge(u,v));
            tarjanBCC(v);
            low[u] = min(low[u],low[v]);
            if((parent[u]==-1 && children>1) || (parent[u]!=-1 && low[v]>=dfn[u])){
                /// articulation point found!!!
                api[u]=1;
                while(st.top().u!=u || st.top().v!=v){
                    //printf("(%d--%d) ",st.top().u,st.top().v);
                    region[BCCcnt].insert(st.top().u);
                    region[BCCcnt].insert(st.top().v);
                    st.pop();
                }
                //printf("(%d--%d)\n",st.top().u,st.top().v);
                region[BCCcnt].insert(st.top().u);
                region[BCCcnt].insert(st.top().v);
                st.pop();
                BCCcnt++;
            }
        }
        else if(v!=parent[u] && dfn[v] < low[u]){
            low[u] = dfn[v];
            st.push(edge(u,v));
        }
    }
}

void find_BCC()
{
    int i;
    for(i=1;i<=n;i++){
        if(dfn[i]==-1) tarjanBCC(i);
        if(!st.empty()){
            while(!st.empty()){
                //printf("(%d--%d) ",st.top().u,st.top().v);
                region[BCCcnt].insert(st.top().u);
                region[BCCcnt].insert(st.top().v);
                st.pop();
            }
            //printf("\n");
            BCCcnt++;
        }
    }
}

int valid;
vector<int>edge[M+M];
int Left[M+M],Right[M+M],used[M+M],N;

int match(int u)
{
    if(used[u]) return 0;
    used[u]=1;
    for(int i=0;i<edge[u].size();i++){
        int v = edge[u][i];
        if(Left[v]==-1 || match(v)){
            Left[v] = u;
            Right[u] = v;
            return 1;
        }
    }
    return 0;
}

int BPM()
{
    int ans = 0 , path=1,i;
    while(path){
        path = 0;
        memset(used,0,sizeof(used));
        for(i=0;i<valid;i++) if(!used[i] && Right[i]==-1) path+=match(i);
    }
    for(i=0;i<valid;i++) if(Right[i]!=-1) ans++;
    return ans;
}

void update(int val)
{
    N = valid+b;
    for(int i=0;i<N;i++){
        edge[i].clear();
        Right[i]=-1;
        Left[i]=-1;
        used[i]=0;
    }
    int x,i,j;
    for(i=0;i<valid;i++){
        for(j=0;j<b;j++){
            x = total[i] - need[j];
            if(abs(x)<=val){
                edge[i].push_back(valid+j);
                edge[valid+j].push_back(i);
            }
        }
    }
}

int bin_search()
{
    int lo = 0 , hi = 101010 , mid , val , ans=-1;
    while(lo<=hi){
        mid = (lo+hi)/2;
        update(mid);
        val = BPM();
        //cout<<mid<<" ===> "<<val<<" <------> "<<valid<<endl;
        if(val < valid) lo = mid+1;
        else{
            ans = mid;
            hi = mid-1;
        }
    }
    return ans;
}

int main()
{
    int i,j,k,l,t,kase=0,u,v;
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d%d%d",&n,&e,&b);
        for(i=1;i<=n;i++) scanf("%d",&energy[i]);
        for(i=0;i<b;i++) scanf("%d",&need[i]);
        for(i=0;i<e;i++){
            scanf("%d%d",&u,&v);
            E[u].push_back(v);
            E[v].push_back(u);
        }
        find_BCC();

        for(i=0;i<BCCcnt;i++){
            for(it = region[i].begin() ; it!=region[i].end(); it++){
                k = *it;
                reg[reg_cnt].push_back(k);
            }
            reg_cnt++;
        }
        valid=0;
        for(i=0;i<BCCcnt;i++){
            l = reg[i].size();
            if(l>2){
                int sum=0;
                for(j=0;j<reg[i].size();j++){
                    sum+=energy[reg[i][j]];
                    taken[reg[i][j]]=1;
                }
                total[valid++] = sum;
            }
        }
        for(i=1;i<=n;i++) if(!taken[i]) total[valid++] = energy[i];
        printf("Buzz Mission %d: %d ",++kase,valid);
        if(valid>b) printf("No\n");
        else{
            /*printf("=====\n");
            for(i=0;i<valid;i++) printf("%d(%d) ",i,total[i]);
            printf("\n");
            for(i=0;i<b;i++) printf("%d(%d) ",i,need[i]);
            printf("\n");*/
            printf("%d\n",bin_search());
        }
    }
}
