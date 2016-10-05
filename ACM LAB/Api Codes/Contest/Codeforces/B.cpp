#include<bits/stdc++.h>
using namespace std;
#define MAX 110

int arr[MAX],cnt;
char str[MAX],ch;

int main()
{
    int n,l;
    while(scanf("%d",&n)==1){
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
        getchar();
        bool flag =true;
        for(int i=0;i<n;i++){
            gets(str);
            l = strlen(str);
            cnt = 0;
            for(int j=0;j<l;j++){
                ch = str[j];
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch =='y') cnt++;
            }
            if(cnt!=arr[i]) flag = false;
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

