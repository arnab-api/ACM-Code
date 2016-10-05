#include<bits/stdc++.h>
using namespace std;
#define MAX 111

double P,p_arr[MAX];
int m_arr[MAX],N;
double DP[MAX][MAX*MAX];
int pp[MAX][MAX*MAX];

double call(int index,int amount,double sum)
{
    //cout<<"called"<<"---> "<<index<<"----> "<<amount<<"-----> ";
    //printf("%.6f\n",sum);
    if(sum>=1.0) return 10101010;
    if(index==N){
        if(amount<=0) return 0;
        return 1000010;
    }
    double &ret = DP[index][amount];
    if(ret>-1.0) {
        //cout<<"returned"<<endl;
        return ret;
    }
    double p1 = 1000010,p2 = 1000010;
    //printf(" ------->>>>>>>>>>>>>>>>>>> %lf %lf\n",sum,(1.0 - sum)*p_arr[index]);
    p1 = (1.0 - sum)*p_arr[index] + call(index+1,amount - m_arr[index],sum+p_arr[index]);
    p2 = call(index+1,amount,sum);
    return ret = min(p1,p2);
}

int binarySearch(int lo,int hi,int sum)
{
    int mid,res;
    double val;
    while(lo<=hi){
        mid = (lo+hi)/2;
        for(int i=0;i<N;i++){
            for(int j=0; j<=sum+5;j++) DP[i][j] = -2.0;
        }
        val = call(0,mid,0.0);
        //printf("%.6f  %.6f",val,P);
        //cout<<"   => "<<hi<<" "<<lo<<" "<<mid<<endl;
        if(val>P-.000001) hi = mid - 1;
        else {
            lo = mid + 1;
            res = mid;
        }
    }
    memset(pp,-1,sizeof(pp));
    return res;
}

int main()
{
    freopen("00in.txt","r",stdin);
    //freopen("00out.txt","w",stdout);
    int kase=0,t;
    scanf("%d",&t);
    while(t--){
        int sum = 0;
        scanf("%lf%d",&P,&N);
        for(int i=0;i<N;i++) {
            scanf("%d%lf",&m_arr[i],&p_arr[i]);
            sum+=m_arr[i];
        }
        //cout<<"-----> " <<sum<<endl;
        int ans = binarySearch(0,sum,sum);
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}
