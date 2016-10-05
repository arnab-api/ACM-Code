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
#define M 110
#define oo 1<<30

int DP[M][M],lenW;
char A[M],B[M],pat[M];

void calcLPS()
{
    int i,j,len=strlen(pat);
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
    //for(i=0;i<len;i++) printf("%d ",lps[i]);
    //printf("\n");
}

int calcLCS(int i,int j,int k)
{
    if(A[i]=='\0' || B[j]=='\0') return 0;
    if(DP[i][j]!=-1) return DP[i][j];
    if(A[i]==B[j]) {
        if(A[i]==pat[k]) k++;
        int val=calcLCS(i+1,j+1);
        if(k==lenW)
    }
    else{
        int val1=calcLCS(i+1,j);
        int val2=calcLCS(i,j+1);
        return DP[i][j]=max(val1,val2);
    }
}

string path;
int lcs;

void printLCS(int i,int j,int k)
{
    if(A[i]=='\0' || B[j]=='\0'){
        cout<<path<<endl;
        return;
    }
    if(A[i]==B[j]){
        path+=A[i];
        printLCS(i+1,j+1);
    }
    else{
        int val1=calcLCS(i+1,j);
        int val2=calcLCS(i,j+1);
        if(val1>val2) printLCS(i+1,j);
        else printLCS(i,j+1);
    }
}

int main()
{
	int i,j,k,l,t;
	while(scanf(" %s",&A)==1){
        scanf(" %s",&B);
        scanf(" %s",&pat);
        lenW=strlen(pat);
        memset(DP,-1,sizeof(DP));
        path="";
        lcs=0;
        lcs=calcLCS(0,0);
        cerr<<"------------------->"<<lcs<<endl;
        printLCS(0,0,0);

	}
	return 0;
}

