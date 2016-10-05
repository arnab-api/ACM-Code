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
#define M 300
#define oo 1<<30

int path[M],n;
int edge[M][M];
bool flag;

void init()
{
    flag = false;
    memset(path,-1,sizeof(path));
    memset(edge,0,sizeof(edge));
}

bool isValid(int node,int pos)
{
    if(!edge[path[pos-1]][node]) return false;
    for(int i=0; i<pos; i++) if(path[i]==node) return false;
    return true;
}

bool find_hamiltonian_cycle(int pos)
{
    if(pos==n)
    {
        if(edge[path[pos-1]][path[0]]) return true;
        return false;
    }
    for(int i=2; i<=n; i++)
    {
        if(isValid(i,pos))
        {
            path[pos]=i;
            if(find_hamiltonian_cycle(pos+1)) return true;
            path[pos]=-1;
        }
    }
    return false;
}

void hamilton()
{
    path[0]=1;
    flag = find_hamiltonian_cycle(1);
    if(flag)
    {
        for(int i=0; i<n; i++) printf("%d ",path[i]);
        printf("1\n");
    }
    else printf("N\n");
}

int main()
{
    int i,j,k,l,t,a,b;
    char ch[10];
    while(scanf("%d",&n)==1)
    {
        init();
        while(1)
        {
            scanf(" %s",&ch);
            if(ch[0]=='%') break;
            l=strlen(ch);
            a=0;
            for(i=0; i<l; i++) a = (a*10)+(ch[i]-'0');
            scanf("%d",&b);
            //printf("--------> %d %d\n",a,b);
            edge[a][b]=1;
            edge[b][a]=1;
        }
        hamilton();
    }
    return 0;
}

