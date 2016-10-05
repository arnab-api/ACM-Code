    #include<bits/stdc++.h>
    using namespace std;
    #define M 1010

    int used[M],Right[M],Left[M],m,n;
    vector<int>edge[M];

    void init()
    {
        for(int i=0;i<M;i++){
            used[i]=0;
            Left[i]=-1;
            Right[i]=-1;
            edge[i].clear();
        }
    }

    int match(int u)
    {
        if(used[u]==1) return 0;
        used[u]=1;
        for(int i=0;i<edge[u].size();i++){
            int v=edge[u][i];
            if(Left[v]==-1 || match(Left[v])){
                //if(Right[v]!=-1) continue;
                Left[v]=u;
                Right[u]=v;
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
            for(int i=1;i<=n;i++){
                if(!used[i] && Right[i]==-1){
                    path+=match(i);
                }
            }
        }
        for(int i=1;i<=n;i++) if(Right[i]!=-1) ret++;
        //for(int i=1;i<=n;i++) if(Right[i]==-1 && Left[i]==-1) ret++;
        return ret/2;
    }

    int main()
    {
        int t,kase=0,i,j,a,b;
        scanf("%d",&t);
        while(t--){
            init();
            scanf("%d%d",&n,&m);
            for(i=0;i<m;i++){
                scanf("%d%d",&a,&b);
                edge[a].push_back(b);
                edge[b].push_back(a);
            }
            //cout<<"------------------->";
            printf("Case %d: %d\n",++kase,n-BPM());
            //for(i=1;i<=n;i++) printf("%d  %d  %d\n",i,Left[i],Right[i]);
        }
        return 0;
    }

