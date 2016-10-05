#include<bits/stdc++.h>
using namespace std;

vector<string>food,frst;
int cnt[110],a[110];

void init()
{
    food.clear();
    frst.clear();
    memset(cnt,0,sizeof(cnt));
}

int main()
{
    int n,k,l,f,m;
    string str;
    while(scanf("%d",&n)==1){
        init();
        for(int i=0;i<n;i++){
            cin>>str;
            food.push_back(str);
        }
        scanf("%d",&k);
        scanf("%d",&f);
        int available = n - f;
        for(int i=0;i<f;i++){
            cin>>str;
            frst.push_back(str);
        }
        for(int i=0;i<k;i++){
            scanf("%d",&a[i]);
            for(int j=0;j<a[i];j++){
                cin>>str;
                for(l=0;l<f;l++) if(str==frst[l]) cnt[i]++;
            }
        }
        scanf("%d",&m);
        for(int i=0;i<k;i++){
            cerr<<"----------->>> ";
            if(cnt[i]==a[i]) printf("YES\n");
            else{
                int danger = a[i] - cnt[i];
                //cout<<cnt[i]<<"  "<<a[i]<<"  "<<danger<<" "<<available<<" "<<m<<" ";
                if(danger > available - m) printf("NO\n");
                else printf("MAYBE\n");
            }
        }
    }
    return 0;
}
