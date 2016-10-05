#include<bits/stdc++.h>
using namespace std;

int main()
{
    bool flag ;
    int n,i;
    char ch,str[1000];
    int len,word;
    while(scanf("%d",&n)==1){
        scanf(" %s",str);
        //puts(str);
        flag = false;
        len = word = 0;
        for(i=0;i<n;i++){
            //cout<<str[i];
            if(str[i] == '(') { flag = true; continue;}
            if(str[i] == ')') { flag = false; continue;}
            //cout<<">>>>>>>  "<<flag<<endl;
            if(!flag && str[i]!='_'){
                int cnt = 0;
                //cout<<"called"<< "  "<<i <<"  "<<str[i]<<endl;
                while((str[i]!='_' && str[i]!='(') && i<n){
                    //cout<<str[i]<<endl;
                    cnt++;
                    i++;
                }
                //cout<<"called"<< "  "<<i <<"  "<<str[i]<<endl;
                len = max(len,cnt);
                //cout<<"--------->>  "<<len<<endl;
            }
            else if(flag && str[i]!='_'){
                if(str[i]=='(') continue;
                word++;
                //cout<<"-------------- flag -------------\n";
                while((str[i]!='_' && str[i]!=')' && str[i]!='(') && i<n) {
                    //cout<<str[i]<<endl;
                    i++;
                }
            }
            if(str[i] == '(') flag = true;
            if(str[i] == ')') flag = false;
            //cout<<"-->>>>>>>  "<<flag<<endl;
        }
        printf("%d %d\n",len,word);
    }
    return 0;
}

