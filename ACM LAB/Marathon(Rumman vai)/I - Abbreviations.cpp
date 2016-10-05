#include<bits/stdc++.h>
using namespace std;

map<string,int>mp;
map<string,int>:: iterator it1;

vector<string>v,seq;

void init()
{
    mp.clear();
    seq.clear();
    v.clear();

}

string compare2(string str1,string str2)
{
    int i1 = 0,i2 = 0,l1 = str1.size(),l2 = str2.size();
    string ret = "";
    while(i1!=l1 && i2!=l2){
        if(str1[i1]!=str2[i2]) break;
        ret+=str1[i1];
        i1++; i2++;
    }
    if(i2<l2) ret+=str2[i2];
    return ret;
}

string compare3(string str1,string str2,string str3)
{
    string ret1 = compare2(str1,str2);
    string ret2 = compare2(str3,str2);
    return max(ret1,ret2);
}

int main()
{
    int n,i,kase=0;
    string str,ans[110];
    while(scanf("%d",&n)==1){
        if(!n) break;
        init();
        for(i=0;i<n;i++){
            cin>>str;
            mp[str] = i;
            v.push_back(str);
            seq.push_back(str);
        }
        printf("%d\n",++kase);
        if(n==1) cout<<seq[0]<<" "<<seq[0][0]<<endl;
        else{
            sort(v.begin(),v.end());
            for(i=0;i<n;i++){
                if(i==0) ans[mp[v[i]]] = compare2(v[i+1],v[i]);
                else if(i==n-1) ans[mp[v[i]]] = compare2(v[i-1],v[i]);
                else ans[mp[v[i]]] = compare3(v[i-1],v[i],v[i+1]);
                //cerr<<"-------->  "<<v[i]<<" ===> "<<ans[mp[v[i]]]<<endl;
            }
            for(i=0;i<n;i++){
                cout<<seq[i]<<" "<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
/**
4
cat
dog
mouse
horse
3
ant
antelope
anteater
1
ant
2
aabb
aaa
0
*/
