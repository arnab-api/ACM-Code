#include<bits/stdc++.h>
using namespace std;
#define M 510

int can_rank[M][M],com_rank[M][M];
int can_eng[M], com_eng[M];
int com_prefer[M][M], next[M];

void Stable(int n)
{
    int a,b,d,i,com_index;
    stack<int>can_free;
    for(i=1;i<=n;i++){
        can_free.push(i);
        can_eng[i]=0;
        com_eng[i+n]=0;
        next[i]=1;
    }
    while(!can_free.empty()){
        a=can_free.top();
        com_index=next[a];
        next[a]++;
        b=can_rank[a][com_index];
        if(com_eng[b]==0){
            com_eng[b]=a;
            can_eng[a]=b;
            can_free.pop();
        }
        else{
            d=com_eng[b];
            if(com_prefer[b][a]<com_prefer[b][d]){
                com_eng[b]=a;
                can_eng[a]=b;
                can_eng[d]=0;
                can_free.pop();
                can_free.push(d);
            }
        }
    }
    for(i=1;i<=n;i++) printf(" (%d %d)",i,can_eng[i]);
}

int main()
{
    int t,a,i,j,n,kase=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++) scanf("%d",&can_rank[i][j]);
        }
        for(i=n+1;i<=2*n;i++){
            for(j=1;j<=n;j++){
                scanf("%d",&com_rank[i][j]);
                com_prefer[i][com_rank[i][j]]=j;
            }
        }
        printf("Case %d:",++kase);
        Stable(n);
        printf("\n");
    }
    return 0;
}
