#include<bits/stdc++.h>
using namespace std;
#define oo INT_MAX

int main()
{
    double s,neg,ans[5];
    int arr[5],Max,Mid,Min;
    while(scanf("%lf",&s)==1)
    {
        scanf("%d",&arr[0]);
        scanf("%d",&arr[1]);
        scanf("%d",&arr[2]);

        if(arr[0] == arr[1] && arr[0] == arr[2])
        {
            Max = 0;
            Mid = 1 ;
            Min = 2;
        }
        else
        {
            //cerr<<"==========>"<<endl;
            int curMax = -oo;
            int curMin = oo;
            for(int i=0; i<3; i++)
            {
                //cout<<arr[i]<<"   "<<curMax<<endl;
                if(arr[i]>curMax)
                {
                    curMax = arr[i];
                    Max = i;
                }
            }
            for(int i=0; i<3; i++) if(arr[i]<curMin && i!=Max)
                {
                    curMin = arr[i];
                    Min = i;
                }
            for(int i=0; i<3; i++) if(i!=Min && i!=Max) Mid = i;

        }

        //cout<<Max<<"   MAX === > "<<arr[Max]<<endl;
        //cout<<Min<<"   Min === > "<<arr[Min]<<endl;
        //cout<<Mid<<"   Mid === > "<<arr[Mid]<<endl;

        neg = 0.0;

        if(arr[Min]==0) ans[Min] = 0.0;
        else
        {
            ans[Min] = 1;
            neg += 1.0;
        }

        if(arr[Mid]==0) ans[Mid] = 0;
        else
        {
            ans[Mid] = 1;
            neg += 1.0;
        }
        //cout<<s<<" ==> "<<neg<<endl;
        ans[Max] = s - neg;

        printf("%lf %lf %lf\n",ans[0],ans[1],ans[2]);
    }
    return 0;
}
