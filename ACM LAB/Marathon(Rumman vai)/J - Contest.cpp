#include<bits/stdc++.h>
using namespace std;
#define MAX 20

int point[MAX];

struct data
{
    int index,score,sub,ac;
    data(){}
    data(int i,int s,int su,int a){
        index = i;
        score = s;
        sub = su;
        ac = a;
    }
    bool operator < (const data & d)const{
        if(score == d.score && ac == d.ac && sub == d.sub) return index < d.index;
        if(score == d.score && ac == d.ac) return sub < d.sub;
        if(score == d.score) return ac < d.ac;
        return score > d.score;
    }
};

data arr[MAX];

int main()
{
    //freopen("00in.txt","r",stdin);
    //freopen("00out.txt","w",stdout);

    int team,prob,kase=0,Sub;
    int tNo;
    char pNo,judge;
    while(scanf("%d%d",&team,&prob)==2){
        if(!team && !prob) break;
        for(int i=0;i<prob;i++) {
            scanf("%d",&point[i]);
        }
        for(int i=1;i<=team;i++) arr[i] = data(i,0,0,0);
        scanf("%d",&Sub);
        while(Sub--){
            scanf("%d",&tNo);
            scanf(" %c",&pNo);
            scanf(" %c",&judge);

            arr[tNo].sub++;
            if(judge=='A'){
                arr[tNo].ac++;
                arr[tNo].score+=point[pNo - 'A'];
            }
        }
        sort(arr+1,arr+team+1);
        printf("%d\n",++kase);
        for(int i=1;i<=team;i++){
            printf("%d %d\n",arr[i].index,arr[i].score);
        }
    }
    return 0;
}
