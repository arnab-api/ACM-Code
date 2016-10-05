#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
#define N 10010
vector<int>v[N];
int cnt=0,taken[N];
void DFS(int d)
{
    if(taken[d]==1) return;
    cnt++;
    taken[d]=1;
    for(int i=0;i<v[d].size();i++){
        DFS(v[d][i]);
    }
}
int main()
{
    int n,m,l,t,i,x,y,z;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&l);
        for(i=0;i<=n;i++) {
            v[i].clear();
            taken[i]=0;
        }
        cnt=0;
        for(i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
        }
        for(i=0;i<l;i++){
            scanf("%d",&z);
            DFS(z);
        }
        printf("%d\n",cnt);
    }
	return 0;
}
