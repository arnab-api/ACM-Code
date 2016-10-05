#include<bits/stdc++.h>
using namespace std;
#define MX 333

int Left[MX],Right[MX],used[MX],n;
vector<int>G[MX];

void init()
{
    for(int i=0;i<MX;i++){
        G[i].clear();
        Right[i]=-1;
        Left[i]=-1;
        used[i]=0;
    }
}

int match(int u)
{
    if(used[u]) return 0;
    used[u]=1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
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
        for(int i=0;i<N;i++) if(Right[i]==-1 && used[i]==0) path+=match(i);
    }
    for(int i=0;i<N;i++) if(Right[i]!=-1) ret++;
    return ret;
}

int get_st(string pref)
{
    int st;
    if(pref=="XS") st=n*0+1;
    else if(pref=="S") st=n*1+1;
    else if(pref=="M") st=n*2+1;
    else if(pref=="L") st=n*3+1;
    else if(pref=="XL") st=n*4+1;
    else if(pref=="XXL") st=n*5+1;
    return st;
}

int main()
{
    int m,i,j,t,kase=0,st,ans;
    string pref;
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++){
            cin>>pref;
            st=get_st(pref);
            for(j=st;j<st+n;j++) G[i].push_back(j);

            cin>>pref;
            st=get_st(pref);
            for(j=st;j<st+n;j++) G[i].push_back(j);
        }
        ans=BPM(m);
        //cerr<<"------------------->";
        printf("Case %d: ",++kase);
        if(ans==m) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
