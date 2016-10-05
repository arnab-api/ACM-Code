#include<bits/stdc++.h>
using namespace std;

vector<int>v;

int main()
{
    int t,n,q,a,i,kase=0;
    char ch;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        v.clear();
        for(i=0;i<n;i++){
            scanf("%d",&a);
            v.push_back(a);
        }
        printf("Case %d:\n",++kase);
        while(q--){
            scanf(" %c",&ch);
            scanf("%d",&a);
            if(ch=='a') v.push_back(a);
            else if(ch=='c'){
                //cout<<"=------>";
                if(v.size()<a) printf("none\n");
                else{
                    printf("%d\n",v[a-1]);
                    v.erase(v.begin()+a-1);
                }
            }
        }
    }
    return 0;
}
