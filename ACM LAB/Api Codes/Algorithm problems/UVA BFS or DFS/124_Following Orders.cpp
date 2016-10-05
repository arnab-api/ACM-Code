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

int main()
{
    char ch;
    int i,j,k;
    vector<char>v,con;
    bool fst=true;
    while(scanf("%c",&ch)==1){
        if(!fst)printf("\n");
        v.clear();
        con.clear();
        if(ch!=' ') v.push_back(ch);
        for(i=0;;i++){
            scanf("%c",&ch);
            if(ch=='\n') break;
            if(ch!=' ') v.push_back(ch);
        }
        sort(v.begin(),v.end());
        //for(i=0;i<v.size();i++) printf("%c",v[i]);
        //        printf("\n");
        for(i=0;;i++){
            scanf("%c",&ch);
            if(ch=='\n') break;
            if(ch!=' ') con.push_back(ch);
        }
        //for(i=0;i<con.size();i++) printf("%c",con[i]);
        //        printf("\n");
        int r[con.size()];
        int p=1;
            for(j=0;j<con.size();j++){
                for(k=0;k<v.size();k++){
                    if(con[j]==v[k]) r[j]=k;
                }
            }
            for(j=0;j<con.size();j+=2) if(r[j]>r[j+1]){
                p=0;
                break;
            }
            for(j=0;j<con.size();j++){
                for(k=v.size()-1;k>-1;k--){
                    if(con[j]==v[k]) {
                        r[j]=k;
                        break;
                    }
                }
            }
            for(j=0;j<con.size();j+=2) if(r[j]>r[j+1]){
                p=0;
                break;
            }

            if(p==1) {
                for(i=0;i<v.size();i++) printf("%c",v[i]);
                printf("\n");
            }
        while(next_permutation(v.begin(),v.end())){
            int p=1;
            for(j=0;j<con.size();j++){
                for(k=0;k<v.size();k++){
                    if(con[j]==v[k]) {
                        r[j]=k;
                        break;
                    }
                }
            }
            for(j=0;j<con.size();j+=2) if(r[j]>r[j+1]){
                p=0;
                break;
            }

            for(j=0;j<con.size();j++){
                for(k=v.size()-1;k>-1;k--){
                    if(con[j]==v[k]) {
                        r[j]=k;
                        break;
                    }
                }
            }
            for(j=0;j<con.size();j+=2) if(r[j]>r[j+1]){
                p=0;
                break;
            }

            if(p==1) {
                for(i=0;i<v.size();i++) printf("%c",v[i]);
                printf("\n");
            }
        }
        if(fst) fst=false;
    }
	return 0;
}
