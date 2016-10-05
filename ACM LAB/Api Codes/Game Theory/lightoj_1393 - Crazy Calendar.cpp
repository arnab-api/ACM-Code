#include<bits/stdc++.h>
using namespace std;
#define MAX 50050
#define lli long long int

int main()
{
    lli t,R,C,i,j,xor_sum,num,down,right,kase=0,way;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&R,&C);
        xor_sum = 0ll;
        for(i = 1; i <= R ; i++){
            for(j = 1; j<= C ; j++){
                scanf("%lld",&num);
                right = C - j;
                down = R - i;
                way = right + down;
                if(num && (way % 2)) xor_sum ^= num;
            }
        }
        //cout<<xor_sum<<endl;
        printf("Case %lld: ",++kase);
        if(xor_sum) printf("win\n");
        else printf("lose\n");
    }
    return 0;
}
