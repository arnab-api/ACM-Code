#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<sstream>
#include<set>
#include<utility>

using namespace std;

#define sz 10010

struct ed
{
    int s, e, cost;
    ed(int a, int b, int c)
    {
        s=a;
        e=b;
        cost=c;
    }
};

int par[sz], n, e, cnt, Mx, j;
vector<ed>vec;

int Comp(ed a, ed b)
{
    return a.cost<b.cost;
}

int Link(int x, int y)
{
    x>y?par[y]=x:par[x]=y;

}

int Find(int r)
{
    if(par[r] == r) return r;
    else return (par[r] = Find(par[r]));
}

int MST()
{
    int i, x, y;
    for(i=0; i<e && vec[i].cost<j; i++)
    {
        x = Find(vec[i].s);
        y = Find(vec[i].e);

        if(x!=y)
        {
            Link(x, y);
            cnt += vec[i].cost;
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    #endif
    int i, a, b, c, total, tcase, cs=1, air;
    scanf("%d", &tcase);

    while(tcase--)
    {
        scanf("%d %d %d", &n, &e, &j);
        for(i=0; i<=n; i++) par[i] = i;

        vec.clear();
        for(i=0; i<e; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            vec.push_back(ed(a, b, c));
        }
        sort(vec.begin(), vec.end(), Comp);
        cnt = air = 0;
        MST();
        for(i=1; i<=n; i++) if(par[i] == i) air++;

        printf("Case #%d: %d %d\n", cs++, cnt+(air*j), air);
    }


    return 0;
}
