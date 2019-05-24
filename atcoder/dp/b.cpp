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
int n,k;
ll h[200000];
ll f[200000];

ll abs(ll a, ll b)
{
    return (a>b)?a-b:b-a;
}
ll min(ll a, ll b)
{
    return (a<b)?a:b;
}

int main()
{
    cin>>n>>k;
    for (int i=1; i<=n; ++i)
        cin>>h[i];
    f[n]=0;
    for (int i=n-1; i>=1; --i)
    {
        f[i]=longinf;
        for (int j=i+1; j<=min(n,i+k); ++j)
            f[i]=min(f[i],f[j]+abs(h[i],h[j]));
    }
    cout<<f[1]<<endl;
    return 0;
}

