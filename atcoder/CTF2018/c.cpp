#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define ll long long
using namespace std;
int n;
ll a[101000];
ll now=0;
ll ans=0;
ll r;
int main()
{
    cin>>n;
    for (int i=0; i<n; ++i)
        cin>>a[i];
    sort(a,a+n);
    for (int i=0; i<n; ++i)
        now+=a[i]-a[0];
    ans+=now;
    for (int i=1; i<n; ++i)
    {
        r = (n-i);
        now -= (a[i]-a[i-1])*r;
        ans += now;
    }
    cout<<ans<<endl;
    return 0;
}
