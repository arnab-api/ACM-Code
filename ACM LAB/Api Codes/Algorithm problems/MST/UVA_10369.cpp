#include<bits/stdc++.h>
using namespace std;
#define N 510

int n,m,s;
struct node{
    int x,y;
    node(int a,int b){
        x=a; y=b;
    }
};
double dist_node(node a, node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
struct edge{
    int ux,uy,vx,vy;
    double w;
    edge(int ax,int ay,int bx,int by,double c){
        ux=ax; vx=bx; w=c;
        uy=ay; vy=by;
    }
};
bool con(edge a, edge b)
{
    return a.w<b.w;
}
vector<edge>E;
vector<node>V;

int main()
{
    int t,i,j,a,b;
    scanf("%d",&t);
    while(t--){
        V.clear();
        E.clear();
        scanf("%d%d",&s,&n);
        for(i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            V.push_back(node(a,b));
        }
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                node A=node(V[i].x,V[i].y);
                node B=node(V[j].x,V[j].y);
                E.push_back(edge(A.x,A.y,B.x,B.y,dist_node(A,B)));
            }
        }
        sort(E.begin(),E.end(),con);
        for(i=0;i<E.size();i++){
            node A=node(E[i].ux,E[i].uy);
            node B=node(E[i].vx,E[i].vy);
            printf("(%d,%d)<-->(%d,%d)==>%lf\n",A.x,A.y,B.x,B.y,E[i].w);
        }
    }
    return 0;
}
