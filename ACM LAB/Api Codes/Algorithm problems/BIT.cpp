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


const int sz=1000*100;
int arr[sz];

void add(int id,int vlu){
    for(int i=id;i<sz;i+=(i&-i)){
        arr[i]+=vlu;
    }
    return ;
}
int read(int id){
    int sum=0;
    for(int i=id;i>0;i-=(i&-i)){
        sum+=arr[i];
    }
    return sum;
}

int main()
{
	int i,j,k,l,t;
	int n;
	string str;
	stringstream ss;
	while(cin>>str){
        ss<<str;
	}
	while(ss>>n)
{
    cout<<n;
}	return 0;
}

