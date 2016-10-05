#include<bits/stdc++.h>
using namespace std;
#define M 100010
#define oo INT_MAX

vector<int>sub_arr[4*M];
int tree[4*M],ara[M],n;
int mini,maxi;

void clr()
{
    for(int i=0;i<4*M;i++){
        sub_arr[i].clear();
    }
    mini=oo;
    maxi=-oo;
}

void build(int node,int b,int e)
{
    if(b>e) return;
    if(b==e) {sub_arr[node].push_back(ara[b]); return;}
    int mid=(b+e)/2;
    int left=node*2;
    int right=node*2+1;
    build(left,b,mid);
    build(right,mid+1,e);

    int lpos=0,rpos=0,ll=sub_arr[left].size(),rl=sub_arr[right].size();
    while(lpos<ll && rpos<rl){
        if(sub_arr[left][lpos]<=sub_arr[right][rpos]){
            sub_arr[node].push_back(sub_arr[left][lpos]);
            lpos++;
        }
        else{
            sub_arr[node].push_back(sub_arr[right][rpos]);
            rpos++;
        }
    }
    while(lpos<ll){
        sub_arr[node].push_back(sub_arr[left][lpos]);
        lpos++;
    }
    while(rpos<rl){
        sub_arr[node].push_back(sub_arr[right][rpos]);
        rpos++;
    }
    //printf("%d %d==>",b,e);
    //for(int i=0;i<sub_arr[node].size();i++) printf(" %d",sub_arr[node][i]);
    //printf("\n");
}

vector<int>seg;
void select(int node,int b,int e,int i,int j)
{
    //printf("%d %d %d %d\n",b,e,i,j);
    if(b>j || e<i) return;
    if(b>=i && e<=j){seg.push_back(node); return;}
    int mid=(b+e)/2;
    int left=node*2;
    int right=node*2+1;
    select(left,b,mid,i,j);
    select(right,mid+1,e,i,j);
}

int bin_srch2(int node,int x)
{
    int cnt=0;
    cnt+=lower_bound(sub_arr[node].begin(),sub_arr[node].end(),x+1)-sub_arr[node].begin();
    return cnt;
}

int bin_srch1(int lo,int hi,int k)
{
    int left=lo,right=hi,l_bound=-1;
    while(left<=right){
        //printf("%d %d",left,right);
        int mid=(left+right)/2;
        int val=0;
        for(int i=0;i<seg.size();i++){
            val+=bin_srch2(seg[i],mid);
        }
        //printf(" %d %d\n",val,k);
        if(val>=k){
            l_bound=mid;
            right=mid-1;
        }
        else left=mid+1;
    }
    return l_bound;
}

int solve(int l,int r,int k)
{
    seg.clear();
    select(1,1,n,l,r);
    /*for(int i=0;i<seg.size();i++){
        printf("%d -->",seg[i]);
        for(int j=0;j<sub_arr[seg[i]].size();j++) printf(" %d",sub_arr[seg[i]][j]);
        printf("\n");
    }*/
    return bin_srch1(mini,maxi,k);
    return -1;
}

int main()
{
    int q,i,j,l,r,k,ans;
    while(scanf("%d%d",&n,&q)==2){
        clr();
        for(i=1;i<=n;i++) {
            scanf("%d",&ara[i]);
            mini=min(mini,ara[i]);
            maxi=max(maxi,ara[i]);
        }
        //for(i=1;i<=n;i++) printf("%d ",ara[i]);
        //printf("\n");
        build(1,1,n);
        //for(i=0;i<sub_arr[1].size();i++) printf("%d ",sub_arr[1][i]);
        //printf("\n");
        while(q--){
            scanf("%d%d%d",&l,&r,&k);
            ans=solve(l,r,k);
            //cerr<<"==========>";
            printf("%d\n",ans);
        }
    }
    return 0;
}
