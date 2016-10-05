#include <stdio.h>
#include<math.h>
int main()
{
    int i,n,m;
    int j,k = 1;
    int a = 0;


    scanf("%d",&n);
    int prime[n+1];

    prime[0]=2;

    for(i=3; ;i=i+2){
        for(j=3;j<=sqrt(i);j+=2){
            if(i%j==0){
                a = i;
                break;
            }
        }

        if(a!=i){
            prime[k] = i;
            k++;
        }

        if(prime[n]==i)
            break;
    }
    for(i=0;i<n;i++) printf("%d\n",prime[i]);
    while(1){

        scanf("%d",&m);
        printf("%d\n",prime[m-1]);

    }

    return 0;

}
