#include<bits/stdc++.h>
using namespace std;

string bin(int N)
{
    string S="";
    while(abs(N)>0){
        S+='0'+(N%2);
        N/=2;
    }
    reverse(S.begin(),S.end());
    return S;
}

int main()

{
    int a=4;
    cout<<a<<" "<<(~a)<<endl;
    cout<<a<<" "<<bin(a)<<endl;
    cout<<~a<<" "<<bin(~a)<<endl;
    return 0;
}
