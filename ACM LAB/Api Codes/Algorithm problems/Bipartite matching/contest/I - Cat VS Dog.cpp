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
int Left[M],Right[M],used[M];

void init(int N)
{
    for(int i=0;i<N;i++){
        E[i].clear();
        Left[i]=-1;
        Right[i]=-1;
    }
}

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
        for(int i=0;i<N;i++) if(Right[i]==-1 && used[i]==0) path+=match(i);
    }
    for(int i=0;i<N;i++) if(Right[i]!=-1) ret++;
    return ret/2;
}

struct pref
{
    string lk,dlk;
};
pref Child[M];

int main()
{
	int i,j,k,l,t;
	int n,m,p,ans;
	while(scanf("%d%d%d",&n,&m,&p)==3){
        init(p);
        for(i=0;i<p;i++){
            cin>>Child[i].lk;
            cin>>Child[i].dlk;
        }
        //for(i=0;i<p;i++) cout<<i<<" --->"<<Child[i].lk<<" "<<Child[i].dlk<<endl;
        for(i=0;i<p;i++){
            for(j=i+1;j<p;j++){
                if(Child[i].lk==Child[j].dlk || Child[j].lk==Child[i].dlk){
                    E[i].push_back(j);
                    E[j].push_back(i);
                }
            }
        }
        ans=p-BPM(p);
        //cerr<<"------------------------>";
        printf("%d\n",ans);
	}
	return 0;
}

