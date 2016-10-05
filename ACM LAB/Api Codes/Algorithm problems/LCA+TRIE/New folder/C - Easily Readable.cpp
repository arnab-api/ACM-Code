#include<bits/stdc++.h>
using namespace std;
#define M 100100
#define mn 52

struct node
{
    int word;
    node *next[mn+1];
    node(){
        for(int i=0;i<mn;i++) next[i]=NULL;
        word=0;
    }
}*root;

void Insert(char *str,int len)
{
    node *cur=root;
    for(int i=0;i<len;i++){
        int id=str[i];
        if(str[i]>='A' && str[i]<='Z') id=id-'A';
        else if(str[i]>='a' && str[i]<='z') id=id-'a'+25;
        if(cur->next[id]==NULL) cur->next[id]=new node();
        cur=cur->next[id];
    }
    cur->word++;
}

int Search(char *str,int len)
{
    //printf("%s --> %d\n",str,len);
    node *cur=root;
    for(int i=0;i<len;i++){
        int id=str[i];
        if(str[i]>='A' && str[i]<='Z') id=id-'A';
        else if(str[i]>='a' && str[i]<='z') id=id-'a'+25;
        if(cur->next[id]==NULL) return 0;
        cur=cur->next[id];
    }
    return cur->word;
}

void del(node *cur)
{
    for(int i=0;i<mn;i++) if(cur->next[i]!=NULL) del(cur->next[i]);
    delete (cur);
}

int main()
{
    int t,n,l,i,len,q,ans,kase=0;
    char str[110],line[M];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        root = new node();
        getchar();
        for(i=0;i<n;i++){
            gets(str);
            l=strlen(str);
            if(l>2) sort(str+1,str+l-1);
            //cout<<"============>";
            //puts(str);
            Insert(str,strlen(str));
        }
        scanf("%d",&q);
        getchar();
        printf("Case %d:\n",++kase);
        while(q--){
            gets(line);
            len=strlen(line);
            ans=1;
            int in=0;
            for(i=0;i<len;i++){
                if(line[i]==' '){
                    str[in]='\0';
                    l=strlen(str);
                    if(l>2) sort(str+1,str+l-1);
                    if(l>0) ans*=Search(str,strlen(str));
                    //cout<<"===================>"<<str<<"X"<<Search(str,strlen(str))<<endl;
                    in=0;
                }
                else str[in++]=line[i];
            }
            str[in]='\0';
            l=strlen(str);
            if(l>2) sort(str+1,str+l-1);
                if(l>0) ans*=Search(str,strlen(str));
            //cout<<"===================>"<<str<<"X"<<Search(str,strlen(str))<<endl;
            //cerr<<"----------------------->";
            printf("%d\n",ans);
        }
        del(root);
    }
    return 0;
}
/**
2
8
baggers
beggars
in
the
blowed
bowled
barn
bran
1
beggars bowled in the barn
8
Baggers
Beggars
in
The
Blowed
bowled
Barn
Bran
2
Beggars bowled in The Barn
beggars bowled in the barn
**/
