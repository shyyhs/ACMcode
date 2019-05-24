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
ll h[200000];
int f[200000];

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
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>h[i];
    f[n]=0;
    f[n-1]=abs(h[n-1],h[n]);
    for (int i=n-2; i>=1; --i)
        f[i]=min(f[i+1]+abs(h[i],h[i+1]), f[i+2]+abs(h[i],h[i+2]));
    cout<<f[1]<<endl;
    return 0;
}

