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
#include<limits.h>
using namespace std;
#define ll long long int
#define N 1000100

int n,m;

struct edge{
    int u,v,w;
    edge(int a,int b,int c){
        u=a,v=b,w=c;
    }
};
vector<edge>E;

bool con(edge a,edge b) {
    return a.w>b.w;
}
int p[N];
void make_set(int a)
{
    p[a]=a;
}

int find_set(int a)
{
    if(p[a]==a) return a;
    return p[a]=find_set(p[a]);
}

int source,dstn;
int vis[N];

int mst()
{
    int a,b,c,mini=INT_MAX;
    sort(E.begin(),E.end(),con);
    for(int i=0;i<m+2;i++){
        a=E[i].u; b=E[i].v; c=E[i].w;
        if(find_set(source)==find_set(dstn)) return mini;
        if(find_set(a)!=find_set(b)){
            p[find_set(a)]=find_set(b);
            //printf("%d %d %d\n",a,b,c);
            //printf("==>");
            //for(int i=1;i<=m;i++) printf("%d(%d) ",find_set(i),i);
            //printf("\n");
            if(c<mini) mini=c;
        }
    }
    return mini;
}
int main()
{
    int a,b,c,ans,i,kase=0;
    string s1,s2,src,dst;
    while(scanf("%d%d",&n,&m)==2){
        if(n==0 && m==0) break;
        E.clear();
        for(i=0;i<N;i++) {
            make_set(i);
            vis[i]=0;
        }
        map<string,int>mp;
        int in=1;
        for(i=0;i<m;i++){
            cin>>s1>>s2>>c;
            if(mp.find(s1)==mp.end()) mp[s1]=in++;
            if(mp.find(s2)==mp.end()) mp[s2]=in++;
            a=mp[s1]; b=mp[s2];
            E.push_back(edge(a,b,c));
            E.push_back(edge(b,a,c));
        }
        //map<string,int> :: iterator it=mp.begin();
        //for(it=mp.begin();it!=mp.end();it++) {
        //    string str=it->first;
        //    cout<<str<<" "<<mp[str]<<endl;
        //}
        cin>>src>>dst;
        source=mp[src];
        dstn=mp[dst];
        ans=mst();
        kase++;
        printf("Scenario #%d\n%d tons\n\n",kase,ans);
    }
	return 0;
}
