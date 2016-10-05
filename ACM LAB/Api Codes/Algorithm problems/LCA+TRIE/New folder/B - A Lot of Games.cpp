#include<bits/stdc++.h>
using namespace std;
#define mn 26

struct node
{
    int first,second;
    node *next[mn];
    node(){
        for(int i=0;i<mn;i++) next[i]=NULL;
        first=0;
        second=0;
    }
}*root;

void Insert(string str,int len)
{
    node *cur=root;
    for(int i=0;i<len;i++){
        int id=str[i]-'a';
        if(cur->next[id]==NULL) cur->next[id]=new node();
        cur=cur->next[id];
    }
}

void call(node *cur,int dep)
{
    bool End=true;
    for(int i=0;i<mn;i++){
        if(cur->next[i]){
            End=false;
            call(cur->next[i],dep+1);
            cur->first = cur->first | (((cur->next[i])->first)^1);
            cur->second = cur->second | (((cur->next[i])->second)^1);
        }
    }
    if(End){
        dep=dep%2;
        cur->first=0;
        cur->second=1;
    }
}

void del(node *cur)
{
    for(int i=0;i<mn;i++) if(cur->next[i]!=NULL) del(cur->next[i]);
    del(cur);
}

int main()
{
    int n,k,jor,bijor,ans,l;
    string A;
    while(scanf("%d%d",&n,&k)==2){
        getchar();
        root=new node();
        while(n--){
            cin>>A;
            l=A.size();
            Insert(A,l);
        }
        call(root,0);
        printf("%d %d\n",root->first,root->second);
        if(root->first==0) printf("Second\n");
        else if(root->first==1 && root->second==1) printf("First\n");
        else{
            //cout<<"=====>";
            if(k&1) printf("First\n");
            else printf("Second\n");
        }
    }
    return 0;
}
