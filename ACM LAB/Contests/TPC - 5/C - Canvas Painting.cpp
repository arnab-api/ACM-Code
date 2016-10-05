#include<bits/stdc++.h>
using namespace std;
#define lli long long int

priority_queue<lli>pq;

int main()
{
    lli t,n,p,a,b,c,ans;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        while(!pq.empty()) pq.pop();
        while(n--){
            scanf("%lld",&a);
            pq.push(-a);
        }
        ans = 0;
        while(pq.size()>1){
            a = pq.top() ; pq.pop();
            b = pq.top() ; pq.pop();
            c = a+b;
            ans += c;
            pq.push(c);
        }
        printf("%lld\n",-ans);
    }
    return 0;
}
/**
2
3
7 4 7
4
5 3 5 7
*/
