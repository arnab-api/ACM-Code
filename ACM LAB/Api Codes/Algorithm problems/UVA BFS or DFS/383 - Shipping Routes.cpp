#include<bits/stdc++.h>
using namespace std;
#define M 35
#define oo INT_MAX
int dis[M],taken[M],m_in=0,m,n,p;
vector<int>v[M];
map<string,int>mp;
string s;

void init()
{
    mp.clear();
    m_in=0;
    for(int i=0;i<M;i++){
        v[i].clear();
    }
}

int BFS(int srce,int dest)
{
    taken[srce]=1; dis[srce]=0;
    queue<int>q;
    q.push(srce);
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int i=0;i<v[u].size();i++){
            int n=v[u][i];
            if(!taken[n]){
                taken[n]=1;
                dis[n]=dis[u]+1;
                q.push(n);
            }
        }
        if(taken[dest]==1) return dis[dest];
    }
    return -1;
}

int main()
{
    //freopen("383-shipping.txt","w",stdout);
    int t,i,j,a,b,mul,ans,kase=0;
    string s1,s2,srce,dest;
    scanf("%d",&t);
    printf("SHIPPING ROUTES OUTPUT\n\n");
    while(t--){
        init();
        scanf("%d%d%d",&m,&n,&p);
        for(i=0;i<m;i++){
            cin>>s;
            if(mp.find(s)==mp.end()) mp[s]=m_in++;
        }
        /*map<string,int> :: iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            s=it->first;
            cout<<s<<" "<<mp[s]<<endl;
        }*/
        for(i=0;i<n;i++){
            cin>>s1>>s2;
            a=mp[s1]; b=mp[s2];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        printf("DATA SET  %d\n\n",++kase);
        while(p--){
            cin>>mul>>srce>>dest;
            for(i=0;i<M;i++){
                taken[i]=0;
                dis[i]=oo;
            }
            ans=BFS(mp[srce],mp[dest]);
            if(ans==-1) printf("NO SHIPMENT POSSIBLE\n");
            else printf("$%d\n",mul*ans*100);
        }
        printf("\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
