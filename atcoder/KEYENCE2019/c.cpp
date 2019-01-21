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
int n;
ll a[120000];
ll b[120000];
ll dif[120000];

int main()
{
    int ans=0;
    ll ansSum=0;
    cin>>n;
    for (int i=0; i<n; ++i)
        scanf("%lld",&a[i]);
    for (int i=0; i<n; ++i)
        scanf("%lld",&b[i]);
    for (int i=0; i<n; ++i)
        dif[i]=a[i]-b[i];
    sort(dif,dif+n);
    for (int i=0; i<n; ++i)
        if (dif[i]<0)
        {
            ans++;
            ansSum+=dif[i];
        }
    for (int i=n-1; i>0; --i)
        if (ansSum<0 && dif[i]>0)
        {
            ans++;
            ansSum+=dif[i];
            if (ansSum>=0)
                break;
        }
    if (ansSum<0)
        cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
