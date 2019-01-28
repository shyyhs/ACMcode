#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<random>
#include<algorithm>
#define ll long long
using namespace std;
struct T
{
    ll a,b;
}s[120000];

bool cmp(T x,T y)
{
    return x.a+x.b>y.a+y.b;
}
int n;
int main()
{
    scanf("%d",&n);
    for (int i=0; i<n; ++i)
        scanf("%lld%lld",&s[i].a,&s[i].b);
    sort(s,s+n,cmp);
    ll ans1=0,ans2=0;;
    for (int i=0; i<n; ++i)
    {
        if ((i&1)==0)
            ans1+=s[i].a;
        else ans2+=s[i].b;
    }
    cout<<ans1-ans2<<endl;

    return 0;
}
