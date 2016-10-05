#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,kase=0;
    double a,b,c,w,hi,lo,val;
    scanf("%d",&t);
    while(t--){
        scanf("%lf%lf%lf",&a,&b,&c);
        lo=0; hi=min(a,b);
        while(lo<=hi){
            w=(lo+hi)/2;
            val=(sqrt(a*a-w*w)*sqrt(b*b-w*w))/(sqrt(a*a-w*w)+sqrt(b*b-w*w));
            //cout<<val<<endl;
            if(val==c) break;
            else if(val<c) hi=w-.0000001;
            else if(val>c) lo=w+.0000001;
        }
        //cout<<"------>";
        printf("Case %d: %.10lf\n",++kase,w);
    }
    return 0;
}
