#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define N 110

int n,m;
struct edge{
    int u,v,w;
    edge(int a,int b,int c){
        u=a; v=b; w=c;
    };
};
vector<edge>E,save;

int p[N];

void make_set(int a)
{
    p[a]=a;
}

int find_set(int a)
{
    if(p[a]==a) return a;
    else return p[a]=find_set(p[a]);
}

bool con(edge a, edge b)
{
    return a.w<b.w;
}
vector<int>path,altpath;
int mst()
{
    int i,a,b,c,sum=0;
    for(i=1;i<=n;i++) make_set(i);
    sort(E.begin(),E.end(),con);
    bool flag;
    if(path.size()==0) flag=true;
    else flag=false;
    for(i=0;i<E.size();i++){
        a=E[i].u; b=E[i].v; c=E[i].w;
        if(find_set(a)!=find_set(b)){
            if(flag==true) path.push_back(i);
            altpath.push_back(i);
            p[find_set(a)]=find_set(b);
            sum+=c;
        }
    }
    set<int>st;
    for(i=1;i<=n;i++) st.insert(find_set(i));
    if(st.size()==1) return sum;
    else return -1;
}

int main()
{
    int t,i,j,kase=0,a,b,c,ans,alter,mini,ans2;
    scanf("%d",&t);
    freopen("A.txt","w",stdout);
    while(t--){
        scanf("%d%d",&n,&m);
        E.clear();
        path.clear();
        save.clear();
        for(i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            E.push_back(edge(a,b,c));
            E.push_back(edge(b,a,c));
            save.push_back(edge(a,b,c));
            save.push_back(edge(b,a,c));
        }
        ans=mst();

        //printf("==>%d\n",ans);
        kase++;
        printf("Case #%d : ",kase);
        if(ans==-1) {
            printf("No way\n");
            continue;
        }
        vector<edge> :: iterator it=E.begin();
        alter=0;
        mini=INT_MAX;
        for(i=0;i<path.size();i++) printf("==>%d ",path[i]);
        printf("\n");
        for(i=0;i<E.size();i++){
            edge in=E[i];
            E.erase(it+i);
            E.erase(it+i);
            i++;
            altpath.clear();
            ans2=mst();
            E.clear();
            for(j=0;j<save.size();j++) E.push_back(save[j]);
            if(ans2==-1) continue;
            if(ans2<mini) {
                bool flag=true;
                for(int j=0;j<altpath.size();j++) {
                    for(int i=0;i<altpath.size();i++) printf("==>%d ",altpath[i]);
                    printf("\n");
                    if(altpath[j]!=path[j]){
                        flag=false;
                        break;
                    }
                }
                if(!flag){
                    mini=ans2;
                    alter++;
                }
            }
        }
        //for(i=0;i<path.size();i++) printf("==>%d ",path[i]);
        //printf("\n");
        if(alter==0) printf("No second way\n");
        else printf("%d\n",mini);
    }
    return 0;
}
