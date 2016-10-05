#include<bits/stdc++.h>
using namespace std;

int main()
{
    double cow,car,show,ans,total;
    while(scanf("%lf%lf%lf",&cow,&car,&show)==3){
        total = cow + car;
        ans = (cow*car + car*(car-1))/(total * (total - show - 1));
        printf("%.5lf\n",ans);
    }
    return 0;
}
