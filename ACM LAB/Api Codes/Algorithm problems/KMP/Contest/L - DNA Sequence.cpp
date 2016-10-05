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
#define sizee 1555
#define M 17
#define oo 1<<30

int lps[sizee];
string ans,ara[M],revara[M];
int DP[1<<M][M];

int calcLPS(string str1,string str2)
{
    reverse(str1.begin(),str1.end());
    string pat=str1+'#'+str2;
    int i,j,len=pat.size();
    i=1; j=0;
    lps[0]=0;
    while(i<len){
        if(pat[i]==pat[j]){
            lps[i]=j+1;
            i++; j++;
        }
        else{
            if(j!=0) j=lps[j-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps[len-1];
    //for(i=0;i<len;i++) printf("%d ",lps[i]);
    //printf("\n");
}

int Set(int N,int pos) { return N = N | (1<<pos);}
//bool Check(int N,int pos) { return (bool)(N & (1<<pos));}
bool Check(int N,int pos) { return (bool)(N & (1<<pos));}

int lim,mini,n;

int call(string str,int N,int cnt)
{
    //printf("called\n");
    //cout<<"-------->===> "<<str<<"  "<<N<<endl;
    int len;
    if(N>=lim-1) {
        //printf("----------------------------> called ");
        len=str.size();
        //cout<<str<<"  "<<N<<"  "<<len<<endl;
        if(len<mini) {
            ans=str;
            mini=len;
        }
        else if(len==mini) ans=min(ans,str);
        return str.size();
    }
    if(DP[N][cnt]!=-1) return DP[N][cnt];
    string mod;
    int x,i,j,q=INT_MAX;
    for(i=0;i<n;i++){
        if(!Check(N,i)){
            //printf("called\n");
            x=calcLPS(str,revara[i]);
            mod=str;
            for(j=x;j<ara[i].size();j++) mod+=ara[i][j];
            q=min(q,call(mod,Set(N,i),cnt+1));
        }
    }
    DP[N][cnt]=q;
}

int main()
{
    ios_base::sync_with_stdio (false);
    string str;
	int i,j,k,l,t,kase=0;
	scanf("%d",&t);
	while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++) {
            cin>>str;
            ara[i]=str;
            reverse(str.begin(),str.end());
            revara[i]=str;
        }
        memset(DP,-1,sizeof(DP));
        lim=(1<<n);
        mini=INT_MAX;
        ans="";
        call("",0,0);
        //cerr<<"---------------->";
        printf("Case %d: ",++kase);
        cout<<ans<<endl;
	}
	return 0;
}

/**
10
2
TAC
ACT
2
ACT
TAC
**/
