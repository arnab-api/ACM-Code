#include<bits/stdc++.h>
using namespace std;
#define M 100010
#define oo INT_MAX

int tree[3*M],ara[M],n;

struct info{
    int data,index;
    info(int d,int i){
        data=d;
        index=i;
    }
};

bool con(info A,info B)
{
    return A.data<B.data;
}

vector<info>v;

void init(int node,int b,int e)
{
    if(b==e){tree[node]=ara[b]; return;}
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
}

int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b) return oo;
    if(i<=b && j>=e) return tree[node];
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return min(p1,p2);
}

int bin_search(int i,int j,int val)
{
    int pos=-1,it;
    int left=0;
    int right=v.size()-1;
    while(left<=right){
        int mid=(left+right)/2;
        //printf("-->%d\n",v[mid].data);
        if(v[mid].data==val) {
            it=mid;
            pos=v[mid].index;
            if(pos<i) while(v[it+1].data==val){
                if(v[it].index>=i && v[it].index<=j) break;
                it++;
            }
            else if(pos>j) while(v[it-1].data==val){
                if(v[it].index>=i && v[it].index<=j) break;
                it--;
            }
            pos=v[it].index;
            if(pos>=i && pos<=j) return pos;
        }
        if(val>v[mid].data) left=mid+1;
        else if(val<v[mid].data) right=mid-1;
    }
    return -1;
}

int maxi,maxb,maxe,cnt=0;

void recur(int b,int e)
{
    //if(cnt==20) return;
    if(b>e) return;
    int mini=query(1,1,n,b,e);
    if(mini*(e-b+1)>maxi){
        maxi=mini*(e-b+1);
        maxb=b;
        maxe=e;
    }
    int pos=bin_search(b,e,mini);
    //printf("%d-->%d %d (%d %d %d %d %d)\n",++cnt,mini,pos,maxi,maxb,maxe,b,e);
    recur(b,pos-1);
    recur(pos+1,e);
}

int main()
{
    int i,j,l,t,r,val,ans,kase=0;
    scanf("%d",&t);
    while(t--){
        v.clear();
        scanf("%d",&n);
        for(i=1;i<=n;i++) {
            scanf("%d",&ara[i]);
            v.push_back(info(ara[i],i));
        }
        init(1,1,n);
        sort(v.begin(),v.end(),con);
        /*for(i=0;i<v.size();i++) printf("%d(%d) ",v[i].data,v[i].index);
        printf("\n");
        for(i=1;i<20;i++) printf("%d-->%d\n",i,tree[i]);
        while(scanf("%d%d",&i,&j)==2){
            val=query(1,1,n,i,j);
            printf("min=%d && pos=%d\n",val,bin_search(i,j,val));
        }*/
        maxi=0;//query(1,1,n,1,n)*n;
        maxb=1;
        maxe=n;
        recur(1,n);
        printf("Case %d: %d\n",++kase,maxi);
    }
    return 0;
}
/*
9
44 33 77 11 22 99 55 66 88
*/

