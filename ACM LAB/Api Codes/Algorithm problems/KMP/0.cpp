#include<bits/stdc++.h>
using namespace std;
#define M 1111

string text,pat;
int lps[M],n,m;

void computeLPS()
{
    memset(lps,-1,sizeof(lps));
    int i,j;
    lps[0]=0;
    i=1; j=0;
    while(i<n){
        if(pat[i]==pat[j]){
            lps[i]=j+1;
            j++;
            i++;
        }
        else{
            if(j!=0) j=lps[j-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    for(i=0;i<n;i++) printf("%d ",lps[i]);
    printf("\n");
}

void KMPsearch()
{
    computeLPS();
    int i=0,j=0;
    while(i<m){
        if(text[i]==pat[j]){
            i++;
            j++;
        }
        if(j==n) {
            printf("pattern found at %d\n",i-j);
            j=lps[j-1];
            //j=0;
        }
        else if(i<m && pat[j]!=text[i]){
            if(j!=0) j=lps[j-1];
            else i++;
        }
    }
}

int main()
{
    while(cin>>pat){
        n=pat.size();
        cin>>text;
        m=text.size();
        KMPsearch();
    }
    return 0;
}
/**
aba
abababa
ababcababababcabab*ababcababababcabab
aaaaa
**/
