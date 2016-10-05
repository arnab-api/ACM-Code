#include<bits/stdc++.h>
using namespace std;
#define M 1000010

int ndiv[M];

void call()
{
    int p,k,temp,cnt;
    ndiv[1]=1;
    for(p=2;p<=M;p++){
        if(!ndiv[p]){
            for(k=p;k<=M;k+=p){
                if(!ndiv[k]) ndiv[k]=1;
                temp=k,cnt=0;
                while(temp%p==0){
                    temp=temp/p;
                    cnt++;
                }
                ndiv[k]=ndiv[k]*(cnt+1);
            }
        }
    }
}

int main()
{
    call();
    for(int i=3501;i<=3600;i++) printf("%d-->%d\n",i,ndiv[i]);
    return 0;
}
