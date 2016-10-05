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
#define MAX 100100
#define oo 1<<30

string text;
int revSA[MAX],SA[MAX],cnt[MAX],nxt[MAX];
bool bh[MAX],b2h[MAX];
int LCP[MAX];

bool cmp(const int & i,const int & j)
{
    return text[i]<text[j];
}

void sortFirstChar(int n)
{
    for(int i=0;i<n;i++) SA[i] = i;
    sort(SA,SA+n,cmp);
    for(int i=0;i<n;i++){
        bh[i] = (i==0 || text[SA[i]]!=text[SA[i-1]]);
        b2h[i] = false;
    }
    return;
}

int CountBucket(int n)
{
    int bucket = 0;
    for(int i=0,j;i<n;i=j){
        j=i+1;
        while(j<n && bh[j]==false) j++;
        nxt[i] = j;
        bucket++;
    }
    return bucket;
}

void SetRank(int n)
{
    for(int i=0;i<n;i=nxt[i]){
        cnt[i]=0;
        for(int j=i;j<nxt[i];j++) revSA[SA[j]]=i;
    }
}

void findNewRank(int l,int r,int step)
{
    for(int j=l;j<r;j++){
        int pre = SA[j] - step;
        if(pre>=0){
            int head = revSA[pre];
            revSA[pre] = head+cnt[head]++;
            b2h[revSA[pre]] = true;
        }
    }
}

void findNewBucket(int l,int r,int step)
{
    for(int j=l;j<r;j++){
        int pre = SA[j]-step;
        if(pre>=0 && b2h[revSA[pre]]){
            for(int k=revSA[pre]+1;b2h[k] && !bh[k];k++) b2h[k] = false;
        }
    }
}

void buildSA(int n)
{
    sortFirstChar(n);
    for(int h=1;h<n;h<<=1){
        if(CountBucket(n)==n) break;
        SetRank(n);
        b2h[revSA[n-h]] = true;
        cnt[revSA[n-h]]++;
        for(int i=0;i<n;i = nxt[i]){
            findNewRank(i,nxt[i],h);
            findNewBucket(i,nxt[i],h);
        }
        for(int i=0;i<n;i++){
            SA[revSA[i]]=i;
            bh[i]|=b2h[i];
        }
    }
}

void buildLCP(int n)
{
    int len=0;
    for(int i=0;i<n;i++) revSA[SA[i]]=i;
    for(int i=0;i<n;i++){
        int k = revSA[i];
        if(k==0){
            LCP[k]=0;
            continue;
        }
        int j = SA[k-1];
        while(text[i+len]==text[j+len]) len++;
        LCP[k] = len;
        if(len) len--;
    }
}

void printSA(int n)
{
    for(int i=0;i<n;i++) {
        printf("%2d  ",SA[i]);
        cout<<text.substr(SA[i])<<endl;
    }
    printf("\n");
    for(int i=1;i<n;i++) printf("%2d\n",LCP[i]);
    printf("\n");
    for(int i=0;i<n;i++) {
        cout<<text.substr(i);
        printf("    %2d\n",revSA[i]);
    }
    printf("\n");
}

void Check()
{
    int l;
    while(cin>>text){
        l=text.size();
        buildSA(l);
        buildLCP(l);
        printSA(l);
    }
}

int main()
{
    //Check();
    int test,kase=0,l,p,q,ans,i,len,val;
    scanf("%d",&test);
    while(test--){
        cin>>text;
        //cout<<text<<endl;
        l=text.size();
        buildSA(l);
        buildLCP(l);

        scanf("%d%d",&p,&q);
        ans=0;
        for(i=0;i<l;i++){
            len = l - SA[i];
            val = min(len,q) - max(LCP[i],p-1);
            if(val>0) ans+=val;
        }
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}

