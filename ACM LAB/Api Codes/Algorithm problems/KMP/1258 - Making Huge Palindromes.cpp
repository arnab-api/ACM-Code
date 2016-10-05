#include<bits/stdc++.h>
using namespace std;
#define M 1000100

string text,pat;
int n,m,lps[M],cnt;

void computeLPS()
{
    memset(lps,-1,sizeof(lps));
    int i,j;
    lps[0]=0;
    i=1; j=0;
    while(i<n){
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

int KMPsearch()
{
    n=pat.size();
    m=text.size();
    computeLPS();
    int i,j;
    i=0; j=0;
    while(i<m){
        if(text[i]==pat[j]){
            i++;
            j++;
        }
        if(j==n) {
            return j;
            printf("pattern found!\n");
            j=lps[j-1];
        }
        else if(i<m && pat[j]!=text[i]){
            if(j!=0) j=lps[j-1];
            else i++;
        }
    }
    return j;
}

int main()
{
    int t,kase=0;
    scanf("%d",&t);
    while(t--){
        cin>>text;
        pat=text;
        reverse(pat.begin(),pat.end());
        cnt=KMPsearch();
        //cout<<"-------->"<<cnt<<endl;
        printf("Case %d: %d\n",++kase,2*n-cnt);
    }
    return 0;
}
