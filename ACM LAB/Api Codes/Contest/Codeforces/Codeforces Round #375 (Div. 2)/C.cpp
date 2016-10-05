#include<bits/stdc++.h>
using namespace std;
#define MAX 2000+10


int arr[MAX],cnt[MAX],perform[MAX];

struct min_data
{
    int band,song;
    min_data(){}
    min_data(int b,int s){
        band = b;
        song = s;
    }
    bool operator < (const min_data & d) const{
        if(song == d.song) return band < d.band;
        return song > d.song;
    }
};

struct max_data
{
    int band,song;
    max_data(){}
    max_data(int b,int s){
        band = b;
        song = s;
    }
    bool operator < (const max_data & d) const{
        return song < d.song;
    }
};
vector<int>api,perform[MAX];

int main()
{
    int n,m,i,j,chng;
    while(scanf("%d%d",&n,&m)==2){
        memset(cnt,0,sizeof(cnt));
        chng = 0;
        for(i=1;i<=n;i++){
            scanf("%d",&arr[i]);
            if(arr[i]<=m) cnt[arr[i]]++;
        }
        priority_queue<min_data>min_pq;
        for(i=1;i<=n;i++) min_pq.push(min_data(i,cnt[i]));
        for(i=1;i<=n;i++){
            if(arr[i]>m){
                min_data d = min_pq.top(); min_pq.pop();
                arr[i] = d.band;
                cnt[d.band]++;
                d.song++;
                min_pq.push(d);
                chng++;
            }
        }
        set<min_data>st;
        set<min_data>:: iterator it1,it2;
        for(i=1;i<=n;i++) {
            st.insert(min_data(i,cnt[i]));
            max_pq.push(max_data(i,cnt[i]));
        }
        int avg = 0;
        for(i=1;i<=m;i++) avg+= i*cnt[i];
        avg = avg/n;
        for(i=1;i<=n;i++){

        }
    }
    return 0;
}
