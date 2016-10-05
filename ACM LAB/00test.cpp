/*
Once I had a mind
And thoughts was given

But nowadays, in this evil age
All my sense is somewhere else

Once I had a soul
I was one with my god

But now I am abandoned
Banished from these lies

Long my tale's been in the cold
For ages has lain hidden

I know how to bewitch fire
And how to fame flames
I know how to banish worms
And turn snakes away
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime>
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512

using namespace std;

double  a;
int N;
struct pt
{
    double  x;
    double  y;
};

pt p[1<<20];
vector<pt> pts;

double  get_area(vector<pt> v)
{
    v.push_back(v[0]);
    double  area=0;
    for (int i=0; i+1<v.size(); i++)
        area+=v[i].x*v[i+1].y-v[i].y*v[i+1].x;
    if (area<0)
        area=-area;
    return area;
}

pt get_point(pt p1,pt p2,double  r)
{
    p1.x+=(p2.x-p1.x)*r;
    p1.y+=(p2.y-p1.y)*r;
    return p1;
}

double  solve(double  rat)
{
    vector<pt> new_points;
    rat=1.0/rat;
    for (int i=0; i<N; i++)
    {
        new_points.push_back(get_point(pts[i],pts[(i+N-1)%N],rat));
        //new_points.push_back(pts[i]);
        new_points.push_back(get_point(pts[i],pts[(i+1)%N],rat));
    }
    return get_area(new_points);
}

int main()
{
//freopen("beavers.in","r",stdin);
//freopen("beavers.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
//cin.tie(0);

    cin>>a>>N;
    a=1.0-a;

    for (int i=0; i<N; i++)
    {
        cin>>p[i].x>>p[i].y;
        p[i+N]=p[i];
        pts.push_back(p[i]);
    }

    double  starting_area=get_area(pts);
    cout<<"------------------>>> "<<starting_area<<endl;
    cout<<N<<endl;
    long double all_angles=0;
    for (int i=0; i<N; i++)
    {
        vector<pt>v;
        v.push_back(pts[(i+N-1)%N]);
        v.push_back(pts[i]);
        v.push_back(pts[(i+1)%N]);
        pt a = pts[(i+N-1)%N];
        pt b = pts[i];
        pt c = pts[(i+1)%N];
        printf("--->>  (%lf,%lf) (%lf,%lf) (%lf,%lf) ====> %lf\n",a.x,a.y,b.x,b.y,c.x,c.y,get_area(v));
        all_angles+=get_area(v);
    }
    cout<<"--------------->> "<<all_angles<<endl;
//cout<<starting_area<<endl;

    double  remove_area=starting_area*a;
    cout<<"--------------->> "<<starting_area<<"   "<<remove_area<<endl;
    double  rat=remove_area/all_angles;
    cout<<rat<<endl;
    rat=sqrt(rat);
    //cout.precision(12);
    cout<<fixed<<1.0/rat<<endl;

    return 0;
}
