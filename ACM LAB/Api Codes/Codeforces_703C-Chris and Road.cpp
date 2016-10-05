#include<bits/stdc++.h>
using namespace std;
#define M 10010

struct point
{
    double x,y;
    point(){}
    point(double a,double b){
        x = a;
        y = b;
    }
    bool operator < (const point & p)const{
        if(x == p.x) return y < p.y;
        return x > p.x;
    }
};

struct point2
{
    double x,y;
    point2(){}
    point2(double a,double b){
        x = a;
        y = b;
    }
    bool operator < (const point2 & p)const{
        if(y == p.y) return x > p.x;
        return y > p.y;
    }
};

priority_queue<point> pq;
priority_queue<point2> pq2;

int main()
{
    double n,w,v,u,a,b,currH,ans;
    while(scanf("%lf%lf%lf%lf",&n,&w,&v,&u)==4){
        while(!pq.empty()) pq.pop();
        while(!pq2.empty()) pq2.pop();
        bool flag = true;
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&a,&b);
            if(a<0) flag = false;
            pq.push(point(a,b));
            pq2.push(point2(a,b));
        }

        currH = 0;
        while(!pq.empty() && flag){
            //printf("-----------------> %lf %lf\n",pq.top().x,pq.top().y);
            if(pq.top().y<=currH) pq.pop();
            else{
                point p = pq.top(); pq.pop();
                if((p.x - 0)/v < (p.y - 0)/u) flag = false;
                //currH = p.y;
            }
        }
        if(flag) {
            ans = w/u;
            //printf("flag true\n");
        }
        else{
            ans = 0;
            currH = 0;
            point2 prev = point2(0,0);
            while(!pq2.empty()){
                if(pq2.top().x - v*ans < 0){
                    pq2.pop();
                }
                else{
                    if((pq2.top().x - prev.x)/v >= (pq2.top().y - prev.y)/u) {
                        ans += (pq2.top().x - prev.x)/v;
                        prev = pq2.top();
                    }
                    else{
                        ans += (pq2.top().x - prev.x)/v;
                        prev.y = prev.y + u*((pq2.top().x - prev.x)/v);
                        prev.x = pq2.top().x;
                    }
                    //printf("%lf %lf ======> %lf %lf >>> %lf\n",pq2.top().x,pq2.top().y,prev.x,prev.y,ans);
                    pq2.pop();
                }
            }
            ans += (w - prev.y)/u;
        }
        //cerr<<"--------------------->";
        printf("%.10lf\n",ans);
    }
    return 0;
}
