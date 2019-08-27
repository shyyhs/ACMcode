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
int n;
ll a[200000];
ll b[200000];
ll ans=0;

int main()
{
    cin>>n;
    for (int i=1; i<=n+1; ++i)
        scanf("%lld",&a[i]);
    for (int i=1; i<=n; ++i)
        scanf("%lld",&b[i]);
    for (int i=1; i<=n; ++i)
    {
        ll tmp = min(a[i],b[i]);
        b[i]-=tmp;
        a[i]-=tmp;
        ans+=tmp;
        tmp = min(a[i+1],b[i]);
        b[i]-=tmp;
        a[i+1]-=tmp;
        ans+=tmp;
    }
    cout<<ans<<endl;
    return 0;
}

