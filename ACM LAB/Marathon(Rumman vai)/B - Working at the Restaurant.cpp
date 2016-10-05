#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("00Output.txt","w",stdout);
    char comm[20];
    int pile1,pile2,n,m;
    bool frst = true;
    while(scanf("%d",&n)==1){
        if(!n) break;

        if(!frst) printf("\n");
        else frst = false;

        pile1  = 0;
        pile2  = 0;
        while(n--){
            scanf(" %s",comm);
            scanf("%d",&m);
            if(comm[0]=='D'){
                pile2 += m;
                printf("DROP 2 %d\n",m);
            }
            else if(comm[0]=='T'){
                if(m>pile1){
                    if(pile1>0){
                        printf("TAKE 1 %d\n",pile1);
                        m -= pile1;
                        pile1 = 0;
                    }
                    printf("MOVE 2->1 %d\n",pile2);
                    pile1 += pile2;
                    pile2 = 0;
                }
                printf("TAKE 1 %d\n",m);
                pile1 -= m;
            }
        }
    }
    return 0;
}
/**
3
DROP 100
TAKE 50
TAKE 20
3
DROP 3
DROP 5
TAKE 8
4
DROP 3
TAKE 2
DROP 5
TAKE 6
4
DROP 3
TAKE 3
DROP 5
TAKE 5
4
DROP 3
DROP 5
TAKE 3
TAKE 5
0

*/
