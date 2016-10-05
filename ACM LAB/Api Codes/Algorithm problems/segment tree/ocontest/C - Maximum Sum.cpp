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
#define M 100100
#define oo 1<<27

struct info{
    int data,pos;
};

info tree[3*M],ara[M],nul;

void init(int node,int b,int e)
{
    if(b==e){
        tree[node]=ara[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    if(tree[left].data>tree[right].data) tree[node]=tree[left];
    else tree[node]=tree[right];
}

void update(int node,int b,int e,int i,int j)
{
    if(b>i || e<i) return;
    if(b==e && e==i) {tree[node].data=j; return;}
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);
    if(tree[left].data>tree[right].data) tree[node]=tree[left];
    else tree[node]=tree[right];
}

info query(int node,int b,int e,int i,int j)
{
    if(b>j || e<i) return nul;
    if(b>=i && e<=j) return tree[node];
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    info p1=query(left,b,mid,i,j);
    info p2=query(right,mid+1,e,i,j);
    if(p1.data>p2.data) return p1;
    else return p2;
}

int main()
{
	int a,i,j,k,l,t,n,q,x,y;
	info m1,m2;
	nul.data=-oo;
	char dit;
	while(scanf("%d",&n)==1){
        //memset(tree,0,sizeof(tree));
        for(i=1;i<=n;i++) {
            scanf("%d",&a);
            ara[i].data=a;
            ara[i].pos=i;
        }
        init(1,1,n);
        scanf("%d",&q);
        while(q--){
            scanf(" %c",&dit);
            scanf("%d%d",&x,&y);
            if(dit=='U') update(1,1,n,x,y);
            else if(dit=='Q'){
                m1=query(1,1,n,x,y);
                //printf("--->%d %d\n",m1.data,m1.pos);
                update(1,1,n,m1.pos,0);
                m2=query(1,1,n,x,y);
                //printf("--->%d %d\n",m2.data,m2.pos);
                update(1,1,n,m1.pos,m1.data);
                //cout<<"====>";
                printf("%d\n",m1.data+m2.data);
            }
        }
	}
	return 0;
}

