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
#define M 30010
#define lli long long int

vector<lli>E[M],C[M];
lli D[M];
lli oo=100000;

void init(lli N)
{
    for(lli i=0;i<N;i++){
        E[i].clear();
        C[i].clear();
        D[i]=oo;
    }
}

struct ret{
    lli node,cost;
    ret();
    ret(lli n,lli c){
        node=n; cost=c;
    }
};

ret BFS(lli srce)
{
    //cout<<"------------------>"<<srce<<endl;
    queue<lli>q;
    memset(D,63,sizeof(D));
    //for(lli i=0;i<M;i++) printf("%lld %lld\n",i,D[i]);
    D[srce]=0;
    q.push(srce);
    ret R=ret(srce,0);
    while(!q.empty()){
        lli u=q.front(); q.pop();
        //cerr<<"------>"<<u<<endl;
        lli ucost=D[u];
        for(lli i=0;i<E[u].size();i++){
            lli v=E[u][i];
            lli vcost=ucost+C[u][i];
            //cerr<<"====>"<<v<<"  "<<vcost<<" "<<D[v]<<endl;
            if(vcost<D[v]){
                D[v]=vcost;
                if(vcost>R.cost){
                    R=ret(v,vcost);
                }
                q.push(v);
            }
        }
    }
    return R;
}

int main()
{
	lli i,j,k,l,t,n,u,v,w,kase=0;
	scanf("%lli",&t);
	while(t--){
	    scanf("%lld",&n);
        init(n);
        for(i=1;i<n;i++){
            scanf("%lld%lld%lld",&u,&v,&w);
            E[u].push_back(v);
            E[v].push_back(u);
            C[u].push_back(w);
            C[v].push_back(w);
        }
        ret R=BFS(0);
        printf("Case %lld: %lld\n",++kase,BFS(R.node).cost);
	}
	return 0;
}

