#include<bits/stdc++.h>
using namespace std;
#define mn 10
#define root 1

int cnt;
bool flag;

struct node{
    int next[mn],word;
};
node trie[10000*26];

void init()
{
    memset(trie,0,sizeof(trie));
    cnt=1;
    flag=true;
}

void Insert(string str)
{
    int cur=root;
    int len=str.size();
    for(int i=0;i<len;i++){
        int id=str[i]-'0';
        if(trie[cur].next[id]==0) trie[cur].next[id]=++cnt;
        cur=trie[cur].next[id];
    }
    trie[cur].word=1;
}

void solve(int cur)
{
    if(!flag) return;
    bool leaf=true;
    for(int i=0;i<mn;i++){
        if(trie[cur].next[i]!=0){
            leaf=false;
            if(trie[cur].word==1) flag=false;
            solve(trie[cur].next[i]);
        }
    }
}

int main()
{
    int t,kase=0,i,n;
    string str;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        init();
        while(n--){
            cin>>str;
            Insert(str);
        }
        solve(root);
        printf("Case %d: ",++kase);
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
