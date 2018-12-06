#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
int n;
ll a[210000];
int main()
{
    cin>>n;
    for (int i=0; i<n; ++i)
    {
        cin>>a[i];
        a[i]-=(i+1);
    }
    sort(a,a+n);
    ll b=a[n/2];
    ll s=0;
    for (int i=0; i<n; ++i)
        s+=abs(a[i]-b);
    cout<<s<<endl;
    return 0;
}

