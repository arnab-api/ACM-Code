#include<bits/stdc++.h>
using namespace std;

bool flag;

struct node
{
    int child,word;
    node *next[13];
    node(){
        child=0;
        word=0;
        for(int i=0;i<10;i++) next[i]=NULL;
    }
}*root;

void Insert(char *str,int len)
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

int Search(char *str,int len)
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
    for(int i=0;i<10;i++){
        if(cur->next[i]) del(cur->next[i]);
    }
    delete cur;
}

int main()
{
    int t,n,i;
    char str[20];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        getchar();
        root=new node();
        flag=true;
        while(n--){
            gets(str);
            //cerr<<"==============:>";
            //puts(str);
            if(flag) Insert(str,strlen(str));
        }
        if(!flag) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
