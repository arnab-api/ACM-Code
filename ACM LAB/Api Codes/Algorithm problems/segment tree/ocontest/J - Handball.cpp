#include<stdio.h>

int main()
{
    int n,m,i,j,a,cnt,flag;
    while(scanf("%d%d",&n,&m)==2){
        cnt=0;
        for(i=0;i<n;i++){
            flag=1;
            for(j=0;j<m;j++){
                scanf("%d",&a);
                if(a==0) flag=0;
            }
            if(flag) cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
