#include<bits/stdc++.h>
using namespace std;
#define M 20100

vector<int>G[M];
int low[M],dfn[M],scc,belong[M],m_in,depth;
stack<int>s;
map<string,int>mp;

void init()
{
    for(int i=0;i<M;i++){
        G[i].clear();
        dfn[i]=-1;
        belong[i]=-1;
    }
    scc=depth=0;
    mp.clear();
    m_in=0;
    while(!s.empty()) s.pop();
}

void tarjan(int u)
{
    low[u]=dfn[u]=depth++;
    s.push(u);
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(dfn[v]==-1){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(belong[v]==-1) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        int v;
        do{
            v=s.top();
            belong[v]=scc;
            s.pop();
        }while(v!=u);
        scc++;
    }
}


int main()
{
    int t,kase=0,i,j,a,b,m;
    scanf("%d",&t);
    string s1,s2;
    while(t--){
        init();
        scanf("%d",&m);
        while(m--){
            cin>>s1;
            if(mp.find(s1)==mp.end()) mp[s1]=m_in++;
            cin>>s2;
            if(mp.find(s2)==mp.end()) mp[s2]=m_in++;
            a=mp[s1];
            b=mp[s2];
            G[a].push_back(b);
        }
        /*for(i=0;i<m_in;i++){
            printf("%d --> ",i);
            for(j=0;j<G[i].size();j++) printf("%d ",G[i][j]);
            printf("\n");
        }*/
        for(i=0;i<m_in;i++) if(dfn[i]==-1) tarjan(i);
        //cout<<"----->"<<scc;
        printf("Case %d: ",++kase);
        if(scc<m_in) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
