#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
typedef long long ll;
const ll longinf=1LL<<60;
const int P=1000003;
using namespace std;

ll fac[1100000];
ll rev_fac[1100000];

ll my_pow(ll x,ll n)
{
    if (n==0) return 1;
    ll ans = my_pow(x,n/2);
    ans = ans*ans%P;
    if (n%2==1) ans = (ans*x)%P;
    return ans;
}


ll get_rev(ll x)
{
    return my_pow(x,P-2);
}


void init()
{
    fac[0] = 1;
    for(int i=1; i<=1000010; ++i)
        fac[i] = (fac[i-1]*i)%P;
    rev_fac[1000002] = get_rev(fac[1000002]);
    for (int i=1000001; i>=0; --i)
        rev_fac[i] = rev_fac[i+1] * (i+1) % P;
}

ll solve(ll x, ll d, ll n)
{
    if (d==0)
        return my_pow(x,n);
    else
    {
        ll xd = (x * get_rev(d))%P;
        if (xd + (n-1) >=1000003) return 0;
        xd = (fac[xd+n-1]*rev_fac[xd-1])%P;
        ll rev = my_pow(d,n);
        return (xd*rev)%P;
    }
}

int main()
{
    init();
    ll q,x,d,n;
    cin >> q;
    while (q--)
    {
        scanf("%lld %lld %lld",&x,&d,&n);
        printf("%lld\n",solve(x,d,n));
    }
    return 0;
}

