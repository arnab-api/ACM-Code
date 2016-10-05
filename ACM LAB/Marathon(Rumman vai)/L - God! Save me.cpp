#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,kase=0;
    double p,x,ans,div;
    bool flag;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        div = 1.0;
        ans = 0.0;
        flag = false;
        while(n--){
            scanf("%lf%lf",&x,&p);
            ans += abs(x*p);
            if(x<0) div -= p;
            else flag = true;
        }
        printf("Case %d: ",++kase);
        if(!flag) printf("God! Save me\n");
        else{
            ans = ans/div;
            printf("%.2lf\n",ans);
        }
    }
    return 0;
}
/**
3
-2 0.33
-3 0.33
-5 0.34
3
2 0.34
-3 0.33
-5 0.33
*/
