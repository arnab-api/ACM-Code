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
#define N 1100

int n,dis;
struct Pair{
    double u,v;
    Pair(double a,double b){
        u=a; v=b;
    }
};

struct edge{
    int u,v;
    double w;
    edge(int a,int b,double c){
        u=a; v=b; w=c;
    }
};
vector<edge>E;

int prnt[N],city[N];

void make_set(int a)
{
    prnt[a]=a;
    city[a]=a;
}

int find_set(int a)
{
    if(prnt[a]==a) return a;
    else return prnt[a]=find_set(prnt[a]);
}

int find_city(int a)
{
    if(city[a]==a) return a;
    else return city[a]=find_city(city[a]);
}

bool con(edge a, edge b)
{
    return a.w<b.w;
}
double sum1,sum2;
void mst()
{
    int a,b;
    double c;
    sum1=0,sum2=0;
    sort(E.begin(),E.end(),con);
    for(int i=0;i<E.size();i++){
        a=E[i].u; b=E[i].v; c=E[i].w;
        //printf("%d %d %lf\n",a,b,c);
        if(find_set(a)!=find_set(b)){
            prnt[find_set(a)]=find_set(b);
            //printf("%d %d %lf\n",a,b,c);
            //printf("==>");
            //for(int i=1;i<=n;i++) printf("%d(%d) ",i,find_set(i));
            //printf("\n");
            if(find_city(a)==find_city(b))sum1+=c;
            else sum2+=c;
        }
    }
}

int main()
{
    int t,i,j,kase=0;
    double a,b,x,y,ans;
    scanf("%d",&t);
    while(t--){
        E.clear();
        vector<Pair>v;
        Pair p=Pair(0,0);
        v.push_back(p);
        scanf("%d%d",&n,&dis);
        for(i=0;i<n;i++){
            scanf("%lf%lf",&a,&b);
            p=Pair(a,b);
            v.push_back(p);
        }
        for(i=0;i<v.size();i++) make_set(i);
        for(i=1;i<v.size();i++){
            p=v[i];
            x=p.u; y=p.v;
            //printf("%lf %lf %d\n",x,y,i);
        }
        //Pair A;
        //Pair B;
        double x1,x2,y1,y2,W;
        for(i=1;i<=n;i++){
            Pair A=v[i];
            x1=A.u; y1=A.v;
            for(j=i;j<=n;j++){
                Pair B=v[j];
                x2=B.u; y2=B.v;
                W=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
                //printf("%lf %lf %lf %lf ==>%lf\n",x1,x2,y1,y2,W);
                E.push_back(edge(i,j,W));
                E.push_back(edge(j,i,W));
                if(find_city(i)!=find_city(j) && W<=dis){
                    city[find_city(i)]=find_city(j);
                }
            }
        }
        set<int>st;
        for(i=1;i<=n;i++) st.insert(find_city(i));
        //ans=mst();
        mst();
        kase++;
        printf("Case #%d: %d %.0lf %.0lf\n",kase,st.size(),sum1,sum2);
    }
	return 0;
}
