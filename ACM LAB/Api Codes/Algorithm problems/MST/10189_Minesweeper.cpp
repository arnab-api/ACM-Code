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
#define ll long long int

int fx[]={-1,0,1,-1,1,-1,0,1};
int fy[]={1,1,1,0,0,-1,-1,-1};

int main()
{
    int n,m,i,j,k,x,y,kase=0;
    char in[110][110];
    int ara[110][110];
    bool first=true;
    while(scanf("%d%d",&n,&m)==2){
        if(n==0 && m==0) break;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++) scanf(" %c",&in[i][j]);
        }
        /*for(i=0;i<n;i++){
            for(j=0;j<m;j++) printf("%c",in[i][j]);
            printf("\n");
        }*/
        for(i=0;i<n;i++){
            for(j=0;j<m;j++) ara[i][j]=0;
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(in[i][j]=='*'){
                    for(k=0;k<8;k++){
                        x=i+fx[k];
                        y=j+fy[k];
                        if(x>=0 && x<n && y>=0 && y<m) ara[x][y]++;
                    }
                }
            }
        }
        kase++;
        if(!first) printf("\n");
        else first=false;
        printf("Field #%d:\n",kase);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(in[i][j]=='*') printf("*");
                else printf("%d",ara[i][j]);
            }
            printf("\n");
        }
        //printf("\n");
    }
	return 0;
}
