#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;

vector<char>v,con;
vector<char>p;
int taken[100];
int ara[30][30];

void call()
{
    if(p.size()==v.size()) {
        for(int i=0;i<v.size();i++) printf("%c ",p[i]);
        printf("\n");
    }
    for(int i=0;i<v.size();i++){
        int r=1;
        if(p.size()>1){
            for(int j=0;j<p.size()-1;j++){
                for(int k=j+1;k<p.size();k++){
                    if(ara[p[j]-'a'][p[k]-'a']==-1){
                        r=0;
                        return ;
                    }
                }
            }
        }
        if(!taken[i] && r==1){
            taken[i]=1; p.push_back(v[i]);
            call();
            taken[i]=0; p.pop_back();
        }
    }
}

int main()
{
    char ch;
    int i,j,k;
    while(scanf("%c",&ch)==1){
        v.clear();
        con.clear();
        for(i=0;i<30;i++){
            for(j=0;j<30;j++) ara[i][j]=0;
        }
        if(ch!=' ') v.push_back(ch);
        for(i=0;;i++){
            scanf("%c",&ch);
            if(ch=='\n') break;
            if(ch!=' ') v.push_back(ch);
        }
        sort(v.begin(),v.end());
        for(i=0;;i++){
            scanf("%c",&ch);
            if(ch=='\n') break;
            if(ch!=' ') con.push_back(ch);
        }
        char a,b;
        for(i=0;i<con.size()-1;i+=2){
            a=con[i];
            b=con[i+1];
            ara[b-'a'][a-'a']=-1;
        }
        //for(i=0;i<10;i++){
        //    for(j=0;j<10;j++) printf("%d",ara[i][j]);
            //printf("\n");
        //}
        call();
        printf("\n");
    }
	return 0;
}

