#include<bits/stdc++.h>
using namespace std;
#define M 10100

int n,m,vis[M],taken[M];
vector<int>edge[M],topsort,x,y;
map<string,int>in;
map<int,string>out;

void init(int n)
{
    in.clear();
    out.clear();
    x.clear();
    y.clear();
    topsort.clear();
    for(int i=0;i<=n;i++) {
        edge[i].clear();
        vis[i]=0;
    }
}

void DFS(int p)
{
    if(vis[p]==1) return;
    vis[p]=1;
    for(int i=0;i<edge[p].size();i++) if(!vis[edge[p][i]]) DFS(edge[p][i]);
    topsort.push_back(p);
}

int kosaraju()
{
    int i,l,cnt=0,j;
    for(i=1;i<=n;i++) if(!vis[i]) DFS(i);
    l=topsort.size();
    for(i=1;i<=n;i++) {
        vis[i]=0;
        taken[i]=0;
        edge[i].clear();
    }
    for(i=0;i<x.size();i++) edge[y[i]].push_back(x[i]);
    for(i=0;i<l;i++) printf("%d ",topsort[i]);
    printf("\n");
    vector<string>prnt;
    for(i=l-1;i>=0;i--) if(!vis[topsort[i]]) {
        DFS(topsort[i]);
        prnt.clear();
        for(j=1;j<=n;j++) if(vis[j]==1 && taken[j]==0) {
            prnt.push_back(out[j]);
            taken[j]=1;
        }
        for(j=0;j<prnt.size()-1;j++) cout<<prnt[j]<<", ";
        cout<<prnt[prnt.size()-1]<<endl;
        cnt++;
    }
    return cnt;
}

int main()
{
    int t,i,j,a,b,ans,kase=0,c,d;
    string s1,s2,s;
    bool fst=true;
    while(scanf("%d%d",&n,&m)==2){
        if(n==0 && m==0) break;
        init(n);
        c=1;
        //getchar();
        for(i=0;i<m;i++){
            cin>>s1>>s2;
            if(in.find(s1)==in.end()) in[s1]=c++;
            if(in.find(s2)==in.end()) in[s2]=c++;
            a=in[s1]; b=in[s2];
            edge[a].push_back(b);
            x.push_back(a); y.push_back(b);
        }
        map<string,int> :: iterator it;
        for(it=in.begin();it!=in.end();it++){
            s=it->first;
            d=in[s];
            out[d]=s;
            //cout<<"->"<<s<<" "<<d<<endl;
        }
        /*map<int,string> :: iterator itt;
        for(itt=out.begin();itt!=out.end();itt++){
            d=itt->first;
            s=out[d];
            cout<<"--->"<<d<<" "<<s<<endl;
        }*/
        if(!fst) printf("\n");
        else fst=false;
        printf("Calling circles for data set %d:\n",++kase);
        ans=kosaraju();
        //printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}

