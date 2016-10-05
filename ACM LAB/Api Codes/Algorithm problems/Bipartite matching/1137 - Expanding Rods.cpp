#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)

int main()
{
    int t,kase=0,cnt=0;
    double L,L1,h,r,theta,n,c,hi,lo,val,H;
    scanf("%d",&t);
    while(t--){
        scanf("%lf%lf%lf",&L,&n,&c);
        L1=(1.0+n*c)*L;
        hi=pi; lo=0.0;
        cnt=0;
        while(lo<=hi && cnt<100){
            theta=(lo+hi)/2;
            r=L/(2*sin(theta));
            val=r*2*theta;
            if(val < L1) lo=theta;
            else hi=theta;
            cnt++;
        }
        H=r-r*cos(theta);
        printf("Case %d: %.10lf\n",++kase,H);
    }
    return 0;
}
