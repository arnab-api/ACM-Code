#include<bits/stdc++.h>
using namespace std;
#define N 105

int taken[N],indegree[N],n;
vector<string>v;
vector<int>order,con[N];

void init()
{
    int i,j;
    v.clear();
    order.clear();
    for(i=0; i<N; i++)
    {
        taken[i]=0;
        indegree[i]=0;
        con[i].clear();
    }
}

int main()
{
    int m,kase=0,i,j,k,a,b;
    string s,s1,s2;
    while(scanf("%d\n",&n)==1)
    {
        init();
        map<string,int>mp;
        int in=1;
        for(i=0; i<n; i++)
        {
            cin>>s;
            v.push_back(s);
            mp[s]=in++;
        }
        map<string,int>:: iterator it;
        /* for(it=mp.begin(); it!=mp.end(); it++){
            s=it->first;
            cout<<s<<"-->"<<mp[s]<<endl;
        }*/
        scanf("%d\n",&m);
        for(i=0; i<m; i++)
        {
            cin>>s1>>s2;
            a=mp[s1];
            b=mp[s2];
            con[a].push_back(b);
            indegree[b]++;
        }
        /*for(i=1;i<=n;i++){
            for(j=1;j<=n;j++) printf("%d",con[i][j]);
            printf("\n");
        }*/
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(indegree[j]==0 && !taken[j])
                {
                    order.push_back(j);
                    taken[j]=1;
                    for(k=0; k<con[j].size(); k++)
                    {
                        indegree[con[j][k]]--;
                    }
                    break;
                }
            }
        }
        printf("Case #%d: Dilbert should drink beverages in this order:",++kase);
        for(i=0; i<order.size(); i++) cout<<" "<<v[order[i]-1];
        printf(".\n\n");
    }
    return 0;
}
