#include<bits/stdc++.h>
using namespace std;
#define M 505

int women_rank[M][M], men_rank[M][M];
int women_eng[M], men_eng[M];
int women_prefer[M][M], next[M];

void stable_marriage(int n)
{
    int i,j,women_index,a,b,d;
    stack<int>men_free;
    for(i=1;i<=n;i++){
        men_free.push(i);
        women_eng[i]=0;
        men_eng[i]=0;
        next[i]=1;
    }
    while(!men_free.empty()){
        a=men_free.top();
        women_index=next[a];
        next[a]++;

        b=men_rank[a][women_index];
        if(women_eng[b]==0){
            women_eng[b]=a;
            men_eng[a]=b;
            men_free.pop();
        }
        else{
            d=women_eng[b];
            if(women_prefer[b][a]<women_prefer[b][d]){
                women_eng[b]=a;
                men_eng[a]=b;
                men_free.pop();
                men_free.push(d);
                men_eng[d]=0;
            }
        }
    }
    for(i=1;i<=n;i++) printf("%d %d\n",i,men_eng[i]);
}

int main()
{
    int t,n,a,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a);
            for(j=1;j<=n;j++){
                scanf("%d",&women_rank[i][j]);
                women_prefer[a][women_rank[i][j]]=j;
            }
        }
        for(i=1;i<=n;i++){
            scanf("%d",&a);
            for(j=1;j<=n;j++){
                scanf("%d",&men_rank[i][j]);
            }
        }
        stable_marriage(n);
    }
    return 0;
}
