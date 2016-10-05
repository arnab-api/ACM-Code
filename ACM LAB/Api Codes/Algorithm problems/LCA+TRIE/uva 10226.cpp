#include<bits/stdc++.h>
using namespace std;

int main()
{
    char str[50];
    string A;
    int t,i,j,k,l,cnt;
    double ans;
    map<string,int>mp;
    map<string,int>:: iterator it;
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--){
        cnt=0;
        mp.clear();
        while(gets(str)){
            if(str[0]=='\0'){
                //printf("----XXX-----\n");
                break;
            }
            cnt++;
            //cout<<"----------------->";
            //puts(str);
            l=strlen(str);
            A="";
            for(i=0;i<l;i++) A+=str[i];
            if(mp.find(A)==mp.end()) mp[A]=1;
            else mp[A]++;
        }
        for(it=mp.begin();it!=mp.end();it++){
            A=it->first;
            cout<<A;
            ans=((double)mp[A]*100.0)/double(cnt);
            printf(" %.4lf\n",ans);
        }
        if(t!=0) printf("\n");
    }
    return 0;
}
/**
2

Red Alder
Ash
Aspen
Basswood
Ash
Beech
Yellow Birch
Ash
Cherry
Cottonwood
Ash
Cypress
Red Elm
Gum
Hackberry
White Oak
Hickory
Pecan
Hard Maple
White Oak
Soft Maple
Red Oak
Red Oak
White Oak
Poplan
Sassafras
Sycamore
Black Walnut
Willow

arnab
api
sen
sharma
api


**/
