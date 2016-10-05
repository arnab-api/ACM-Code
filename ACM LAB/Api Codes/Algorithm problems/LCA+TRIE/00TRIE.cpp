#include<bits/stdc++.h>
using namespace std;
#define M 100

struct node{
    int child;
    int word;
    node *next[55];
    node(){
        word=0;
        child=0;
        for(int i=0;i<=52;i++) next[i]=NULL;
    }
}*root;

void Insert(char *str,int l)
{
    node *cur=root;
    for(int i=0;i<l;i++){
        int id=str[i];
        if(str[i]>='A' && str[i]<='Z') id=id-'A' ;
        else if(str[i]>='a' && str[i]<='z') id=id-'a'+26;
        else id=52;
        //cout<<id<<endl;
        if(cur->next[id]==NULL) {
            cur->next[id]=new node();
            //cout<<"======>\n";
            //cur->next[id].child++;
        }
        cur->child++;
        cur=cur->next[id];
    }
    cur->child++;
    cur->word++;
}

int Search(char *str)
{
    int l=strlen(str);
    node *cur=root;
    for(int i=0;i<l;i++){
        int id=str[i];
        if(str[i]>='A' && str[i]<='Z') id=id-'A' ;
        else if(str[i]>='a' && str[i]<='z') id=id-'a'+26;
        else id=52;
        if(cur->next[id]==NULL) return 0;
        cur=cur->next[id];
    }
    return cur->word;
}

void del(node *cur)
{
    //cout<<"=====>"<<endl;
    for(int i=0;i<=52;i++){
        if(cur->next[i]!=NULL) del(cur->next[i]);
    }
    delete (cur);
}
int cnt;
double ans;
void call(node *cur,string S)
{
    if(cur->word){
        cout<<S;
        int x=cur->word;
        ans=((double)x*100.0)/double(cnt);
        printf(" %.4lf\n",ans);
    }
    for(int i=0;i<=52;i++){
        if(cur->next[i]) {
            char ch;
            if(i<52){
                if(i<26) ch='A'+i;
                else ch=i-26+'a';
            }
            else ch=' ';
            call(cur->next[i],S+ch);
        }
    }
}

int main()
{
    freopen("A.txt","w",stdout);
    char str[50];
    int t,i,j,k,l;
    double ans;
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--){
        cnt=0;
        root=new node();
        while(gets(str)){
            if(str[0]=='\0'){
                //printf("----XXX-----\n");
                break;
            }
            cnt++;
            //cout<<"----------------->";
            //puts(str);
            Insert(str,strlen(str));
        }
        call(root,"");
        if(t!=0) printf("\n");
        del(root);
    }
    return 0;
}
