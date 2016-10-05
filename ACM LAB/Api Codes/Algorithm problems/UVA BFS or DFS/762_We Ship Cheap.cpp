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
#define oo 100000

vector<int>edge[1000];
int d[1000],vis[1000],parent[1000];
void init()
{
    for(int i=0;i<1000;i++) {
        edge[i].clear();
        d[i]=oo;
        parent[i]=-1;
        vis[i]=0;
    }
}
void BFS(int srce,int dst)
{
    d[srce]=0;
    vis[srce]=1;
    queue<int>q;
    q.push(srce);
    while(!q.empty()){
        int u=q.front();q.pop();
        int ucost=d[u];
        for(int i=0;i<edge[u].size();i++){
            int v=edge[u][i];
            if(!vis[v]){
                vis[v]=1;
                parent[v]=u;
                d[v]=ucost+1;
                q.push(v);
            }
        }
    }
}
int main()
{
    int n,i,j,k,l;
    string s1,s2;
    while(scanf("%d",&n)==1){
        init();
        set<string>s;
        vector<string>v,uniq;
        for(i=0;i<n;i++){
            cin>>s1>>s2;
            l=s.size();
            v.push_back(s1);
            v.push_back(s2);
            s.insert(s1);
            if(s.size()>l) uniq.push_back(s1);
            l=s.size();
            s.insert(s2);
            if(s.size()>l) uniq.push_back(s2);
        }
        //for(i=0;i<uniq.size();i++) cout<<uniq[i]<<endl;
       // for(i=0;i<v.size();i++) cout<<v[i]<<" "<<v[i++]<<endl;
        for(i=0;i<2*n;i++){
            for(j=0;j<s.size();j++) if(v[i]==uniq[j]) break;
            i++;
            for(k=0;k<s.size();k++) if(v[i]==uniq[k]) break;
            edge[j].push_back(k);
            edge[k].push_back(j);
        }
        /*for(i=0;i<uniq.size();i++){
            cout<<i<<"("<<uniq[i]<<")"<<"==>";
            for(j=0;j<edge[i].size();j++) cout<<" "<<edge[i][j]<<"("<<uniq[edge[i][j]]<<")";
            cout<<endl;
        }*/
        int srce,dst;
        cin>>s1>>s2;
        /*if(s1==s2){
            printf("\n");
            continue;
        }*/
        printf("\n");
        l=s.size();
        s.insert(s1);
        s.insert(s2);
        if(s.size()>l) {
            printf("No route\n");
            continue;
        }
        for(i=0;i<uniq.size();i++) if(uniq[i]==s1) break;
        srce=i;
        for(i=0;i<uniq.size();i++) if(uniq[i]==s2) break;
        dst=i;
        BFS(srce,dst);
        //cout<<srce<<uniq[srce]<<"  "<<dst<<uniq[dst]<<endl;
        //printf("%d\n",d[dst]);
        if(!vis[dst]){
            printf("No route\n");
            continue;
        }
        vector<int>out;
        int in=dst;
        for(i=0;i<d[dst];i++){
            out.push_back(in);
            out.push_back(parent[in]);
            in=parent[in];
        }
        for(i=out.size()-1;i>-1;i--){
            cout<<uniq[out[i]]<<" ";
            i--;
            cout<<uniq[out[i]]<<endl;
        }
    }
	return 0;
}
