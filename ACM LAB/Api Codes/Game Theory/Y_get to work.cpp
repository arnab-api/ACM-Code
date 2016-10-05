#include<bits/stdc++.h>
using namespace std;
#define MaxTown 110
#define MaxEmp 510

int vehicle[MaxTown],town[MaxEmp],carry[MaxEmp],office,N,emp[MaxTown],E;
vector<int>vec[MaxTown];

int main()
{
    int i,j,k,l;
    while(scanf("%d%d",&N,&office)==2){
        memset(vehicle,0,sizeof(vehicle));
        memset(emp,0,sizeof(emp));
        for(i=0;i<MaxTown;i++) vec[i].clear();
        scanf("%d",&E);
        for(i=0;i<E;i++){
            scanf("%d%d",&town[i],&carry[i]);
            emp[town[i]]++;
            vec[town[i]].push_back(carry[i]);
        }
        bool flag = true;
        for(i=1;i<=N;i++){
            if(!flag) break;
            if(i == office) continue;
            int j = 0;
            int sum = 0;
            sort(vec[i].begin(),vec[i].end());
            reverse(vec[i].begin(),vec[i].end());
            while(j < vec[i].size()){
                sum = sum+vec[i][j++];
                vehicle[i]++;
                if(sum>=emp[i]) break;
            }
            if(sum<emp[i]) flag = false;
        }
        if(!flag) printf("IMPOSSIBLE\n");
        else{
            for(int i=1;i<=N;i++){
                if(i>1) printf(" ");
                printf("%d",vehicle[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
