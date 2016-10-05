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
#define M 50050

int ara[M],frst[M],scnd[M],nxt[M];

vector<int> D[M];

void find_D(int pos)
{
    int num=pos;
    int i;
    for(i=1;i*i<=num;i++){
        if(num%i==0){
            D[pos].push_back(i);
            if(i!=(num/i)) D[pos].push_back(num/i);
        }
    }
}

struct Query{
    int l,r,nxt,ans;
};

Query Q[M];

int tree[5*M];

int query(int node,int b,int e,int from,int to)
{
    if(b>to || e<from) return 0;
    if(b>=from && e<=to) return tree[node];
    int mid=(b+e)/2;
    int left=node*2;
    int right=node*2+1;
    int p1=query(left,b,mid,from,to);
    int p2=query(right,mid+1,e,from,to);
    return max(p1,p2);
}

void update(int node,int b,int e,int p,int newval)
{
    if(b>p || e<p) return;
    if(b>=p && e<=p) {tree[node]=newval; return;}
    int mid=(b+e)/2;
    int left=node*2;
    int right=node*2+1;
    update(left,b,mid,p,newval);
    update(right,mid+1,e,p,newval);
    tree[node]=max(tree[left],tree[right]);
}

void init()
{
    memset(tree,0,sizeof(tree));
    memset(frst,-1,sizeof(frst));
    memset(scnd,-1,sizeof(scnd));
    memset(nxt,-1,sizeof(nxt));
}

int main()
{
    int t,n,q,l,r,i,j,a;
    for(i=1;i<=M;i++) find_D(i);
    scanf("%d",&t);
    while(t--){
        init();

        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&ara[i]);
        }
        scanf("%d",&q);
        for(i=1;i<=q;i++){
            scanf("%d%d",&l,&r);
            Q[i].l=l;
            Q[i].r=r;
            Q[i].nxt=nxt[r];
            nxt[r]=i;
        }
        //sort(Q+1,Q+q+1);
        for(i=1;i<=n;i++){
            //printf("%d -->",ara[i]);
            for(j=0;j<D[ara[i]].size();j++){
                a=D[ara[i]][j];
                //printf(" %d",a);
                if(frst[a]==-1) frst[a]=i;
                else{
                    if(scnd[a]==-1){
                        if(a>query(1,1,n,frst[a],frst[a])) update(1,1,n,frst[a],a);
                        scnd[a]=i;
                    }
                    else{
                        //if(a==query(1,1,n,frst[a],frst[a]))update(1,1,n,frst[a],0);
                        frst[a]=scnd[a];
                        if(a>query(1,1,n,frst[a],frst[a])) update(1,1,n,frst[a],a);
                        scnd[a]=i;
                    }
                }
                //printf("(%d %d)",frst[a],scnd[a]);
            }
            //printf("\n");
            for(j=nxt[i];j!=-1;j=Q[j].nxt){
                //printf("===>%d\n",j);
                //if(j==-1) break;
                //printf("--->%d %d --> ",Q[j].l,Q[j].r);
                Q[j].ans=query(1,1,n,Q[j].l,Q[j].r);
                //printf("%d\n",Q[j].ans);
            }
        }
        for(i=1;i<=q;i++) printf("%d\n",Q[i].ans);
    }
    return 0;
}

/*
1
10
8 2 4 9 5 7 10 6 1 3
4
2 10
2 4
6 9
7 10
*/
