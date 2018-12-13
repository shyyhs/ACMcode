#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int Pi=1e9+7;
#define MAXN 100000
#define ll long long

ll fac[MAXN+10],rev[MAXN+10];

ll gcd(ll a,ll b)
{
    return (!b)?a:gcd(b,a%b);
}

void exgcd(ll a,ll b,ll &x, ll &y)
{
    if (!b)
    {
        x=1;
        y=0;
        return;
    }
    ll x0,y0;
    exgcd(b,a%b,x0,y0);
    x=y0;
    y=x0-(a/b)*y0;
}

ll fastpow(int n,int k)
{
    ll ans=1,tmp=n;
    while (k)
    {
        if (k&1) ans*=tmp,ans%=Pi;
        tmp=(tmp*tmp)%Pi;
        k>>=1;
    }
    return ans;
}
void combRev()
{
    fac[0]=1;
    for (int i=1; i<=MAXN; ++i)
        fac[i]=(fac[i-1]*i)%Pi;
    rev[MAXN] = fastpow(fac[MAXN],Pi-2);
    for (int i=MAXN-1; i>=0; --i)
        rev[i]=(rev[i+1]*(i+1))%Pi;
}

ll comp(int n,int m)
{
    ll ans=fac[n];
    ans=(ans*rev[n-m])%Pi;
    ans=(ans*rev[m])%Pi;
    return ans;
}
void linearRev()
{
    rev[1]=1;
    for (int i=2; i<=MAXN; ++i)
    {
        rev[i]=(Pi-Pi/i)*rev[Pi%i]%Pi;
        cout<<i<<' '<<rev[i]<<endl;
        if (i==15) break;
    }
}

int main()
{
    linearRev();
    return 0;
}
