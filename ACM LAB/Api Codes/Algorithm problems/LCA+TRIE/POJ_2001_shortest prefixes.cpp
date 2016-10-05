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
#define M
#define oo 1<<30
using namespace std;

vector<string>v;

struct node
{
    int word,child;
    node *next[28];
    string prefix;
    node()
    {
        word=0;
        child=0;
        prefix="";
        for(int i=0;i<26;i++) next[i]=NULL;
    }
}*root;

void Insert(string S,int len)
{
    node *cur=root;
    string A;
    for(int i=0;i<len;i++){
        int id=S[i]-'a';
        if(cur->next[id]==NULL) {
            cur->next[id]=new node();
        }
        cur->child++;
        A=cur->prefix;
        cur=cur->next[id];
        cur->prefix=A+S[i];
    }
    cur->child++;
    cur->word++;
}

void del(node *cur)
{
    for(int i=0;i<26;i++){
        if(cur->next[i]!=NULL) del(cur->next[i]);
    }
    delete cur;
}

string Search(string S,int len)
{
    string ans="";
    ans+=S[0];
    node *cur=root;
    for(int i=0;i<len;i++){
        int id=S[i]-'a';
        cur=cur->next[id];
        if(cur->child>1) {
            if(i<len-1) ans=cur->prefix+S[i+1];
        }
    }
    if(cur->child>1) return S;
    return ans;
}

int main()
{
    v.clear();
    string A;
    root =  new node();
    while(cin>>A){
        Insert(A,A.size());
        v.push_back(A);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" "<<Search(v[i],v[i].length())<<endl;;
    }
    return 0;
}
