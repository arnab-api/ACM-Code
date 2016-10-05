#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
vector<int>order[105],ans;
int taken[105];
void init()
{
    for(int i=0;i<105;i++){
        order[i].clear();
        taken[i]=0;
    }
    ans.clear();
}
void take(int p)
{
    if(!taken[p]){
        for(int i=0;i<order[p].size();i++) take(order[p][i]);
        taken[p]=1;
        ans.push_back(p);
    }
}
int main()
{
    string b1,b2,s;
    vector<string>v;
    int i,j,n,m,a,b,c=0;;
    while(scanf("%d",&n)==1){
        v.clear();
        for(i=0;i<n;i++){
            cin>>s;
            v.push_back(s);
        }
        init();
        scanf("%d",&m);
        for(i=0;i<m;i++){
            cin>>b1>>b2;
            for(j=0;j<v.size();j++) if(v[j]==b1) break;
            a=j;
            for(j=0;j<v.size();j++) if(v[j]==b2) break;
            b=j;
            order[b].push_back(a);
        }
        for(i=0;i<v.size();i++){
            take(i);
        }
        c++;
        printf("Case #%d: Dilbert should drink beverages in this order: ",c);
        for(i=0;i<ans.size()-1;i++) cout<<v[ans[i]]<<" ";
        cout<<v[ans[ans.size()-1]]<<".";
        cout<<endl<<endl;
    }
	return 0;
}
