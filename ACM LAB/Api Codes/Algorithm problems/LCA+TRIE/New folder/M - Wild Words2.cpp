
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
#define mn 28

struct node
{
    int leaf;
    vector<int>mark;
    char ch;
    node *next[mn];
    node(){
        for(int i=0;i<mn;i++) next[i]=NULL;
        mark.clear();
        ch='#';
        leaf=0;
    }
}*root;

void Insert(string str,int len,int mark)
{
    node *cur=root;
    for(int i=0;i<len;i++){
        int id;
        if(str[i]=='*') id=27;
        else if(str[i]=='?') id=26;
        else id=str[i]-'a';
        if(cur->next[id]==NULL) cur->next[id]=new node();
        cur->leaf++;
        cur=cur->next[id];
        cur->ch=str[i];
    }
    cur->mark.push_back(mark);
}

void del(node *cur)
{
    for(int i=0;i<mn;i++) if(cur->next[i]) del(cur->next[i]);
    delete cur;
}

vector<int>ans;

void Search(string str,int dep,node *cur)
{
    int i;
    if(dep==str.length()){
        //cout<<cur->ch<<"  "<<cur->mark<<" "<<cur->leaf<<endl;
        if(!cur->mark.empty()) for(i=0;i<cur->mark.size();i++) ans.push_back(cur->mark[i]);
        while(cur->next[27]!=NULL)
        {
            cur=cur->next[27];
            if(!cur->mark.empty()) for(i=0;i<cur->mark.size();i++) ans.push_back(cur->mark[i]);
        }
        return;
    }
    char id=str[dep];
    if(cur->next[id-'a']!=NULL) Search(str,dep+1,cur->next[id-'a']);
    if(cur->next[26]!=NULL) Search(str,dep+1,cur->next[26]);
    if(cur->next[27]!=NULL) {
        Search(str,dep+1,cur->next[27]);
        Search(str,dep,cur->next[27]);
    }
    if(cur->ch=='*') if(dep<str.length()) Search(str,dep+1,cur);
}

int main()
{
    int n,q,i;
    string A;
    while(scanf("%d%d",&n,&q)==2){
        root=new node();
        getchar();
        for(i=0;i<n;i++){
            cin>>A;
            Insert(A,A.length(),i);
        }
        while(q--){
            cin>>A;
            ans.clear();
            Search(A,0,root);
            //cout<<"-------------------->";
            if(!ans.size()) printf("Not match");
            else {
                sort(ans.begin(),ans.end());
                for(i=0;i<ans.size();i++){
                    if(i>0 && ans[i]==ans[i-1]) continue;
                    if(i>0) printf(" ");
                    printf("%d",ans[i]);
                }
            }
            printf("\n");
        }
        del(root);
    }
    return 0;
}
/**
7 3
*
t?i*s**
t*s**
*
*th*
*t*h*i*s*
*?*
this
t
a
**/
