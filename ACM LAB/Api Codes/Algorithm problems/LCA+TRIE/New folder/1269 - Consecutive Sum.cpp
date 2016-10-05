#include<bits/stdc++.h>
using namespace std;
#define M 50500

struct node
{
    int child,word,val;
    node *next[3];
    node()
    {
        for(int i=0;i<2;i++) next[i]=NULL;
        child=0;
        word=0;
        val=0;
    }
}*root;

string bin(int N)
{
    int i;
    string A="";
    char ch;
    while(N>0){
        ch=(N&1)+'0';
        A+=ch;
        N>>=1;
    }
    reverse(A.begin(),A.end());
    while(A.size()!=32) A='0'+A;
    return A;
}

void Insert(string str,int len,int val)
{
    node *cur=root;
    int i;
    for(i=0;i<len;i++){
        int id=str[i]-'0';
        if(cur->next[id]==NULL) cur->next[id]=new node();
        cur->child++;
        cur=cur->next[id];
    }
    cur->child++;
    cur->word++;
    cur->val=val;
}

int Search(string str,int len,int val,int dir)
{
    node *cur=root;
    int i;
    for(i=0;i<len;i++){
        int id=(str[i]-'0')^dir;
        if(cur->next[0]==NULL && cur->next[1]==NULL) break;
        if(cur->next[id]==NULL){
            //cout<<id<<endl;
            id=id^1;
            //cout<<"-->"<<id<<endl;
        }
        cur=cur->next[id];
    }
    int ret=(cur->val)^val;
    //cout<<"==>"<<val<<" "<<bin(val)<<endl;
    //cout<<"==>"<<cur->val<<" "<<bin(cur->val)<<endl;
    //cout<<"==>"<<ret<<" "<<bin(ret)<<endl;
    return (ret);
}

void del(node *cur)
{
    for(int i=0;i<2;i++) if(cur->next[i]!=NULL) del(cur->next[i]);
    delete (cur);
}

int main()
{
    int n,kase=0;
    //while(scanf("%d",&n)==1) cout<<bin(n)<<endl;
    int t,i,ara[M],sum[M],r,j,k;
    string B,rev;
    char ch;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%d",&ara[i]);
        r=0;
        root = new node();
        sum[0]=0;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        Insert("00000000000000000000000000000000",32,0);
        for(i=1;i<=n;i++){
            r=r^ara[i];
            sum[i]=r;
            B=bin(r);
            //cout<<B<<"====================>"<<r<<endl;
            maxi=max(maxi,Search(B,B.size(),r,1));
            mini=min(mini,Search(B,B.size(),r,0));
            //cout<<maxi<<"-----"<<mini<<endl;
            if(r!=0) Insert(B,B.size(),r);
        }
        //cerr<<"----------------------->";
        printf("Case %d: %d %d\n",++kase,maxi,mini);
        del(root);
    }
    return 0;
}
