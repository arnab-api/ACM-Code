#include<bits/stdc++.h>
using namespace std;
#define M 1000

int sg[M];

int get_sg(int x)
{
    if(sg[x]!=-1) return sg[x];
    int vis[M];
    memset(vis,0,sizeof(vis));
    int half=(x-1)/2;
    for(int i=1;i<=half;i++) {
        vis[get_sg(i)^get_sg(x-i)]=1;
        printf("-->%d %d %d %d => %d\n",i,x-i,get_sg(i),get_sg(x-i),get_sg(i)^get_sg(x-i));
    }
    for(int i=0;i<=x;i++) printf("%d ",vis[i]);
    printf("\n");
    for(int i=0;;i++) if(!vis[i]) return sg[x]=i;
}

void call()
{
    memset(sg,-1,sizeof(sg));
    sg[0]=sg[1]=sg[2]=0;
}

int main()
{
    call();
    int x;
    while(scanf("%d",&x)==1){
        printf("===>%d\n",get_sg(x));
    }
    return 0;
}
