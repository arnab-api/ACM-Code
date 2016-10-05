#include<bits/stdc++.h>
using namespace std;
#define M 55

int used[M],Right[M],Left[M],m,n;
vector<int>edge[M];

void init()
{
    for(int i=0;i<M;i++){
        used[i]=0;
        Right[i]=-1;
        Left[i]=-1;
        edge[i].clear();
    }
}

struct info{
    int height,age,status;
};

int match(int u)
{
    if(used[u]==1) return 0;
    used[u]=1;
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if(Left[v]==-1 || match(Left[v])){
            Right[u]=v;
            Left[v]=u;
            return 1;
        }
    }
    return 0;
}

int BPM()
{
    int path=1,ret=0;
    while(path){
        path=0;
        memset(used,0,sizeof(used));
        for(int i=0;i<m;i++){
            if(!used[i] && Right[i]==-1){
                path+=match(i);
            }
        }
    }
    for(int i=0;i<m;i++) if(Right[i]!=-1) ret++;
    return ret;
}

int main()
{
    int i,j,t,kase=0;
    info men[M],women[M];
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d%d",&m,&n);
        for(i=0;i<m;i++)scanf("%d%d%d",&men[i].height,&men[i].age,&men[i].status);
        for(i=0;i<n;i++)scanf("%d%d%d",&women[i].height,&women[i].age,&women[i].status);
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(abs(men[i].height-women[j].height)<=12 && abs(men[i].age-women[j].age)<=5 && men[i].status==women[j].status){
                    edge[i].push_back(j);
                }
            }
        }
        /*for(i=0;i<m;i++){
            printf("%d --> ",i);
            for(j=0;j<edge[i].size();j++) printf(" %d",j);
            printf("\n");
        }*/
        //cout<<"------------------>";
        printf("Case %d: %d\n",++kase,BPM());
    }
    return 0;
}
