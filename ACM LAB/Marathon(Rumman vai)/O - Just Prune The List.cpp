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
#define lli long long int

map<int,int>mp1,mp2;
map<int,int>:: iterator it1,it2;
set<int>st;
set<int>:: iterator it;

int main()
{
	int i,j,k,l,t,a,cnt,n,m;
	scanf("%d",&t);
	while(t--){
        scanf("%d%d",&n,&m);
        mp1.clear();
        mp2.clear();
        st.clear();
        cnt = 0;
        for(i=0;i<n;i++){
            scanf("%d",&k);
            if(mp1.find(k)==mp1.end()) mp1[k]=1;
            else mp1[k]++;
            st.insert(k);
        }
        for(i=0;i<m;i++){
            scanf("%d",&k);
            if(mp2.find(k)==mp2.end()) mp2[k]=1;
            else mp2[k]++;
            st.insert(k);
        }
        for(it=st.begin();it!=st.end();it++){
            if(mp1.find(*it)==mp1.end()) mp1[*it] = 0;
            if(mp2.find(*it)==mp2.end()) mp2[*it] = 0;
            //printf("%d ===> %d %d\n",*it,mp1[*it],mp2[*it]);
            cnt += abs(mp1[*it] - mp2[*it]);
        }
        //cerr<<"-------------->";
        printf("%d\n",cnt);
	}
	return 0;
}

