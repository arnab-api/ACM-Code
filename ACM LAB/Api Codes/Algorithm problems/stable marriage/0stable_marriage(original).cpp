#include<bits/stdc++.h>
using namespace std;

#define MAX 505

int men_rank_list[MAX][MAX];
int women_rank_list[MAX][MAX];
int women_preference[MAX][MAX];
int men_engaged_to[MAX];
int women_engaged_to[MAX];
int next_to_be_asked[MAX];


void Stable_Marriage(int n)
{
    int i,j,a,b,d,women_index_number;
    stack<int>men_free_list;
    for(i=1;i<=n;i++)
    {
        men_free_list.push(i);
        women_engaged_to[i] = 0;
        next_to_be_asked[i] = 1;
    }
    while(!men_free_list.empty())
    {
        a = men_free_list.top();
        women_index_number = next_to_be_asked[a];
        next_to_be_asked[a] += 1;

        b = men_rank_list[a][women_index_number];
        if(women_engaged_to[b] == 0)
        {
            women_engaged_to[b] = a;
            men_engaged_to[a] = b;
            men_free_list.pop();
            continue;
        }
        else
        {
            d = women_engaged_to[b];
            if(women_preference[b][a] < women_preference[b][d])
            {
                men_free_list.pop();
                women_engaged_to[b] = a;
                men_engaged_to[a] = b;
                men_free_list.push(d);
            }
        }
    }
    for(i=1;i<=n;i++) cout << i << " " << men_engaged_to[i] << endl;
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,i,j,a,b;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);
            for(j=1;j<=n;j++)
            {
                scanf("%d",&women_rank_list[i][j]);
                women_preference[a][women_rank_list[i][j]] = j;
            }
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);
            for(j=1;j<=n;j++)
            {
                scanf("%d",&men_rank_list[i][j]);
            }
        }
        Stable_Marriage(n);
    }
    return 0;
}
