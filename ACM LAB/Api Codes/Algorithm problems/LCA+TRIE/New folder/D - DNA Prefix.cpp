#include<bits/stdc++.h>
using namespace std;
#define A 0
#define C 1
#define G 2
#define T 3

struct node
{
    int child,word,len;
    node *next[6];
    node(){
        for(int i=0;i<4;i++) next[i]=NULL;
        child=0;
        word=0;
        len=0;
    }
}*root;

void Insert(string str,int l)
{
    node *cur=root;
    int i,id,d;
    for(i=0;i<l;i++){
        if(str[i]=='A') id=A;
        else if(str[i]=='T') id=T;
        else if(str[i]=='C') id=C;
        else if(str[i]=='G') id=G;
        if(cur->next[id]==NULL) cur->next[id]=new node();
        cur->child++;
        d=cur->len;
        cur=cur->next[id];
        cur->len=d+1;
    }
    cur->child++;
    cur->word=1;
}

void del(node *cur)
{
    for(int i=0;i<4;i++){
        if(cur->next[i]!=NULL) del(cur->next[i]);
    }
    delete cur;
}

int call(node *cur)
{
    int ret=(cur->len)*(cur->child);
    for(int i=0;i<4;i++){
        if(cur->next[i]!=NULL) ret=max(ret,call(cur->next[i]));
    }
    return ret;
}

int main()
{
    int t,n,kase=0,ans;
    string str;
    scanf("%d",&t);
    while(t--){
        root=new node();
        scanf("%d",&n);
        getchar();
        while(n--){
            cin>>str;
            //cout<<"==========>"<<str<<endl;
            Insert(str,str.size());
        }
        ans=call(root);
        printf("Case %d: %d\n",++kase,ans);
        del(root);
    }
    return 0;
}
