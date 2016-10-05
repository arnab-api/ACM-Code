#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v;
    int n,a,q,d;
    while(scanf("%d",&n)==1){
        v.clear();
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            v.push_back(a);
        }
        scanf("%d",&q);
        while(q--){
            scanf("%d",&d);
            cout<<"====> "<<lower_bound(v.begin(),v.end(),d) - v.begin()<<endl;
            cout<<"====> "<<upper_bound(v.begin(),v.end(),d) - v.begin()<<endl;
        }
    }
    return 0;
}

/**

8
1 1 1 3 3 4 5 5
5
1
2
3
4
5

*/
