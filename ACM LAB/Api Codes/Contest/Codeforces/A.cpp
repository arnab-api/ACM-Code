#include<bits/stdc++.h>
using namespace std;

int main()
{
    int f,hh,mm;
    while(scanf("%d",&f)==1){
        scanf("%d",&hh);
        getchar();
        scanf("%d",&mm);
        if(mm>59) mm%=10;
        if(f == 12){
            if(hh>12) hh%=10;
            if (hh == 0) {
                hh = 10;
            }
        }
        if(f == 24){
            if(hh > 23) hh%=10;
        }
        //cerr<<"--------->> ";
        printf("%02d:%02d\n",hh,mm);
    }
    return 0;
}
