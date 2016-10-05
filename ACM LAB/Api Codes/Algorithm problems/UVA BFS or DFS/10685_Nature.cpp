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
vector<int>edge[5000];
int vis[5000],cnt;

void DFS(int p)
{
    cnt++;
    vis[p]=1;
    for(int k=0;k<edge[p].size();k++){
        if(!vis[edge[p][k]]) DFS(edge[p][k]);
    }
}

int main()
{
    int c,r,i,j,a,b;
    string s,s1,s2;
    while(scanf("%d%d",&c,&r)==2){
        if(c==0 && r==0) break;
        vector<string>creature;
        for(i=0;i<=c;i++){
            edge[i].clear();
            vis[i]=0;
        }
        while(c--){
            cin>>s;
            creature.push_back(s);
        }
        while(r--){
            cin>>s1>>s2;
            for(a=0;a<creature.size();a++) if(s1==creature[a]) break;
            for(b=0;b<creature.size();b++) if(s2==creature[b]) break;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        int max=0;
        for(i=0;i<creature.size();i++){
            if(!vis[i]) {
                cnt=0;
                DFS(i);
                if(cnt>max) max=cnt;
            }
        }
        printf("%d\n",max);
    }
	return 0;
}
