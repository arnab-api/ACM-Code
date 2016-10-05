#include<bits/stdc++.h>
using namespace std;
#define M 40100

int ara[2*M],vis[2*M],F[2*M];
struct data{
    int x, y;
};

data poster[M];
set<int>st;
int main()
{
    int t,n,in,i,j,l,L,R,cnt,x,y,uniq;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        st.clear();
        in=0;
        uniq=0;
        cnt=0;
        for(i=0;i<n;i++){
            scanf("%d%d",&x,&y);
            l=st.size();
            st.insert(x);
            if(st.size()>l) ara[uniq++]=x;
            l=st.size();
            st.insert(y);
            if(st.size()>l) ara[uniq++]=y;
            in++;
            poster[in].x=x;
            poster[in].y=y;
        }
        sort(ara,ara+uniq);
        //for(i=0;i<uniq;i++) printf("%d ",ara[i]);
        //printf("\n");
        for(i=1;i<=in;i++){
            L=lower_bound(ara,ara+uniq,poster[i].x)-ara;
            R=lower_bound(ara,ara+uniq,poster[i].y)-ara;
            //printf("%d %d\n",L,R);
            for(j=L;j<=R;j++) F[j]=i;
        }
        for(i=0;i<uniq;i++) if(!vis[F[i]]) {
            cnt++;
            vis[F[i]]=1;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
