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
#define MAX 1010
#define lli long long int

int fx[] = {0,0,1,-1};
int fy[] = {1,-1,0,0};
int w,h,g,e;
bool taken[1010];

struct Point
{
    int x;
    int y;
    Point(){}
    Point(int xx,int yy){
        x = xx;
        y = yy;
    }
    bool operator < (const Point & p)const{
        if(x == p.x) return y<p.y;
        return x < p.x;
    }
};

int grid[35][35],cnt;

map<Point,int>p2i;
map<int,Point>i2p;
vector<int>v[1010],cost[1010];

void init()
{
    p2i.clear();
    i2p.clear();
    cnt = 0;
    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            grid[i][j] = 0;
            p2i[Point(i,j)] = cnt;
            i2p[cnt] = Point(i,j);
            cnt++;
        }
    }
    for(int i=0;i<cnt;i++){
        v[i].clear();
        cost[i].clear();
    }
}

long long int D[1010];
const lli oo = 1ll << 61;

struct edge
{
    int u,v,w;
    edge(){}
    edge(int uu,int vv,int ww){
        u = uu;
        v = vv;
        w = ww;
    }
};

vector<edge>E;

void Build_graph()
{
    for(int i=0;i<cnt-1;i++) {
        Point p = i2p[i];
        if(grid[p.x][p.y]!=0) continue;
        for(int j=0;j<4;j++){
            int nx = p.x+fx[j];
            int ny = p.y+fy[j];
            if(nx>=0 && nx<w && ny>=0 && ny<h && grid[nx][ny]!=1) {
                v[i].push_back(p2i[Point(nx,ny)]);
                cost[i].push_back(1);
            }
        }
    }

    E.clear();
    for(int i=0;i<cnt;i++){
        for(int j=0;j<v[i].size();j++){
            E.push_back(edge(i,v[i][j],cost[i][j]));
        }
    }
}

bool Bellman_ford(int srce)
{
    int i,j;
    for(i=0;i<cnt;i++) {
        D[i] = oo;
    }
    memset(taken,false,sizeof(taken));
    D[srce]=0;
    taken[srce] = true;
    //for(i=1;i<=n;i++) printf("%d --> %d\n",i,D[i]);
    for(i=0;i<=cnt-1;i++){
        for(j=0;j<E.size();j++){
            int u=E[j].u;
            int v=E[j].v;
            int w=E[j].w;
            if(D[v]>D[u]+w) {
                if(taken[u]) {
                    taken[v] = true;
                    D[v]=D[u]+w;
                }
            }
        }
    }
    for(j=0;j<E.size();j++){
        int u=E[j].u;
        int v=E[j].v;
        int w=E[j].w;
        //printf("--> %d %d %d\n",u,v,w);
        if(D[v]>D[u]+w && taken[u]) return false;
    }
    return true;
}


int main()
{
    //freopen("labyrinth.in","r",stdin);
    //freopen("labyrinth.txt","w",stdout);
	int i,j,k,l,t,x,y,a,b,c;
	while(scanf("%d%d",&w,&h)==2){
        if(!w && !h) break;
        init();
        scanf("%d",&g);
        while(g--){
            scanf("%d%d",&x,&y);
            grid[x][y] = 1;
        }
        scanf("%d",&e);
        while(e--){
            scanf("%d%d",&x,&y);
            grid[x][y] = 2;
            scanf("%d%d",&a,&b);
            scanf("%d",&c);
            v[p2i[Point(x,y)]].push_back(p2i[Point(a,b)]);
            cost[p2i[Point(x,y)]].push_back(c);
        }
        Build_graph();

        /*for(i=0;i<cnt;i++){
            printf("%d --> %d %d ===> %d\n",i,i2p[i].x,i2p[i].y,p2i[i2p[i]]);
        }
        for(i=0;i<cnt;i++){
            printf("%d ---> ",i);
            for(j=0;j<v[i].size();j++) printf(" %d(%d)",v[i][j],cost[i][j]);
            printf("\n");
        }*/

        bool flag = Bellman_ford(0);
        //cerr<<"----------------------->   ";
        /*lli k = D[cnt-1];
        if(k == oo) printf("Impossible\n");
        else{
            if(!flag) printf("Never\n");
            else printf("%lld\n",k);
        }*/
        if(flag){
            lli k = D[cnt-1];
            if(k >= oo) printf("Impossible\n");
            else printf("%lld\n",k);
        }
        else printf("Never\n");
	}
	return 0;
}
/**
3 3
2
2 1
1 2
0
4 3
2
2 1
3 1
1
3 0 2 2 0
4 3
2
2 1
3 1
1
2 2 3 0 0
4 2
0
1
2 0 1 0 -3

4 3
2
2 0
2 1
2
3 1 3 0 5
3 0 3 1 -7

3 3
2
2 1
1 2
1
1 1 0 2 -10

0 0
*/

