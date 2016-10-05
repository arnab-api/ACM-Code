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
#define M 111

int lps[M];

void calcLPS(string pat)
{
	int i=1,j=0;
	lps[0]=0;
	int len=pat.size();
	while(i<len){
		if(pat[i]==pat[j]){
			lps[i]=j+1;
			i++;
			j++;
		}
		else{
			if(j!=0) j=lps[j-1];
			else{
				lps[i]=0;
				i++;
			}
		}
	}
}

string KMP(string pat,string seq)
{
	calcLPS(pat);
	int lenP=pat.size();
	int lenS=seq.size();
	int i=0, j=0;
	int maxi=0;
	while(i<lenS){
		if(seq[i]==pat[j]){
			i++;
			j++;
			maxi=max(maxi,j);
		}
		if(j==lenP) {
			//printf("Pattern found at %d\n",i-j);
			j=lps[j-1];
		}
		else if(i<lenS && seq[i]!=pat[j]){
			if(j!=0) j=lps[j-1];
			else i++;
		}
	}

	string str="";
	for(i=0;i<maxi;i++) str+=pat[i];
	return str;
}

int main()
{

	/*string pat,seq;
	while(cin>>pat){
		cin>>seq;
		cout<<KMP(pat,seq,0)<<endl;
	}*/
	string ara[12];
	string ans,ret,pat,out;
	int n,t,i,j,len;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			cin>>ara[i];
		}
		//for(i=0;i<n;i++) cout<<"===>"<<ara[i]<<endl;
		len=ara[0].size();
		pat=ara[0];
		out="";
		for(i=0;i<len;i++){
            ans=ara[0];
		    if(i!=0) pat.erase(pat.begin());
			for(j=1;j<n;j++){
				ret=KMP(pat,ara[j]);
				//cout<<"=====>"<<ret<<endl;
				if(ret.size()<ans.size()) ans=ret;
				if(ret.size()==ans.size()) ans=min(ans,ret);
			}
            if(ans.size()>out.size()) out=ans;
            if(ans.size()==out.size()) out=min(ans,out);
		}
		//cerr<<"------------------>";
		if(out.size()<3) printf("no significant commonalities\n");
		else cout<<out<<endl;
	}
	return 0;
}
