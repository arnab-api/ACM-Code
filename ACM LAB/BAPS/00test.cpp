#include<bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
    //freopen("0in.txt","r",stdin);
    //freopen("0out.txt","w",stdout);
    double m,o,d,p,rn;
    int t,kase=0,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%lf",&k,&d);
        printf("Case %d:\n",++kase);
        if(!k) {
            m = d;
            p = m/3.0;
            rn = 4.0*m/9.0;
            o = 2.0*m/9;
            printf("%.0lf\n",p);
            printf("%.0lf\n",rn);
            printf("%.0lf\n",o);
        }
        else{
            o = d;
            m = o * (9.0/2.0);
            rn = 4.0*m/9.0;
            p = m/3.0;
            printf("%.0lf\n",p);
            printf("%.0lf\n",rn);
            printf("%.0lf\n",m);
        }
    }
    return 0;
}
