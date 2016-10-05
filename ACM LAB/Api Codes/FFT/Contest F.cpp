#include<bits/stdc++.h>
using namespace std;
#define MAX 100100

int res[MAX],Q[MAX],q;
int calcLIS()
{
    int r=0,j;
    res[r++]=Q[1];
    for(int i=2;i<=q;i++){
        if(Q[i]<res[0]) res[0]=Q[i];
        else if(Q[i]>=res[r-1]) res[r++]=Q[i];
        else{
            j=lower_bound(res,res+r,Q[i])-res;
            if(res[j]<Q[i]) j++;
            res[j]=Q[i];
        }
    }
    return r;
}

int main()
{
    int t,a,asc,dsc;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&q);
        for(int i=1;i<=q;i++) scanf("%d",&Q[i]);
        asc = calcLIS();
        reverse(Q+1,Q+q+1);
        dsc = calcLIS();

        cerr<<"===========> "<<asc<<"  "<<dsc<<endl;
        if(asc>=q-1 || dsc>=q-1) printf("YES\n");
        else printf("NO\n");
     }
    return 0;
}
/**
6
1 4 9 5 6 7

3
3
2 1 7
3
3 2 1
5
3 1 4 1 5
*/
