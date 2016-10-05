#include<bits/stdc++.h>
using namespace std;
#define MAX 50050

char str[MAX];
vector<int>v[30];
queue<int>q;
int vis[30];

void init()
{
    for(int i=0;i<26;i++){
        v[i].clear();
        vis[i] = 0;
    }
    while(!q.empty()) q.pop();
}

int main()
{
    //freopen("00Out.txt","w",stdout);
    int l,i,j,lo,hi;
    while(scanf(" %s",str)==1){
        l = strlen(str);
        init();
        for(i=0;i<l;i++){
            v[str[i]-'A'].push_back(i);
        }
        int found = -1;
        for(i=0;i<l;i++){
            bool valid = true;
            lo = i;
            hi = i + 26 - 1;
            if(hi>l-1) continue;
            for(j=0;j<26;j++){
                while(!v[j].empty() && v[j][0]<lo) v[j].erase(v[j].begin());
                if(v[j].size()<=1) continue;
                if((v[j][0]>=lo && v[j][0]<=hi) && (v[j][1]>=lo && v[j][1]<=hi)){
                    valid = false;
                    break;
                }
            }
            if(valid){
                found = i;
                break;
            }
        }
        if(found==-1) printf("-1\n");
        else{
            lo = found;
            hi = lo + 26 -1;
            for(i=lo;i<=hi;i++) vis[str[i]-'A']=1;
            for(i=0;i<26;i++) if(!vis[i]) q.push(i);

            for(i=0;i<lo;i++) {
                if(str[i]=='?') printf("A");
                else printf("%c",str[i]);
            }
            for(i=lo;i<=hi;i++){
                if(str[i]=='?'){
                    printf("%c",q.front()+'A');
                    q.pop();
                }
                else printf("%c",str[i]);
            }
            for(i=hi+1;i<l;i++) {
                if(str[i]=='?') printf("B");
                else printf("%c",str[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
/**
ABC??FGHIJK???OPQR?TUVWXY?
WELCOMETOCODEFORCESROUNDTHREEHUNDREDANDSEVENTYTWO
??????????????????????????
AABCDEFGHIJKLMNOPQRSTUVW??M
AABACEDFGHIJKLNMOPQRSTUVWXYZBBB
*/
