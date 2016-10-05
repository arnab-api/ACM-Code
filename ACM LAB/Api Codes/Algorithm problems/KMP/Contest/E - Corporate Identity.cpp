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
#define M 211

int lps[M];
char pat[M],ara[4005][M];

int p,mn;

void calcLPS()
{
	int i=1,j=0;
	lps[0]=0;
	int len=strlen(pat);
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

int KMP(int id)
{
	calcLPS();
	int lenP=strlen(pat);
	int lenS=strlen(ara[id]);
	int i=0, j=0;
	int maxima=0;
	while(i<lenS){
		if(ara[id][i]==pat[j]){
			i++;
			j++;
			maxima=max(maxima,j);
		}
		if(j==lenP) {
			//printf("Pattern found at %d\n",i-j);
			j=lps[j-1];
		}
		else if(i<lenS && ara[id][i]!=pat[j]){
			if(j!=0) j=lps[j-1];
			else i++;
		}
	}
    return maxima;
}

void generate_pat(int st)
{
    int in=0,i;
    for(i=st;i<mn;i++) pat[in++]=ara[p][i];
    pat[in]='\0';
}

bool compare(int st1,int st2,int match)
{
    int i=st1,j=st2,cnt=0;
    for(cnt=0;cnt<match;cnt++){
        if(ara[p][i]>ara[p][j]) return true;
        else if(ara[p][i]<ara[p][j]) return false;

        i++;
        j++;
    }
    return false;
}

int main()
{
	int n,t,i,j,len,ret,match,st;
	bool fl;
	while(scanf("%d",&n)==1){
		if(n==0) break;
		mn=10010010;
		p=-1;
		for(i=0;i<n;i++) {
            scanf(" %s",&ara[i]);
            len=strlen(ara[i]);
            if(len<mn){
                p=i;
                mn=len;
            }
		}
		//for(i=0;i<n;i++) cout<<"===>"<<ara[i]<<endl;
		match=0;
		st=-1;
		for(i=0;i<mn;i++){
            generate_pat(i);
            ret=mn;
			for(j=0;j<n;j++){
                if(j==p) continue;
				ret=min(KMP(j),ret);
			}
			if(ret>match){
                match=ret;
                st=i;
            }
            if(ret==match){
                fl=compare(st,i,match);
                if(fl){
                    match=ret;
                    st=i;
                }
            }

            //cerr<<"====>"<<ret<<" "<<i;
            //cerr<<" >>>"<<match<<" "<<st<<endl;
		}
		//cerr<<"------------------>";
		if(match>0) {
            for(i=st;i<st+match;i++) printf("%c",ara[p][i]);
            printf("\n");
		}
		else printf("IDENTITY LOST\n");
	}
	return 0;
}

