#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define M 10000101
#define sizee (int)(M/5)

lli status[sizee+5],prime[6000000],p_cnt=0;
bool Check(lli N,lli pos)
{
    return (bool)( N & 1<<pos);
}
lli Set(lli N,lli pos)
{
    return N=N | (1<<pos);
}

void sieve()
{
    lli n,i,j;
    for(i=2*2; i<=M; i+=2) status[i>>5]=Set(status[i>>5],i & 31);

    for(i=3; i*i<=M; i+=2)
    {
        if(!Check(status[i>>5],i&31))
        {
            for(j=i*i; j<=M; j+= 2*i)
            {
                status[j>>5]=Set(status[j>>5],j & 31);
            }
        }
    }
    //printf("2\n");
    p_cnt=0;
    prime[p_cnt++] = 2;
    for(i=3; i<=M; i+=2)
    {
        if(!Check(status[i>>5],i & 31))
        {
            prime[p_cnt++] = i;
            //printf("%d -> %d\n",cnt,i);
        }
    }
    //cout<<p_cnt<<endl;
}

lli mul_mod(lli base,lli mul,lli modulo)
{
    lli ret = 0;
    while(mul>0)
    {
        if(mul%2ll==1) ret = (ret+base)%modulo;
        base = (base+base)%modulo;
        mul/=2;
    }
    return (ret+modulo)%modulo;
}

lli bigmod(lli base,lli power,lli modulo)
{
    lli ret = 1;
    while(power>0)
    {
        if(power%2ll==1) ret = mul_mod(ret,base,modulo);
        base = mul_mod(base,base,modulo);
        power/=2;
    }
    return (ret+modulo)%modulo;
}

/// N<2 => 1;
/// prime => 2;
/// composite square => 3;
/// composite non square => 4;
lli miller_rabin(lli N,lli it)
{
    //cout<<N<<endl;
    if(N<2) return 1;
    if(N==2) return 2;
    lli root = sqrt(N);
    lli st = max(0ll,root - 2) , nd = root+2;
    for(lli i = st ; i<=nd ; i++) if(i*i == N) return 3;
    lli s = 0 , d = N-1 , a , m1, m2;
    while(d%2ll==0)   /// d obviously even
    {
        d>>=1;
        s++;
    }
    bool flag = true;
    for(lli i=0; i<it; i++)
    {
        a = prime[i];
        flag = true;
        for(lli j = 0; j<s; j++)
        {
            m1 = (bigmod(a,d,N) - 1 + N) % N;
            m2 = (bigmod(a,(1ll<<j)*d,N) + 1) % N;
            if(m1 == 0 || m2 == 0)
            {
                flag = false;
                break;
            }
        }
        if(flag) return 4;
    }
    return 2;
}

lli get_div(lli N)
{
    lli ret = 1;
    for(lli i=0; i<p_cnt && prime[i]*prime[i]<=N ; i++)
    {
        if(N%prime[i]==0)
        {
            lli s = 0;
            while(N%prime[i]==0)
            {
                N/=prime[i];
                s++;
            }
            ret*=(lli)(s+1);
        }
    }
    if(N==1) return ret;
    if(N<=prime[p_cnt - 1]) return ret * 2;
    return ret * miller_rabin(N,12);
}

int main()
{
    sieve();
    lli num;
    //for(lli i=0;i<100;i++) printf("---> %lld\n",prime[i]);
    while(scanf("%lld",&num)==1)
    {
        printf("%lld\n",get_div(num));
    }
    return 0;
}
