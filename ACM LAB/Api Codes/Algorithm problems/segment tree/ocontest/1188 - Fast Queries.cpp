#include<bits/stdc++.h>
using namespace std;
#define M 100100

int ara[M],cnt[M],val,sq,out[M];
struct Query{
    int L,R,index;
    bool operator < (const Query & p)const{
        if((L/sq) == (p.L/sq)) return R < p.R;
        return (L/sq) < (p.L/sq);
    }
};
Query Q[M];

void Add(int pos)
{
    //printf("(+)-->%d %d\n",pos,ara[pos]);
    if(cnt[ara[pos]]==0) val++;
    cnt[ara[pos]]++;
    //printf("(+)-->%d %d\n",pos,ara[pos]);
}

void Remove(int pos)
{
    //printf("(-)-->%d %d\n",pos,ara[pos]);
    cnt[ara[pos]]--;
    if(cnt[ara[pos]]==0) val--;
    //printf("(-)-->%d %d\n",pos,ara[pos]);
}

int main()
{
    int t,n,q,i,j,x,y,kase=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        sq=1000;
//        sq=(int)sqrt(q);
//        if(sq*sq!=q) sq++;
        memset(cnt,0,sizeof(cnt));
        for(i=1;i<=n;i++) scanf("%d",&ara[i]);
        for(i=1;i<=q;i++){
            scanf("%d%d",&x,&y);
            Q[i].L=x; Q[i].R=y;
            Q[i].index=i;
        }
        sort(Q,Q+q+1);
        //for(i=1;i<=q;i++) printf("---> %d %d %d\n",Q[i].L,Q[i].R,Q[i].index);
        int cL=1,cR=0;
        val=0;
        for(i=1;i<=q;i++){
            x=val;
            while(cL<Q[i].L){
                Remove(cL);
                cL++;
            }
            while(cL>Q[i].L){
                cL--;
                Add(cL);
            }
            while(cR>Q[i].R){
                Remove(cR);
                cR--;
            }
            while(cR<Q[i].R){
                cR++;
                Add(cR);
            }
            out[Q[i].index]=val;
            //printf("%d %d %d %d %d %d %d\n",Q[i].L,cL,Q[i].R,cR,Q[i].index,val,x);
        }
        printf("Case %d:\n",++kase);
        for(i=1;i<=q;i++) printf("%d\n",out[i]);
    }
    return 0;
}
/*
1

8 6
2 2 2 2 3 2 2 4
6 8
1 8
3 4
2 7
1 4
6 8
*/

