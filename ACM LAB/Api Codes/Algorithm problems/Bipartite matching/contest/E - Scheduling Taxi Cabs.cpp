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

struct data
{
    int st,sx,sy;
    int et,ex,ey;
};
data A[M];

vector<int>E[M];
int Right[M],Left[M],used[M];

void init()
{
    for(int i=0;i<M;i++){
        E[i].clear();
        Right[i]=-1;
        Left[i]=-1;
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
        for(int i=0;i<M;i++) if(!used[i] && Right[i]==-1) path+=match(i);
    }
    for(int i=0;i<M;i++) if(Right[i]!=-1) ret++;
    return ret;
}

bool check(data X,data Y)
{
    int time=X.et+abs(X.ex-Y.sx)+abs(X.ey-Y.sy);
    if(time < Y.st) return true;
    return false;
}

int main()
{
	int i,j,k,l,t,kase=0,ans,n,h,m;
	scanf("%d",&t);
	while(t--){
        init();
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&h);
            getchar();
            scanf("%d",&m);
            scanf("%d",&A[i].sx);
            scanf("%d",&A[i].sy);
            scanf("%d",&A[i].ex);
            scanf("%d",&A[i].ey);
            A[i].st=h*60+m;
            A[i].et=A[i].st+abs(A[i].sx-A[i].ex)+abs(A[i].sy-A[i].ey);
        }
        //for(i=0;i<n;i++) printf("%d -> %d %d & %d -> %d %d\n",A[i].st,A[i].sx,A[i].sy,A[i].et,A[i].ex,A[i].ey);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(check(A[i],A[j])) E[i].push_back(n+j);
            }
        }
        ans=n-BPM(n);
        //cerr<<"---------------------->";
        printf("Case %d: %d\n",++kase,ans);
	}
	return 0;
}

