#include<bits/stdc++.h>
using namespace std;
#define M 100100
#define root 1

struct node
{
    int word;
    int next[53];
    /*node(){
        for(int i=0;i<53;i++) next[i]=0;
        word=0;
    }*/
};
node trie[100010];
int t_in;

void Insert(char *str,int len)
{
    int cur=root;
    for(int i=0;i<len;i++){
        int id=str[i];
        if(str[i]>='A' && str[i]<='Z') id=id-'A';
        else if(str[i]>='a' && str[i]<='z') id=id-'a'+26;
        if(trie[cur].next[id]==0) trie[cur].next[id]=++t_in;
        cur=trie[cur].next[id];
    }
    trie[cur].word++;
}

int Search(char *str,int len)
{
    //printf("%s --> %d\n",str,len);
    int cur=root;
    for(int i=0;i<len;i++){
        int id=str[i];
        if(str[i]>='A' && str[i]<='Z') id=id-'A';
        else if(str[i]>='a' && str[i]<='z') id=id-'a'+26;
        if(trie[cur].next[id]==0) return 0;
        cur=trie[cur].next[id];
    }
    return trie[cur].word;
}

int main()
{
    //freopen("B.txt","w",stdout);
    int t,n,l,i,len,q,ans,kase=0;
    char str[110],line[M];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(trie,0,sizeof(trie));
        t_in=1;
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
           // cout<<"===================>"<<str<<"X"<<Search(str,strlen(str))<<endl;
            //cerr<<"----------------------->";
            printf("%d\n",ans);
        }
    }
    return 0;
}
/**
1
8
in
the
blowed
bowled
barn
bran
baggers
beggars
1
in the barn beggars bowled
**/

