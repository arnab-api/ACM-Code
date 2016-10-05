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
        if(x == p.x) return y > p.y;
        return x < p.x;
    }
};

priority_queue<point> pq;
point arr[M],rightMost;

int main()
{
    double n,w,v,u,a,b,currH,ans;
    while(scanf("%lf%lf%lf%lf",&n,&w,&v,&u)==4){
        rightMost = point(0,0);
        while(!pq.empty()) pq.pop();
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&a,&b);
            arr[i] = point(a,b);
            pq.push(point(a,b));
            if(a>rightMost.x){
                rightMost = point(a,b);
            }
            else if(a == rightMost.x && b < rightMost.y){
                rightMost = point(a,b);
            }
        }

        bool flag = true;
        currH = 0;
        while(!pq.empty() && flag){
            if(pq.top().y<=currH) pq.pop();
            else{
                point p = pq.top(); pq.pop();
                if((p.x - 0)/v < (p.y - 0)/u) flag = false;
                currH = p.y;
            }
        }
        if(flag) ans = w/u;
        else{
            ans = 0;
            printf("RightMost ====> %lf %lf\n",rightMost.x,rightMost.y);
            double tt = rightMost.x/v;
            if(rightMost.x/v < rightMost.y/u) ans = tt + (w - tt*u)/u;
            else ans = (w - rightMost.y)/u + tt;
        }
        //cerr<<"--------------------->";
        printf("%.10lf\n",ans);
    }
    return 0;
}
