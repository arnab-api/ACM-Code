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

bool flag;

struct node
{
    int child,word;
    node *next[5];
    node(){
        child=0;
        word=0;
        for(int i=0;i<3;i++) next[i]=NULL;
    }
}*root;

void Insert(string str,int len)
{
    node *cur=root;
    for(int i=0;i<len;i++){
        int id=str[i]-'0';
        if(cur->next[id]==NULL) cur->next[id]=new node();
        cur->child++;
        if(cur->word) flag=false;
        cur=cur->next[id];
    }
    cur->child++;
    cur->word++;
    if(cur->child>1) flag=false;
}

int Search(string str,int len)
{
    node *cur=root;
    for(int i=0;i<len;i++){
        int id=str[i]-'0';
        if(cur->next[id]==NULL) return 0;
        cur->child++;
        cur=cur->next[id];
    }
    return cur->word;
}

void del(node *cur)
{
    for(int i=0;i<3;i++){
        if(cur->next[i]) del(cur->next[i]);
    }
    delete cur;
}

int main()
{
    string A;
    int kase=0;
    flag=true;
    root=new node();
    while(cin>>A){
        if(A=="9"){
            printf("Set %d ",++kase);
            if(!flag) printf("is not immediately decodable\n");
            else printf("is immediately decodable\n");
            del(root);
            root= new node();
            flag=true;
        }
        else{
            if(flag) Insert(A,A.size());
        }
    }
    return 0;
}

