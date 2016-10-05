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
    return a.w<b.w;
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

int mst()
{
    int a,b,c,sum=0;
    sort(E.begin(),E.end(),con);
    for(int i=0;i<m+2;i++){
        a=E[i].u; b=E[i].v; c=E[i].w;
        if(find_set(a)!=find_set(b)){
            p[find_set(a)]=find_set(b);
            //printf("%d %d %d\n",a,b,c);
            //printf("==>");
            //for(int i=1;i<=m;i++) printf("%d(%d) ",find_set(i),i);
            //printf("\n");
            sum+=c;
        }
    }
    return sum;
}

int main()
{
    int i,j,a,b,c,ans;
    while(scanf("%d%d",&n,&m)==2){
        E.clear();
        for(i=1;i<=n;i++) make_set(i);
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            E.push_back(edge(a,b,c));
            E.push_back(edge(b,a,c));
        }
        ans=mst();
        printf("%d\n",ans);
    }
	return 0;
}
