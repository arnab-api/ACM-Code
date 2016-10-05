#include<bits/stdc++.h>
using namespace std;
#define M 510

struct Pair{
    int man,woman;
    Pair(int a,int b){
        man=a; woman=b;
    }
};
vector<Pair>SM;
vector<int>men[M],women[M];
int status[M][M],takenm[M],takenw[M];
//taken[i]=1 means ith man is married;
//status[m][n]==1 means mth man proposed to nth woman;
//status[m][n]==0 means inactive;
//status[m][n]==2 means proposal accepted :D ;

void init()
{
    SM.clear();
    for(int i=0;i<M;i++){
        men[i].clear();
        women[i].clear();
        takenm[i]=0;
        takenw[i]=0;
        for(int j=0;j<M;j++) status[i][j]=0;
    }
}

bool con(Pair a,Pair b)
{
    return a.man<b.man;
}

int main()
{
    int t,n,i,j,k,in,s,x,y;
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d",&n);
        for(i=0;i<n;i++){
            for(j=0;j<=n;j++){
                scanf("%d",&in);
                if(j==0) s=in;
                else women[s].push_back(in);
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<=n;j++){
                scanf("%d",&in);
                if(j==0) s=in;
                else men[s].push_back(in);
            }
        }
        for(i=1;i<=n;i++){
            /*printf("===>men\n");
            for(int i=1;i<=n;i++){
                printf("%d==>",i);
                for(int j=0;j<men[i].size();j++){
                    printf(" %d",men[i][j]);
                }
                if(takenm[i]==1) printf(":D");
                printf("\n");
            }*/
            for(j=1;j<=n;j++) {
                if(takenm[j]==1) continue;
                status[j][men[j][0]]=1;
            }
            for(j=1;j<=n;j++){
                if(takenw[j]==1) continue;
                for(k=0;k<women[j].size();k++){
                    if(status[women[j][k]][j]==1){
                        takenm[women[j][k]]=1;
                        takenw[j]=1;
                        status[women[j][k]][j]==2;
                        SM.push_back(Pair(women[j][k],j));
                        //printf("%d woman married to %d man\n",j,women[j][k]);
                        for(x=1;x<=n;x++){
                            if(takenm[x]==1) continue;
                            for(y=0;y<men[x].size();y++){
                                if(men[x][y]==j){
                                    men[x].erase(men[x].begin()+y);
                                    break;
                                }
                            }
                        }
                        break;
                    }
                }
            }
        }
        sort(SM.begin(),SM.end(),con);
        for(i=0;i<SM.size();i++) printf("%d %d\n",SM[i].man,SM[i].woman);
    }
    return 0;
}
