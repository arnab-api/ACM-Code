//#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<climits>
#include<cstring>
#include<cstdlib>

#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>

#include<vector>
#include<map>
#include<string>
#include<queue>
#include<set>
#include<iterator>
#include<numeric>
#include<stack>
#include<list>
using namespace std;
#define pi acos(-1)
#define M 100000000
#define sizee (int)(M/5)

int status[sizee+5];
bool Check(int N,int pos) {return (bool)( N & 1<<pos);}
int Set(int N,int pos) {return N=N | (1<<pos);}

/*void sieve()
{
    int n,i,j;
    for(i=2*2;i<=M;i+=2) status[i/32]=Set(status[i/32],i%32);

    for(i=3;i*i<=M;i+=2){
        if(!Check(status[i/32],i%32)){
            for(j=i*i;j<=M;j+=2*i){
                status[j/32]=Set(status[j/32],j%32);
            }
        }
    }
    printf("2\n");
    int cnt=1;
    for(i=3;i<=M;i+=2) {
        if(!Check(status[i/32],i%32)){
            cnt++;
            //printf("%d -> %d\n",cnt,i);
            if(cnt%100==1) printf("%d\n",i);
        }
    }
}
*/
void sieve()
{
    int n,i,j;
    for(i=2*2;i<=M;i+=2) status[i>>5]=Set(status[i>>5],i & 31);

    for(i=3;i*i<=M;i+=2){
        if(!Check(status[i>>5],i&31)){
            for(j=i*i;j<=M;j+= 2*i){
                status[j>>5]=Set(status[j>>5],j & 31);
            }
        }
    }
    printf("2\n");
    int cnt=1;
    for(i=3;i<=M;i+=2) {
        if(!Check(status[i>>5],i & 31)){
            cnt++;
            //printf("%d -> %d\n",cnt,i);
            if(cnt%100==1) printf("%d\n",i);
        }
    }
}

int main()
{
	int i,j,k,l,t;
	//printf("%d\n",sizee);
	sieve();
	return 0;
}

