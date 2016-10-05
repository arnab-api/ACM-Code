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
#define M 55
#define oo 1<<30

int fx[]={1,0,-1,0};
int fy[]={0,1,0,-1};

int n,nH,nG,used[M],level[M][M],Left[M],Right[M];
char grid[M][M];

struct info{
    int gh,dest;
    info(int a,int b){
        gh=a; dest=b;
    }
};

vector<info>edge[M];

struct jora{
    int x,y;
    jora(int a,int b){
        x=a; y=b;
    }
    bool operator < (const jora & p)const{
        if(x == p.x) return y < p.y;
        return x < p.x;
    }
};

map<jora,int>mpH,mpG;
map<jora,int> :: iterator it;

void init()
{
    mpH.clear();
    mpG.clear();
    nH=0; nG=0;
    for(int i=0;i<M;i++){
        edge[i].clear();
        used[i]=0;
        Right[i]=-1;
        Left[i]=-1;
        //for(int j=0;i<M;i++) level[i][j]=-1;
    }
}

void BFS(int x,int y)
{
    int r=mpH[jora(x,y)],i,j;
    for(i=0; i<M; i++){
        for(j=0 ;j<M; j++) level[i][j]=110;
    }
    level[x][y]=0;
    queue<int>q;
    q.push(x);
    q.push(y);
    while(!q.empty()){
        int ux=q.front(); q.pop();
        int uy=q.front(); q.pop();
        int ucost=level[ux][uy];
        for(i=0;i<4;i++){
            int nx=ux+fx[i];
            int ny=uy+fy[i];
            if(nx>=1 && nx<=n && ny>=1 && ny<=n && grid[nx][ny]!='#' && ucost+1<level[nx][ny]){
                level[nx][ny]=ucost+1;
                q.push(nx);
                q.push(ny);
                if(grid[nx][ny]=='G') edge[r].push_back(info(mpG[jora(nx,ny)],level[nx][ny]));
            }
        }
    }
}

int D[M];

int match(int u)
{
    if(used[u]==1) return 0;
    used[u]=1;
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i].gh;
        int d=edge[u][i].dest;
        if(Left[v]==-1 || (match(Left[v])==1 && d<D[u])){
            Right[u]=v;
            Left[v]=u;
            D[u]=d;
            return 1;
        }
    }
    return 0;
}

int BPM1()
{
    int path=1,ret=0;
    for(int i=0;i<M;i++) D[i]=220;
    while(path){
        path=0;
        memset(used,0,sizeof(used));
        for(int i=1;i<=nH;i++){
            if(!used[i] && Right[i]==-1){
                path+=match(i);
            }
        }
    }
    int maxi=0;
    //for(int i=1;i<=nH;i++) printf("-->%d %d => %d\n",i,Right[i],D[i]);
    for(int i=1;i<=nH;i++) {
        if(Right[i]==-1) return -1;
        if(D[i]>maxi) maxi=D[i];
    }
    return (maxi<<1)+2;
}

int match2(int u)
{
    if(used[u]==1) return 0;
    used[u]=1;
    //for(int i=edge[u].size()-1;i>=0;i--){
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i].gh;
        int d=edge[u][i].dest;
        if(Left[v]==-1 || (match2(Left[v])==1 && d<D[u])){
            Right[u]=v;
            Left[v]=u;
            D[u]=d;
            return 1;
        }
    }
    return 0;
}

int BPM2()
{
    int path=1,ret=0;
    for(int i=0;i<M;i++) {
        D[i]=220;
        Right[i]=-1;
        Left[i]=-1;
    }
    while(path){
        path=0;
        memset(used,0,sizeof(used));
        for(int i=nH;i>=1;i--){
            if(!used[i] && Right[i]==-1){
                path+=match2(i);
            }
        }
    }
    int maxi=0;
    //for(int i=1;i<=nH;i++) printf("-->%d %d => %d\n",i,Right[i],D[i]);
    for(int i=1;i<=nH;i++) {
        if(Right[i]==-1) return -1;
        if(D[i]>maxi) maxi=D[i];
    }
    return (maxi<<1)+2;
}

int main()
{
	int i,j,k,l,t,ans,kase=0;
	scanf("%d",&t);
	char ch;
	while(t--){
        init();
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf(" %c",&ch);
                grid[i][j]=ch;
                if(ch=='G') mpG[jora(i,j)]=++nG;
                if(ch=='H') mpH[jora(i,j)]=++nH;
            }
        }
        for(it=mpH.begin(); it!=mpH.end(); it++){
            jora J=it->first;
            BFS(J.x,J.y);
            //printf("H-->(%d %d)=>%d\n",J.x,J.y,mpH[J]);
        }
        //cout<<"\n\n\n";
        /*for(it=mpG.begin(); it!=mpG.end(); it++){
            jora J=it->first;
            printf("G-->(%d %d)=>%d\n",J.x,J.y,mpG[J]);
        }
        for(int i=1;i<=nH;i++){
            printf("%d==>",i);
            for(j=0;j<edge[i].size();j++) printf(" %d(%d)",edge[i][j].gh,edge[i][j].dest);
            printf("\n");
        }*/
        int r1,r2;
        r1=BPM1();
        r2=BPM2();
        printf("---->%d %d\n",r1,r2);
        ans=min(r1,r2);
        printf("Case %d: ",++kase);
        if(ans==-1) printf("Vuter Dol Kupokat\n");
        else printf("%d\n",ans);
	}
	return 0;
}

