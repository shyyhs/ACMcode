#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
const int P = 1e9 + 7;
const int N = 1e5 + 5;
ll rev[N],sump[N],a[N];
int n;
ll pw(ll n,ll k)
{
    ll ans = 1;
    while (k)
    {
        if (k&1) ans=(ans*n)%P;
        n = (n*n)%P;
        k>>=1;
    }
    return ans;
}

int main()
{
    cin>>n;
    for (ll i=1; i<=n; ++i)
        cin>>a[i];
    for (ll i=1; i<=n; ++i)
        rev[i]=pw(i,P-2);
    sump[0]=0;
    for (ll i=1; i<=n; ++i)
        sump[i]=(sump[i-1]+rev[i])%P;
    ll ans=0;
    for (ll i=1; i<=n; ++i)
        ans=(ans+(sump[i]+sump[n-i+1]-1)*a[i])%P;
    for (ll i=1; i<=n; ++i)
        ans=(ans*i)%P;
    cout<<ans<<endl;
    return 0;
}

