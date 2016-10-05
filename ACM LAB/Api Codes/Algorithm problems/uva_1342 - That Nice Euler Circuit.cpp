//#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<climits>
#include<cstring>
#include<cstdlib>

#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>

#include<vector>
#include<map>
#include<string>
#include<queue>
#include<set>
#include<iterator>
#include<numeric>
#include<stack>
#include<list>
using namespace std;
#define pi acos(-1)
#define M 333
#define oo 1<<30

struct point{
    double x,y;
    point(){}
    point(double a,double b){
        x=a; y=b;
    }

};

point ara[M];
int n;

set<pair<double,double> >st;
set<pair<double,double> >:: iterator it;

void get_intersection(point A,point B,point C,point D)
{
    /// line 1 equation
    double a1 = A.y - B.y;
    double b1 =  - A.x + B.x;
    double c1 = A.y*(A.x - B.x) - A.x*(A.y - B.y);

    double a2 = C.y - D.y;
    double b2 =  - C.x + D.x;
    double c2 = C.y*(C.x - D.x) - C.x*(C.y - D.y);

    if(abs(a1*b2 - a2*b1)<.000001) return;

    double x = (b1*c2 - b2*c1)/(a1*b2 - a2*b1);
    double y = (c1*a2 - c2*a1)/(a1*b2 - a2*b1);

    bool flag = true;

    if(x > max(A.x,B.x) || x < min(A.x,B.x)){flag = false; /*printf(">>>1\n");*/}
    if(y > max(A.y,B.y) || y < min(A.y,B.y)){flag = false; /*printf(">>>2\n");*/}
    if(x > max(C.x,D.x) || x < min(C.x,D.x)){flag = false; /*printf(">>>3\n");*/}
    if(y > max(C.y,D.y) || y < min(C.y,D.y)){flag = false; /*printf(">>>4\n");*/}

    /*printf("Ax = %lf , Ay = %lf  &&  Bx = %lf , By = %lf\n",A.x,A.y,B.x,B.y);
    printf("Cx = %lf , Cy = %lf  &&  Dx = %lf , Dy = %lf\n",C.x,C.y,D.x,D.y);
    printf("x = %lf && y = %lf ===> ",x,y);
    if(flag) printf("true\n");
    else printf("false\n");*/

    if(flag) st.insert(make_pair(x,y));
}

int main()
{
	int i,j,k,l,t,ans,kase=0;
	while(scanf("%d",&n)==1){
        if(n==0) break;
        st.clear();
        for(i=0;i<n;i++){
            scanf("%lf%lf",&ara[i].x,&ara[i].y);
            st.insert(make_pair(ara[i].x,ara[i].y));
            if(i>1) for(j=0;j<n-1;j++) get_intersection(ara[j],ara[j+1],ara[i-1],ara[i]);
        }
        /*for(it = st.begin();it!=st.end();it++){
            cout<<it->first<<" && "<<it->second<<endl;
        }*/
        if(st.size() == n) ans=2;
        else ans = st.size() - (n-1) + 2;
        //cerr<<"==============>";
        printf("Case %d: There are %d pieces.\n",++kase,ans);
	}
	return 0;
}

