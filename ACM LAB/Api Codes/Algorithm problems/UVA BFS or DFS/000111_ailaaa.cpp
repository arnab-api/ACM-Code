/*
     "BISMILLAH HIR RAHMANIR RAHIM"
     MD. MEHADI HASAN
     SHAHJALAL UNIVERSITY OF SCIENCE AND TECHNOLOGY
*/

/// Containers Start
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>
/// C Header Files
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <ctime>
#include <tgmath.h>
#include <cstring>

using namespace std;


#define PI                    acos(-1.0)
#define Pi                    3.141592653589793

#define SET(a)                memset( a, -1,    sizeof a )
#define CLR(a)                memset( a,  0,    sizeof a )
#define MEM(a,val)            memset( a,  val,  sizeof(a) )

#define ll                    long long
#define mod                   1000000007
#define INF                   2147483647


/// I/O Start
#define sf                    scanf
#define pf                    printf

#define sf1(a)                scanf("%d", &a)
#define sf2(a,b)              scanf("%d %d",&a, &b)
#define sf3(a,b,c)            scanf("%d %d %d", &a, &b, &c)
#define sf4(a,b,c, d)         scanf("%d %d %d %d", &a, &b, &c, &d)

#define sf1ll(a)              scanf("%I64d", &a)
#define sf2ll(a,b)            scanf("%I64d %I64d", &a, &b)
#define sf3ll(a,b,c)          scanf("%I64d %I64d %I64d", &a, &b, &c)
#define sf4ll(a,b,c, d)       scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &d)

#define READ                  freopen("input.txt", "r", stdin);
#define WRITE                 freopen("output.txt", "w", stdout);
/// I/O End

#define debug(x) cout << "> " << #x << " = " << x << endl;
#define Max 10000001;

#define loop_tcas(tcas) for(int cas=1; cas<=tcas; cas++)


vector<int>result;
int taken[45]={0};
int prime[45];

int n;

void call(int ck)
{
	if(result.size() == n)              ///PE
	{
		for(int i=0;i<n;i++)
        {
            if(i == 0)
                printf("%d",result[i]);
            else printf(" %d",result[i]);
        }
		//puts("");
		printf("\n");
		return;
	}
	for(int i=2;i<=n;i++)
	{
		if(taken[i]==0 && (prime[ck+i]) == 1)
		{
		    if(result.size() == n-1 && (prime[1+i]) == 1)
            {
                taken[i]=1;

                result.push_back(i);

                call(i);

                taken[i]=0;

                result.pop_back();
            }
            else if(result.size() < n-1)
            {
                taken[i]=1;

                result.push_back(i);

                call(i);

                taken[i]=0;

                result.pop_back();
            }
		}
	}
}

int main()
{
    memset(prime,0,sizeof(prime));

    for(int i=2; i<=41; i++)
    {
        int c = 1;
        for(int j=2; j*j <= i; j++)
        {
            if(i%j == 0)
            {
                c = 0;
                break;
            }
        }
        if(c == 1)
        {
            //cerr << "--> " << i << endl;
            prime[i] = 1;
        }
    }

    int cas = 1;

    //freopen("output1.txt","w",stdout);

	while(scanf("%d",&n) == 1)
    {
        result.push_back(1);
        //if(cas > 1) printf("\n");
        printf("Case %d: \n",cas++);
        call(1);
        result.clear();
        //printf("\n");
    }
}
