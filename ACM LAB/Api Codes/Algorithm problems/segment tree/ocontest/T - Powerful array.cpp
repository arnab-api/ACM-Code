#include<bits/stdc++.h>
using namespace std;
#define sizee 200100
#define M 1000100
#define lli long long int
int ara[sizee],sq,F[M];
lli val,out[sizee];

struct query{
    int l,r,index;
    bool operator < (const query & p)const{
        if((l/sq)==(p.l/sq)) return (r/sq) < (p.r/sq);
        return (l/sq) < (p.l/sq);
    }
};

query Q[sizee];

inline void Add(int pos)
{
    val+=(lli)((F[ara[pos]]<<1)+1)*(lli)ara[pos];
    F[ara[pos]]++;
}

inline void Remove(int pos)
{
    val-=(lli)((F[ara[pos]]<<1)-1)*(lli)ara[pos];
    F[ara[pos]]--;
}

int main()
{
    int i,n,q,x,y;
    while(scanf("%d %d",&n,&q)==2){
        memset(F,0,sizeof(F));
        sq=(int)sqrt(n);
        for(i=1;i<=n;i++) scanf("%d",&ara[i]);
        for(i=1;i<=q;i++){
            scanf("%d %d",&x,&y);
            Q[i].l=x;
            Q[i].r=y;
            Q[i].index=i;
        }
        sort(Q+1,Q+q+1);
        int lp=1,rp=0;
        val=0;
        for(i=1;i<=q;i++){
            while(lp<Q[i].l){
                Remove(lp);
                lp++;
            }
            while(lp>Q[i].l){
                lp--;
                Add(lp);
            }
            while(rp<Q[i].r){
                rp++;
                Add(rp);
            }
            while(rp>Q[i].r){
                Remove(rp);
                rp--;
            }
            out[Q[i].index]=val;
        }
        for(i=1;i<=q;i++) printf("%I64d\n",out[i]);
    }
    return 0;
}
