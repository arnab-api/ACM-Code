//#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<climits>
#include<cstring>
#include<cstdlib>

#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>

#include<vector>
#include<map>
#include<string>
#include<queue>
#include<set>
#include<iterator>
#include<numeric>
#include<stack>
#include<list>
using namespace std;
#define pi acos(-1)
#define M
#define oo 1<<30

struct data{
    int a,b,c;
    data(){}
    data(int x,int y,int z){
        a = x;
        b = y;
        c = z;
    }
    bool operator < (const data & p)const{
        if(a == p.a && b == p.b) return c < p.c;
        if(a == p.a) return b < p.b;
        return a < p.a;
    }
};

vector<data>v;
set<data>st;
set<data>:: iterator it;

int main()
{
	int i,j,k,l,t;
	int n,x,y,z;
	scanf("%d",&t);
	while(t--){
        scanf("%d",&n);
        v.clear();
        st.clear();
        for(i=0;i<n;i++){
            scanf("%d%d%d",&x,&y,&z);
            //v.push_back(data(z,x,y));
            v.push_back(data(x,y,z));
        }
        sort(v.begin(),v.end());

        for(i=0;i<n;i++){
            x = v[i].a ; y = v[i].b ; z = v[i].c;
            st.insert(data(x,y,z));
            bool flag = true;
            while(flag){
                it = st.find(data(x,y,z));
                flag = false;
                if(it!=st.begin()){
                    it--;
                    data D = *it;
                    if(D.a<=x && D.b<=y && D.c<=z){
                        st.erase(it);
                        flag = true;
                    }
                }
            }
        }
        //cerr<<"---------------->";
        printf("%d\n",st.size());
	}
	return 0;
}
/**
3
3
1 2 3
2 3 1
3 1 2
3
1 2 3
2 3 1
1 2 3
3
1 2 3
1 2 3
1 2 3
*/

