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
vector<int>edge[100000];
int vis[100000],cnt;
void DFS(int p)
{
    vis[p]=1;
    for(int k=0;k<edge[p].size();k++) {
        if(!vis[edge[p][k]]){
            cnt++;
            DFS(edge[p][k]);
        }
    }
}
int main()
{
    int t,f,l,i,j,a,b;
    string s1,s2;
    scanf("%d",&t);
    while(t--){
        set<string>st;
        vector<string>v;
        scanf("%d\n",&f);
        for(i=0;i<=2*f;i++) edge[i].clear();
        while(f--){
            l=st.size();
            cin>>s1;
            st.insert(s1);
            if(st.size()>l){
                v.push_back(s1);
                l=st.size();
            }
            cin>>s2;
            st.insert(s2);
            if(st.size()>l){
                v.push_back(s2);
                l=st.size();
            }
            for(a=0;a<v.size();a++) if(v[a]==s1) break;
            for(b=0;b<v.size();b++) if(v[b]==s2) break;
            edge[a].push_back(b);
            edge[b].push_back(a);
            for(i=0;i<v.size();i++) vis[i]=0;
            cnt=1;
            DFS(a);
            printf("%d\n",cnt);
        }
        //for(i=0;i<v.size();i++) cout<<v[i]<<endl;
    }
	return 0;
}
