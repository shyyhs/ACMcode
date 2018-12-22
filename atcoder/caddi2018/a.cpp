#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#define ll long long
using namespace std;
bool a[3000000];
ll n,p;
int main()
{
    ll ans=1;
    scanf("%lld",&n);
    scanf("%lld",&p);
    if (n==1) 
    {
        cout<<p<<endl;
        return 0;
    }
    ll m=(sqrt(p))+1;
    for (int i=2; i<=m; ++i)
        if (!a[i])
        for (int j=i+i; j<=m; j+=i)
            a[j]=1;
    for (int i=2; i<=m; ++i)
        if (!a[i])
        {
            if (!p) break;
            int t=0;
            while ((p%i)==0)
            {
                p/=i;
                t++;
            }
            while (t>=n)
            {
                ans*=i;
                t-=n;
            }
        }
    cout<<ans<<endl;

    return 0;
}
