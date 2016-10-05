#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,avg,ans,mini;
    while(scanf("%d%d%d",&a,&b,&c)==3){
        mini = 1000100;
        for(avg = 1;avg<=100;avg++){
            ans = 0;
            ans += abs(avg - a);
            ans += abs(avg - b);
            ans += abs(avg - c);
            //printf("%d\n",ans);
            mini = min(mini,ans);
        }
        cout<<mini<<endl;
    }
    return 0;
}
