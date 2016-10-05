#include<bits/stdc++.h>
using namespace std;
#define MAX 10010
#define lli long long int

struct data
{
    lli beg,end;
    data(){}
    data(lli b,lli e)
    {
        beg = b;
        end = e;
    }
};

data arr[MAX];

int main()
{
    lli n,m,i,a,b,c,d,j;
    while(scanf("%lld%lld",&n,&m)==2){
        if(!n && !m) break;
        for(i=0;i<n;i++){
            scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
            arr[i] = data(c,c+d);
        }

        for(i=0;i<m;i++){
            scanf("%lld%lld",&a,&b);
            lli cnt = 0;
            b = a+b;
            for(j=0;j<n;j++){
                lli x = max(a,arr[j].beg);
                lli y = min(b,arr[j].end);
                if(x<y) cnt++;
            }
            cerr<<"------------------>  ";
            printf("%lld\n",cnt);
        }
    }
    return 0;
}
