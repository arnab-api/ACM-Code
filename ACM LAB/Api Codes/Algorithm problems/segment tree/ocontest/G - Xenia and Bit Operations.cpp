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
#define M 1050000
#define oo 1<<30
#define Xor 2
#define Or 1

struct info
{
    int data,opr;
};

info tree[3*M];
int ara[M];

void call(int node,int b,int e)
{
    if(b==e){tree[node].opr=Xor; return;}
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    call(left,b,mid);
    call(right,mid+1,e);
    if(tree[left].opr==Xor) tree[node].opr=Or;
    else tree[node].opr=Xor;
    //printf("%d %d %d --> %d\n",node,b,e,tree[node].opr);
}

void init(int node,int b,int e)
{
    if(b==e){tree[node].data=ara[b]; return;}
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    if(tree[node].opr==Or) tree[node].data=tree[left].data | tree[right].data;
    else tree[node].data=tree[left].data ^ tree[right].data;
    //printf("%d %d %d ===> %d %d %d %d\n",node,b,e,tree[node].data,tree[node].opr,tree[left].data,tree[right].data);
}

void update(int node,int b,int e,int p,int x)
{
    if(b>p || e<p) return;
    if(b==e && b==p){tree[node].data=x; return;}
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    update(left,b,mid,p,x);
    update(right,mid+1,e,p,x);
    if(tree[node].opr == Or) tree[node].data=tree[left].data | tree[right].data;
    else tree[node].data = tree[left].data ^ tree[right].data;
}

int main()
{
	int i,j,k,l,t,n,m;
	while(scanf("%d%d",&n,&m)==2){
        for(i=0;i<3*M;i++){
            tree[i].data=0;
            tree[i].opr=0;
        }
        n=1<<n;
        call(1,1,n);
        for(i=1;i<=n;i++) scanf("%d",&ara[i]);
        init(1,1,n);
        //printf("===>%d\n",tree[1].data);
        while(m--){
            scanf("%d%d",&i,&j);
            update(1,1,n,i,j);
            //cout<<"--->";
            printf("%d\n",tree[1].data);
        }
	}
	return 0;
}

