#include<bits/stdc++.h>
using namespace std;
#define M 100100

int ara[M],F[M],cnt[M],out[M],sq,mx;

struct Query{
    int l,r,index;
    bool operator < (const Query & p) const{
        if((l/sq) == (p.l/sq)) return (r/sq) < (p.r/sq);
        return (l/sq) < (p.l/sq);
    }
};

Query Q[50100];

void Add(int pos)
{
    F[ara[pos]]++;
    if(F[ara[pos]]>mx) mx=F[ara[pos]];
    cnt[F[ara[pos]]]++;
}

void Remove(int pos)
{
    cnt[F[ara[pos]]]--;
    if(F[ara[pos]]==mx && cnt[F[ara[pos]]]==0) mx--;
    F[ara[pos]]--;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int t,n,c,q,kase=0,i;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&c,&q);
        for(i=1;i<=n;i++) scanf("%d",&ara[i]);
        sq=(int)sqrt(n);
        if(sq*sq<n) sq++;
        for(i=1;i<=q;i++){
            scanf("%d%d",&Q[i].l,&Q[i].r);
            Q[i].index=i;
        }
        memset(F,0,sizeof(F));
        memset(cnt,0,sizeof(cnt));
        sort(Q+1,Q+q+1);
        int lp=1, rp=0;
        mx=0;
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
            out[Q[i].index]=mx;
        }
        printf("Case %d:\n",++kase);
        cerr<<"hiiiiiii"<<endl;
        for(i=1;i<=q;i++) printf("%d\n",out[i]);
    }
    return 0;
}
