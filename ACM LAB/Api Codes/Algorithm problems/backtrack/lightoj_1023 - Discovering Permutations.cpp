#include<bits/stdc++.h>
using namespace std;
#define M 30

int N,k,taken[30],cnt;

vector<int>v;

void call()
{
    if(cnt==k) return;
    if(v.size()==N){
        cnt++;
        //printf("---------------------> ");
        for(int i=0;i<N;i++) printf("%c",'A'+v[i]);
        printf("\n");
        return;
    }
    for(int i=0;i<N;i++){
        if(taken[i]==0){
            for(int j=0;j<i;j++) if(taken[j]==1) continue;
            taken[i]=1;
            v.push_back(i);
            call();
            taken[i]=0;
            v.pop_back();
        }
    }
}

int main()
{
    //freopen("A.txt","w",stdout);
    int t,kase=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&N,&k);
        v.clear();
        cnt=0;
        printf("Case %d:\n",++kase);
        call();
    }
    return 0;
}
