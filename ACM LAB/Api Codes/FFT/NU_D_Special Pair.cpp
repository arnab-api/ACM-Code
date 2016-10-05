#include<bits/stdc++.h>
using namespace std;
#define M 1010


int arr[M];
vector<int>v[M];

void init()
{
    for(int i=0;i<M;i++){
        v[i].clear();
    }
}

int main()
{
    int n,q,l,r,t,kase=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
        init();
        for(int i=0;i<n;i++){
            if(arr[i]==0) continue;
            for(int j=0;j<n;j++){
                if(arr[j]==0) continue;
                if(arr[i]>arr[j] && arr[i]%arr[j]==0){
                    v[i].push_back(j);
                }
            }
        }
        printf("Case %d:\n",++kase);
        while(q--){
            scanf("%d%d",&l,&r);
            l-- ; r-- ;
            int ans = 0;

            /*for(int i=l;i<=r;i++){
                printf("%d --> ",i);
                for(int j=0;j<v[i].size();j++) printf(" %d",v[i][j]);
                printf("\n");
            }*/
            for(int i=l;i<=r;i++){
                int idl = lower_bound(v[i].begin(),v[i].end(),l) - v[i].begin();
                int idr = upper_bound(v[i].begin(),v[i].end(),r) - v[i].begin();
                //cout<<idl<<"   "<<idr<<endl;
                ans += idr - idl;
            }
            cerr<<" ------------>";
            printf("%d\n",ans);
        }
    }
    return 0;
}
/**
20
4 2
2 1 10 5
1 2
3 4

3 1
2 2 2
1 3

5 7
12 4 6 3 2
*/
