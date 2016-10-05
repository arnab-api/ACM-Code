#include <bits/stdc++.h>
using namespace std;
#define M 10000

vector <int> v[M];
int vis[M],dis[M];
int parent[M];
int src,des;
map <string,int> mstring;
map <int,string> mint;

void starts()
{
    int i;

    for(i=0;i<M;i++){
        v[i].clear();
        vis[i]=0;
        parent[i]=-1;
    }
}

int bfs()
{
    queue <int> q;
    q.push(src);
    vis[src]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<v[u].size();i++){
            int x=v[u][i];
            if(!vis[x]){
                q.push(x);
                vis[x]=1;
                parent[x]=u;
                //dis[x]=dis[u]+1;
            }
        }
        if(vis[des]==1) return 1;
    }
    return 0;
}
int cs=0;
int main()
{
    int e,fst=1;

    while(scanf("%d",&e)==1){
        starts();
        mstring.clear();
        mint.clear();
        int index=1,n1,n2;
        string a,c;

        for(int i=0;i<e;i++){
            cin>>a>>c;
            if(mstring[a]==0){
                mstring[a]=index;
                mint[index]=a;
                index++;
            }
            if(mstring[c]==0){
                mstring[c]=index;
                mint[index]=c;
                index++;
            }
            n1=mstring[a];
            n2=mstring[c];
            v[n1].push_back(n2);
            v[n2].push_back(n1);
            //printf("==>> %d %d\n",n1,n2);
        }
        for(int i=0;i<mstring.size();i++){
            cout<<i<<"("<<mint[i]<<")"<<"==>";
            for(int j=0;j<v[i].size();j++) cout<<v[i][j]<<"("<<mint[v[i][j]]<<")";
            printf("\n");
        }
        cin>>a>>c;
        src=mstring[a];
        des=mstring[c];
        int ans=bfs();

        if(fst) fst=0;
        else printf("\n");
        cout<<"===>"<<endl;
        if(!ans) printf("No route\n");
        else{
            int i=des;
            int arr1[M],arr2[M];
            int j=0;
            while(i!=src){
                arr1[j]=parent[i];
                arr2[j]=i;
                i=parent[i];
                j++;
            }
            for(int x=j-1;x>=0;x--) cout<<mint[arr1[x]]<<" "<<mint[arr2[x]]<<endl;
        }

    }

    return 0;
}



