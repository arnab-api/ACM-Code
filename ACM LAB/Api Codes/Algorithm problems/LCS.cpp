#include<bits/stdc++.h>
using namespace std;
#define M 110

string A,B,ans;
int dp[M][M],mp_in=0;
bool vis[M][M];

map<string,int>mp;

void init()
{
    ans="";
    mp.clear(); mp_in=0;
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            dp[i][j]=-1;
            vis[i][j]=false;
        }
    }
}

int calcLCS(int i,int j)
{
    if(A[i]=='\0' || B[j]=='\0') return 0;
    if(vis[i][j]) return dp[i][j];
    int r=0;
    if(A[i]==B[j]) r=1+calcLCS(i+1,j+1);
    else{
        int val1=calcLCS(i,j+1);
        int val2=calcLCS(i+1,j);
        r=max(val1,val2);
    }
    vis[i][j]=true;
    dp[i][j]=r;
    return dp[i][j];
}

void printLCS(int i,int j)
{
    if(A[i]=='\0' || B[j]=='\0'){
        cout<<"-->"<<ans<<endl;
        return;
    }
    if(A[i]==B[j]){
        ans+=A[i];
        printLCS(i+1,j+1);
    }
    else{
        if(dp[i+1][j]>dp[i][j+1]) printLCS(i+1,j);
        else printLCS(i,j+1);
    }
}

void printALL(int i,int j)
{
    if(A[i]=='\0' || B[j]=='\0'){
        if(mp.find(ans)==mp.end()){
            cout<<"==>>"<<ans<<endl;
            mp[ans]=mp_in++;
        }
        return;
    }
    if(A[i]==B[j]){
        ans+=A[i];
        printALL(i+1,j+1);
        ans.erase(ans.size()-1);
    }
    else{
        if(dp[i+1][j]>dp[i][j+1]) printALL(i+1,j);
        else if(dp[i+1][j]<dp[i][j+1]) printALL(i,j+1);
        else{
            printALL(i+1,j);
            printALL(i,j+1);
        }
    }
}

int main()
{
    while(cin>>A>>B){
        init();
        cout<<calcLCS(0,0)<<endl;
        printLCS(0,0);
        ans="";
        printALL(0,0);
    }
    return 0;
}
