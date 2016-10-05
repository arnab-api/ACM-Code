#include<bits/stdc++.h>
using namespace std;
#define mn 26
#define M 100100
#define root 1

struct node
{
    int first,second;
    int next[mn];
};

int cnt;
node trie[M];

void Insert(string str,int len)
{
    //cout<<"called"<<" "<<str<<" "<<len<<endl;
    int cur=root;
    for(int i=0;i<len;i++){
        int id=str[i]-'a';
        if(trie[cur].next[id]==0) trie[cur].next[id]=++cnt;
        cur=trie[cur].next[id];
    }
}

void call(int cur)
{
    bool leaf=true;
    for(int i=0;i<mn;i++){
        if(trie[cur].next[i]>0){
            leaf=false;
            int v=trie[cur].next[i];
            call(v);
            trie[cur].first=trie[cur].first | !trie[v].first;
            trie[cur].second=trie[cur].second | !trie[v].second;
        }
    }
    if(leaf){
        trie[cur].first=0;
        trie[cur].second=1;
    }
}

int main()
{
    int n,k,jor,bijor,ans,l;
    string A;
    while(scanf("%d%d",&n,&k)==2){
        memset(trie,0,sizeof(trie));
        getchar();
        cnt=1;
        while(n--){
            cin>>A;
            l=A.size();
            Insert(A,l);
        }
        call(root);
        printf("%d %d\n",trie[root].first,trie[root].second);
        if(trie[root].first==0) printf("Second\n");
        else if(trie[root].first==1 && trie[root].second==1) printf("First\n");
        else{
            //cout<<"=====>";
            if(k&1) printf("First\n");
            else printf("Second\n");
        }
    }
    return 0;
}
