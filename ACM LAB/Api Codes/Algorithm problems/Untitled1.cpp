#include<stdio.h>
#include<math.h>
#include<set>
#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<utility>
#include<iomanip>
#include<queue>
using namespace std;
#define clr(a) memset(a,0,sizeof(a))

#define PB push_back
#define pi 3.1415926535897932384626433832795
#define oo -100000
vector<int>adj[300];
int val[100][100]= {0};
int visit[100]= {0};
int cow=0,maxi=0;
int src,srcvalue;








int main()
{
    int t,maxi=0;
    char ar[100];
    scanf("%d",&t);
    getchar();
    getchar();
    while(gets(ar) && ar[0])
    {
        int l=strlen(ar);
        l=l-1;
        int b=ar[0]-'A';
        if(b>maxi)
            maxi=b;

        if(ar[l]>='0' && ar[l]<='9')
        {
            int a=0;
            src=b;
            //int b=

            for(int i=0; i<=l; i++)
            {
                if(ar[i]>='0' && ar[i]<='9')
                {
                    a=a*10;
                    a=a+(ar[i]-'0');
              //      printf("%d\n",a);
                }
            }

            //printf("a=%d\n",a);

            //val[b][b]=a;
            srcvalue=a;
        }

        else
        {
            int a=0;

            for(int i=0; i<=l; i++)
            {
                if(ar[i]>='0' && ar[i]<='9')
                {
                    a=a*10;
                    a=a+(ar[i]-'0');
                 //   printf("%d\n",a);
                }
            }

            //val[b]=a;

            for(int i=1; i<=l; i++)
            {
                if(ar[i]>='A' && ar[i]<='Z')
                {
                    int c=ar[i]-'A';
                    // adj[c].push_back(b);
                    val[c][b]=a;
                }
            }


            for(int i=0; i<=maxi; i++)
            {
                for(int j=0; j<=maxi; j++)
                {
             //       printf("%d ",val[i][j]);
                }
               // printf("\n");
            }



            // val[b][c]=a;



        }
    }

    for(int k=0; k<=maxi; k++)
    {

        for(int i=0; i<=maxi; i++)
        {
            for(int j=0; j<=maxi; j++)
            {

           //     printf("%d \n",val[i][k]);
         //       printf("%d \n",val[k][j]);
       //         printf("%d \n",val[i][j]);
     //           printf("___\n");
               // if(val[i][j]>0)
                {
                    if(val[i][k]+val[k][j]>val[i][j])
                    {
                        val[i][j]=val[i][k]+val[k][j];
                        //val[i][j]=val[i][k];
                    }
                }
               //break;


            }
            //break;
        }
        break;
    }
   // printf("++++++++++++++\n");

    for(int i=0; i<=maxi; i++)
    {
        for(int j=0; j<=maxi; j++)
        {
            printf("%d ",val[i][j]);
        }
        printf("\n");
    }




    return 0;
}







