#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("00Out.txt","w",stdout);
    int n,c,pre,a,cnt;
    while(scanf("%d%d",&n,&c)==2){
        pre = -1;
        cnt = 1;
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            if(pre != -1){
                if(a-pre>c) cnt = 1;
                else cnt++;
            }
            pre = a;
        }
        //cerr<<"------------>";
        printf("%d\n",cnt);
    }
    return 0;
}

