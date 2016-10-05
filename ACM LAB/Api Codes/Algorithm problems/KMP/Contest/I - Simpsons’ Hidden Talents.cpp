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
#define M 150000
#define oo 1<<30

string pat,add;
int lps[M];
void calcLPS()
{
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
    //for(i=0;i<len;i++) printf("%d ",lps[i]);
    //printf("\n");
}

int main()
{
    int x,i;
    while(cin>>pat){
        pat+='#';
        cin>>add;
        pat+=add;
        calcLPS();
        x=lps[pat.size()-1];
        //cerr<<"------------------>";
        for(i=0;i<x;i++) printf("%c",pat[i]);
        if(x!=0) printf(" ");
        printf("%d\n",x);
    }
    return 0;
}
