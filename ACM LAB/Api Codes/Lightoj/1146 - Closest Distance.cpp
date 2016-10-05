#include<bits/stdc++.h>
using namespace std;

struct Point
{
    double x;
    double y;
    Point(){}
    Point(double xx,double yy){
        x = xx;
        y = yy;
    }
};

// Given three colinear Points p, q, r, the function checks if
// Point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    // See http://www.geeksforgeeks.org/orientation-3-ordered-Points/
    // for details of below formula.
    double val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (abs(val-0.0)<.000001) return 0;  // colinear

    return (val > 0)? 1: 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4) { printf("1"); return true;}

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) { printf("2"); return true;}
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) { printf("3"); return true;}

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) { printf("4"); return true;}

     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) { printf("5"); return true;}

    return false; // Doesn't fall in any of the above cases
}

Point getRatioInterDividant(Point A,Point B,double p,double q)
{
    double x = (p*B.x + q*A.x)/(p+q);
    double y = (p*B.y + q*A.y)/(p+q);
    return Point(x,y);
}

Point getRatioOuterDividant(Point A,Point B,double p,double q)
{
    double x = (p*B.x - q*A.x)/(p-q);
    double y = (p*B.y - q*A.y)/(p-q);
    return Point(x,y);
}

double getDistance(Point A,Point B)
{
    return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}

double ternarySearch(Point A,Point B,Point C,Point D)
{
    Point hi = B;
    Point lo = A;
    Point m1,m2;
    double f1,f2;
    int cnt=200;
    double ans = -1.0;
    //printf("(%lf %lf)\n",A.x,A.y);
    //printf("(%lf %lf)\n",B.x,B.y);
    //printf("(%lf %lf)\n",C.x,C.y);
    while(cnt--){
        m1 = getRatioInterDividant(lo,hi,1.0,2.0);
        m2 = getRatioInterDividant(lo,hi,2.0,1.0);

        //printf("(%lf ---> %lf)\n",m1.x,m1.y);
        //printf("(%lf ---> %lf)\n",m2.x,m2.y);
        f1 = getDistance(m1,getRatioInterDividant(C,D,getDistance(A,m1),getDistance(B,m1)));
        f2 = getDistance(m2,getRatioInterDividant(C,D,getDistance(A,m2),getDistance(B,m2)));

        //cout<<f1<<"============> "<<f2<<endl;

        if(f1<f2) hi = m2;
        else lo = m1;
    }
    return (f1+f2)/2;
}

int main()
{
    //freopen("0out.txt","w",stdout);
    int t,kase=0;
    double a,b,ans;
    Point p1,p2,q1,q2;
    scanf("%d",&t);
    while(t--){
        scanf("%lf%lf",&a,&b); p1 = Point(a,b);
        scanf("%lf%lf",&a,&b); q1 = Point(a,b);
        scanf("%lf%lf",&a,&b); p2 = Point(a,b);
        scanf("%lf%lf",&a,&b); q2 = Point(a,b);
        //cout<<p1.x<<"  "<<p1.y<<endl;
        //cout<<p2.x<<"  "<<p2.y<<endl;
        //cout<<q1.x<<"  "<<q1.y<<endl;
        //cout<<q2.x<<"  "<<q2.y<<endl;
        ans = ternarySearch(p1,q1,p2,q2);
        //cerr<<"---------------------> ";
        printf("Case %d: %lf\n",++kase,ans);
    }
    return 0;
}

/**
3
0 0 5 0 5 5 5 0
0 0 5 5 10 10 6 6
0 0 5 0 10 1 1 1
54 96 71 52 52 52 74 61
*/










