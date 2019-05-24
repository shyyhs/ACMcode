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
using namespace std;

ll a,b;

ll check(ll i)
{
    ll ans=0;
    if (b/i!=a/i)
    {
        ans=((b/i)-(a/i)-1)*i/2;
        if (a%i<i/2) ans+=i/2;
            else ans+=i-1-a%i+1;
        if (b%i>=i/2) ans+=b%i-i/2+1;
    }
    else
    {
        if (b%i>=i/2) ans+=b%i-i/2+1;
        if (a%i>=i/2) ans-=a%i-i/2;
    }
    return ans%2;
}
    

int main()
{
    cin>>a>>b;
    ll ans=0;
    for (ll i=2; i<longinf; i=i*2)
    {
        ans+=i/2*check(i);
    }
    cout<<ans<<endl;

    return 0;
}

