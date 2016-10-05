#include<bits/stdc++.h>
using namespace std;
#define M 210

int p[M],n,w,in;
struct edge{
    int u,v,w;
    edge(int a,int b,int c){
        u=a; v=b; w=c;
    }
};

vector<edge>E;

bool con(edge a, edge b)
{
    return a.w<b.w;
}

void make_set(int a)
{
    p[a]=a;
}

int find_set(int a)
{
    if(p[a]==a) return a;
    else return p[a]=find_set(p[a]);
}

int MST()
{
    sort(E.begin(),E.end(),con);
    //for(int i=0;i<E.size();i++) cout<<E[i].u<<" "<<E[i].v<<" "<<E[i].w<<endl;
    int a,b,c,sum=0,taken=0;
    vector<edge> :: iterator it=E.begin();
    for(int i=0;i<E.size();i++){
        a=E[i].u; b=E[i].v; c=E[i].w;
        if(find_set(a)!=find_set(b)){
            p[find_set(a)]=find_set(b);
            sum+=c;
            taken++;
        }
        if(taken==in-2) break;
    }
    if(taken==in-2)return sum;
    else return -1;
}

void init()
{
    for(int i=0;i<=M;i++) make_set(i);
}

int main()
{
    int t,i,j,kase=0,a,b,c,ans;
    scanf("%d",&t);

    while(t--){
        E.clear();
        map<string,int>mp;
        string s;
        scanf("%d",&w);

        in=1;
        for(i=1;i<=w;i++){
            cin>>s;
            if(mp.find(s)==mp.end()) mp[s]=in++;
            a=mp[s];
            cin>>s;
            if(mp.find(s)==mp.end()) mp[s]=in++;
            b=mp[s];
            cin>>c;
            E.push_back(edge(a,b,c));
            //E.push_back(edge(b,a,c));
        }
        map<string,int> :: iterator it;
        /*for(it=mp.begin();it!=mp.end();it++){
            string n=it->first;
            cout<<n<<" "<<mp[n]<<endl;
        }*/
        printf("Case %d: ",++kase);
        init();
        //for(int i=1;i<in;i++) printf("%d(%d) ",i,p[i]);
        //printf("\n");
        ans=MST();
        //for(int i=1;i<in;i++) printf("%d(%d) ",i,find_set(i));
        //printf("\n");
        if(ans==-1) printf("Impossible\n");
        else printf("%d\n",ans);
    }
    return 0;
}

