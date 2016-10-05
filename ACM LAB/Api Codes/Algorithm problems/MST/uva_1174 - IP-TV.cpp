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
#define M 2010
#define oo 1<<30

int n,m;

struct edge{
    int u,v,w;
    edge(int a,int b,int c){
        u=a; v=b; w=c;
    }
    bool operator < (const edge & p)const{
        return w < p.w;
    }
};

vector<edge>E;
map<string,int>mp;
int P[M],in;

void make_set(int a)
{
    P[a]=a;
}

int find_set(int a)
{
    if(P[a]==a) return a;
    return P[a]=find_set(P[a]);
}

void init()
{
    E.clear();
    mp.clear();
    in=0;
    for(int i=0;i<=n;i++) make_set(i);
}

int MST()
{
    int a,b,c,sum=0;
    for(int i=0;i<E.size();i++){
        a=E[i].u; b=E[i].v; c=E[i].w;
        if(find_set(a)!=find_set(b)){
            P[find_set(a)]=find_set(b);
            sum+=c;
        }
    }
    //set<int>st;
    //printf("%d\n",sum);
    //for(int i=0;i<n;i++) st.insert(find_set(i));
    //for(int i=0;i<n;i++) printf("%d(%d) ",i,P[i]);
    //printf("\n");
    //if(st.size()>1) return -1;
    return sum;
}

int main()
{
	int i,j,k,l,t,a,b,c,ans,fst=1;
	string A,B;
	scanf("%d",&t);
	while(t--){
        scanf("%d%d",&n,&m);
        init();
        for(i=0;i<m;i++){
            cin>>A>>B>>c;
            if(mp.find(A)==mp.end()) mp[A]=in++;
            if(mp.find(B)==mp.end()) mp[B]=in++;
            a=mp[A]; b=mp[B];
            E.push_back(edge(a,b,c));
        }
        /*map<string,int> :: iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            A=it->first;
            cout<<A<<" --> "<<mp[A]<<endl;
        }*/
        sort(E.begin(), E.end());
        //for(i=0;i<E.size();i++) printf("%d %d ----> %d\n",E[i].u,E[i].v,E[i].w);
        ans=MST();
        if(!fst) printf("\n");
        else fst=0;
        //cout<<"------------------->";
        printf("%d\n",ans);
	}
	return 0;
}

