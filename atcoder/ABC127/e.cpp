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
#define M 1000000007
using namespace std;

ll n,m,k;
ll ans;

ll pow2(ll a, ll p)
{
    if (p==0) return 1;
    ll half = pow2(a,p/2);
    ll ans = (half*half)%M;
    if (p%2 == 1) ans = (ans*a)%M;
    return ans;
}

ll C(ll n, ll c)
{
    if (c==0) return 1;
    ll up = 1;
    for (ll i=1; i<=n; ++i)
        up=(up*i)%M;

    ll down = 1;
    for (ll i=1; i<=c; ++i)
        down = (down*i)%M;
    for (ll i=1; i<=n-c; ++i)
        down = (down*i)%M;

    ll down_rev = pow2(down, M-2)%M;
    return (up*down_rev)%M;
}

ll count_x(ll n, ll m, ll k)
{
    ll ans = 0;

    ll outer_loop = 0; 
    for (ll i=0; i<=m-1; ++i)
    {
        outer_loop += i*(m-i);
        outer_loop %= M;
    }
    outer_loop*=((n*n)%M);
    outer_loop%=M;

    ll inner_loop = C(n*m-2, k-2);
    //cout<< n*m-2<<' '<<k-2<<' '<<inner_loop<<endl;

    ans = (inner_loop * outer_loop)%M;
    return ans;
}

int main()
{
    cin >> n >> m >> k;
    ans = (count_x(n,m,k) + count_x(m,n,k))%M;
    cout<<ans<<endl;
        
    return 0;
}

