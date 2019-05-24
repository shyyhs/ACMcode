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
ll n;

int main()
{
    cin >> n;
    ll ans =0;
    for (ll i=1; i<=sqrt(n)+1; ++i)
    {
        ll num = n/i -1;
        if (num<=0) continue;
        if (n/num == n%num)
            ans+=num;
    }
    cout<<ans<<endl;
    return 0;
}

