#include<bits/stdc++.h>
using namespace std;
#define MAX 1010

int arr[MAX];

int main()
{
    int t,n,ans,i,j,k,sum;
    scanf("%d",&t);
    while(t--){
        ans = 0;
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&arr[i]);
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                sum = arr[i] + arr[j];
                for(k=0;k<n;k++) {
                    if(k==i || k==j) continue;
                    ans = max(ans,sum^arr[k]);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
