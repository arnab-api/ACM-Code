#include<bits/stdc++.h>
using namespace std;
#define MAX 1010

char input[MAX];
int dg_cnt[15];

int main()
{
    int n,l,v,cnt,mod,kase=0;
    bool fst;
    scanf("%d",&n);
    while(n--){
        scanf(" %s",input);
        l = strlen(input);
        printf("Case %d: ",++kase);
        if(l == 1) printf("S\n");
        else{
            cnt = 0;
            mod = 0;
            memset(dg_cnt,0,sizeof(dg_cnt));
            for(int i=0;i<l;i++){
                v = input[i] - '0';
                if(v % 3 == 0) cnt++;
                dg_cnt[v]++;
                mod = (10*mod + v)%3;
            }
            fst = false;
            if(mod !=0) {
                if(dg_cnt[mod] || dg_cnt[mod+3] || dg_cnt[mod+3+3]) fst = true;
            }
            if(cnt & 1) {
                if(!fst) printf("S\n");
                else printf("T\n");
            }
            else {
                if(!fst) printf("T\n");
                else printf("S\n");
            }
        }
    }
    return 0;
}
