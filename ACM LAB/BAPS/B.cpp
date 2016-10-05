#include<bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
    //freopen("0in.txt","r",stdin);
    //freopen("0out.txt","w",stdout);
    double m,o,d,p,rn;
    string str;
    map<string,int>mp;
    map<string,int>:: iterator it;
    int t,kase=0,k,cnt;
    scanf("%d",&t);
    while(t--){
        mp.clear();
        scanf("%d",&k);
        while(k--){
            cin>>str;
            if(mp.find(str) == mp.end()) mp[str] = 1;
            else mp[str]++;
        }
        cnt = 0;
        for(it = mp.begin();it!=mp.end();it++){
            if(it->second > cnt) {
                str = it -> first;
                cnt = it -> second;
            }
        }
        printf("Case %d: ",++kase);
        cout<<str<<endl;
    }
    return 0;
}

