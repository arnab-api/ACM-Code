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

int main()
{
    string b1,b2,s;
    int i,j,n,m,a,b,c=0,k;
    vector<string>v;
    while(scanf("%d",&n)==1){
        v.clear();
        for(i=0;i<n;i++){
            cin>>s;
            v.push_back(s);
        }
        scanf("%d",&m);
        vector<int>f,s,p;
        for(i=0;i<m;i++){
            cin>>b1>>b2;
            for(j=0;j<v.size();j++) if(v[j]==b1) break;
            a=j;
            for(j=0;j<v.size();j++) if(v[j]==b2) break;
            b=j;
            f.push_back(a);
            s.push_back(b);
        }
        for(i=0;i<v.size();i++) p.push_back(i);
        int r;
        while(next_permutation(p.begin(),p.end())){
            int r=1;
            for(i=0;i<f.size();i++){
                for(a=0;a<p.size();a++) if(p[a]==f[i]) break;
                for(b=0;b<p.size();b++) if(p[b]==s[i]) break;
                if(b<=a){
                    r=0;
                    break;
                }
            }
            if(r==1) break;
        }
        c++;
        printf("Case #%d: Dilbert should drink beverages in this order: ",c);
        for(i=0;i<p.size()-1;i++) cout<<v[p[i]]<<" ";
        cout<<v[p[p.size()-1]]<<".";
        cout<<endl<<endl;
    }
	return 0;
}
