#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
vector<int>edge[26];
int vis[26];

void init()
{
    for(int k=0;k<26;k++){
        vis[k]=0;
        edge[k].clear();
    }
}

void DFS(int p)
{
    vis[p]=1;
    for(int k=0;k<edge[p].size();k++) {
        if(!vis[edge[p][k]]) DFS(edge[p][k]);
    }
}

int main()
{
    int t,i,j;
    char ch,lim;
    string s;
    scanf("%d\n",&t);
    while(t--){
        scanf(" %c",&lim);
        char ara[10000],a,b;
        for(i=0;;i++){
            scanf("%c",&ara[i]);
            if(i!=0 && ara[i]=='\n' && ara[i-1]=='\n') break;
        }
        //for(j=0;j<=i;j++) printf("%c",ara[j]);
        init();
        for(j=0;j<=i;j++){
            if(ara[j]=='\n') continue;
            a=ara[j];
            j++;
            b=ara[j];
            edge[a-'A'].push_back(b-'A');
            edge[b-'A'].push_back(a-'A');
        }
        int cnt=0;
        /*for(i=0;i<=lim-'A';i++){
            printf("%d(%c)==>",i,i+'A');
            for(j=0;j<edge[i].size();j++) printf(" %d(%c)",edge[i][j],edge[i][j]+'A');
            printf("\n");
        }*/
        for(i=0;i<=lim-'A';i++) {
            if(!vis[i]){
                cnt++;
                DFS(i);
            }
        }
        printf("%d\n",cnt);
        if(t!=0) printf("\n");
    }
	return 0;
}
