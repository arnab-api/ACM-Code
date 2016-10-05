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
#define M 110

struct node
{
    vector<int>mark;
    char ch;
    node *next[mn];
    node(){
        for(int i=0;i<mn;i++) next[i]=NULL;
        mark.clear();
        ch='#';
    }
}*root;

int get_id(char ch)
{
    if(ch=='?') return 26;
    if(ch=='*') return 27;
    return ch-'a';
}

void Insert(char *str,int len,int mark)
{
    node *cur=root;
    for(int i=0;i<len;i++){
        int id=get_id(str[i]);
        if(cur->next[id]==NULL) cur->next[id]=new node();
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

//set<int>ans;
//set<int>:: iterator it;
vector<int>ans;

char str[M];
int len;
/*void Search(int dep,node *cur)
{
    int i;
    if(dep==len){
        //cout<<cur->ch<<"  "<<cur->mark<<" "<<cur->leaf<<endl;
        if(!cur->mark.empty()) for(i=0;i<cur->mark.size();i++) ans.insert(cur->mark[i]);
        while(cur->next[27]!=NULL)
        {
            cur=cur->next[27];
            if(!cur->mark.empty()) for(i=0;i<cur->mark.size();i++) ans.insert(cur->mark[i]);
        }
        return;
    }
    char id=str[dep];
    if(cur->next[id-'a']!=NULL) Search(dep+1,cur->next[id-'a']);
    if(cur->next[26]!=NULL) Search(dep+1,cur->next[26]);
    if(cur->next[27]!=NULL) {
        Search(dep+1,cur->next[27]);
        Search(dep,cur->next[27]);
    }
    if(cur->ch=='*') if(dep<len) Search(dep+1,cur);
}*/

/*void Search(int dep,node *cur)
{
    if(cur->next[27]!=NULL) Search(dep,cur->next[27]);
    if(dep<len) if(cur->next[26]!=NULL) Search(dep+1,cur->next[26]);
    char id=cur->ch;
    int i;
    if(id!='*' && dep==len && !cur->mark.empty()){
        for(i=0;i<cur->mark.size();i++) ans.insert(cur->mark[i]);
    }
    if(id=='*'){
        if(!cur->mark.empty()){
            for(i=0;i<cur->mark.size();i++) ans.insert(cur->mark[i]);
        }
        for(i=dep;i<len;i++) if(cur->next[str[i]-'a']!=NULL) Search(i+1,cur->next[str[i]-'a']);
    }
    else if(dep<len){
        if(cur->next[str[dep]-'a']!=NULL) Search(dep+1,cur->next[str[dep]-'a']);
    }
}*/


void Search(node *cur,int dep,bool flag)
{
    if(cur->next[27]!=NULL) Search(cur->next[27],dep,true);
    if(dep<len && cur->next[26]!=NULL) Search(cur->next[26],dep+1,flag);
    int id;
    if(dep==len && !cur->mark.empty()) {
        for(int i=0;i<cur->mark.size();i++) ans.push_back(cur->mark[i]);
        return ;
    }
    if(flag){
        if(!cur->mark.empty()){
            for(int i=0;i<cur->mark.size();i++) ans.push_back(cur->mark[i]);
        }
        for(int i=dep;i<len;i++){
            id=get_id(str[i]);
            if(cur->next[id]!=NULL) Search(cur->next[id],i+1,false);
        }
    }
    else if(dep<len){
        id=get_id(str[dep]);
        if(cur->next[id]!=NULL) Search(cur->next[id],dep+1,false);
    }
}

int main()
{
    int n,q,i;
    char A[110];
    while(scanf("%d%d",&n,&q)==2){
        root=new node();
        getchar();
        for(i=0;i<n;i++){
            scanf(" %s",&A);
            Insert(A,strlen(A),i);
        }
        while(q--){
            scanf(" %s",str);
            len=strlen(str);
            ans.clear();
            //Search(0,root);
            Search(root,0,false);
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
