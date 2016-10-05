#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>

using namespace std;

#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name));
#define EPS 10e-9
#define ll long long
#define ull long long unsigned
#define SF scanf
#define PF printf
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<28)
#define mp make_pair
#define fs first
#define sc second
#define rep(var,s,n,it) for(var=(s);var<(n);(var)+=it)
#define rev(var,s,n,it) for(var=(n-1);var>(s-1);(var)-=it)
#define Read freopen("in.txt","r",stdin)
#define Write freopen("outR.txt","w",stdout)
#define __ std::ios_base::sync_with_stdio (false)

ll MulModL(ll B,ll P,ll M) {    ll R=0; while(P>0)      { if((P&1ll)==1) { R=(R+B); if(R>=M) R-=M; } P>>=1ll; B=(B+B); if(B>=M) B-=M; } return R; }

ll MulModD(ll B, ll P,ll M) {   ll I=((long double)B*(long double)P/(long double)M);    ll R=B*P-M*I; R=(R%M+M)%M;  return R; }

ll BigMod(ll B,ll P,ll M) {     ll R=1; while(P>0)      { if(P%2==1) { R=(R*B)%M; } P/=2; B=(B*B)%M; } return R; } /// (B^P)%M
ll BigModL(ll B,ll P,ll M) {     ll R=1; while(P>0)      { if(P%2==1) { R=MulModL(R,B,M); } P/=2; B=MulModL(B,B,M); } return R; } /// (B^P)%M

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}

#define SZ1 10000010
#define SZ2 5771450

char sieve[(SZ1>>4)+7];
int prime[SZ2];
int totP;

//void bit_sieve()
//{
//    int i,j,k,r;
//    prime[0]=2;
//    k=1;
//    totP=k;
//    int lim=(int)sqrt(SZ1)+1;
//    for(i=3; i<SZ1; i+=2)
//    {
//        if(!(sieve[i>>4]&(1<<((i>>1)&7))))
//        {
//            prime[k++]=i;
//            if(i<lim)
//            {
//                r=i<<1;
//                for(j=i*i; j<SZ1; j+=r)
//                {
//                    sieve[j>>4]|=(1<<((j>>1)&7));
//                }
//            }
//        }
//    }
//    totP=k;
////    deb(k);
//    return;
//}

ll status[SZ2],p_cnt=0;
bool Check(ll N,ll pos)
{
    return (bool)( N & 1<<pos);
}
ll Set(ll N,ll pos)
{
    return N=N | (1<<pos);
}

void bit_sieve()
{
    ll n,i,j;
    for(i=2*2; i<=SZ1; i+=2) status[i>>5]=Set(status[i>>5],i & 31);

    for(i=3; i*i<=SZ1; i+=2)
    {
        if(!Check(status[i>>5],i&31))
        {
            for(j=i*i; j<=SZ1; j+= 2*i)
            {
                status[j>>5]=Set(status[j>>5],j & 31);
            }
        }
    }
    //printf("2\n");
    p_cnt=0;
    prime[p_cnt++] = 2;
    for(i=3; i<=SZ1; i+=2)
    {
        if(!Check(status[i>>5],i & 31))
        {
            prime[p_cnt++] = i;
            //printf("%d -> %d\n",cnt,i);
        }
    }
    cout<<p_cnt<<endl;
    totP = p_cnt;
}

/**
1 means either n<=1
2 means prime
3 means composite square number
4 means composite non square number
*/

ll miller_rabin(ll n,ll it)
{
    cout<<"-----> ";
    deb(n);
    if(n<=1) return 1;
    else if(n==2) return 2;
    else
    {
        ll k=sqrt(n);
        for(ll i=max(0ll,k-2);i<=k+2;i++)
        {
            if(i*i==n) return 3;
        }
        if(n%2==0) return 4;
        else
        {
            ll s=0,d=n-1,a;
            while(d%2==0)
            {
                s++;
                d/=2;
            }
            bool f;
            ll m1,m2;
            for(ll i=0;i<it;i++)
            {
                a=prime[i];
                f=true;
                for(ll j=0;j<s;j++)
                {
                    m1=(BigModL(a,d,n)-1+n)%n;
                    m2=(BigModL(a,(1ll<<j)*d,n)+1)%n;
                    cout<<m1<<endl;
                    cout<<m2<<endl;
                    if(m1==0||m2==0)
                    {
                        f=false;
                        break;
                    }
                }
                if(f) return 4;
            }
        }
    }
    return 2;
}

ll bigmod(ll base,ll power,ll modulo)
{
    ll ret = 1ll;
    while(power>0)
    {
        if(power%2ll==1) ret = (ret*base)%modulo;
        base = (base*base)%modulo;
        power/=2;
    }
    return (ret+modulo)%modulo;
}

ll miller_rabin1(ll N,ll it)
{
    cout<<N<<endl;
    if(N<2) return 1;
    if(N==2) return 2;
    ll root = sqrt(N);
    ll st = max(0ll,root - 2) , nd = root+2;
    for(ll i = st ; i<=nd ; i++) if(i*i == N) return 3;
    ll s = 0 , d = N-1 , a , m1, m2;
    while(d%2ll==0)   /// d obviously even
    {
        d>>=1;
        s++;
    }
    bool flag = true;
    for(ll i=0; i<it; i++)
    {
        a = prime[i];
        flag = true;
        for(ll j = 0; j<s; j++)
        {
            m1 = (BigModL(a,d,N) - 1 + N) % N;
            //m1 = (bigmod(a,d,N) - 1 + N) % N;
            m2 = (BigModL(a,(1ll<<j)*d,N) + 1) % N;
            //m2 = (bigmod(a,(1ll<<j)*d,N) + 1) % N;
            cout<<m1<<endl;
            cout<<m2<<endl;
            if(m1 == 0 || m2 == 0)
            {
                cout<<"************************\n";
                flag = false;
                break;
            }
        }
        if(flag)
            {
                cerr<<"====>";
                return 4;
            }
    }
    return 2;
}

ll get_div(ll n)
{
    ll p=2,r=1,c;
    int i;
    for(i=0;i<totP && prime[i]*prime[i]<=n;i++)
    {
        p=prime[i];
        if(n%p==0)
        {
            c=1;
            while(n%p==0)
            {
                n/=p;
                c++;
            }
            r*=c;
        }
    }
    if(n>1)
    {
        if(n<=prime[totP-1]) r*=2ll;
        else r*=miller_rabin(n,12);
    }
    return r;
}

int main(void)
{
    bit_sieve();
    ll n;
    while(cin>>n)
    {
        cout<<"------------------------------------------->"<<miller_rabin(n,12)<<endl;
        cout<<"===========================================>"<<miller_rabin1(n,12)<<endl;
        cout<<get_div(n)<<"\n";
    }
    return 0;
}













