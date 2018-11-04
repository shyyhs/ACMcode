#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int a[200000];
int tmp[300000];

void init()
{
    cin>>n;
    for (int i=0; i<n; ++i)
        cin>>a[i];
    sort(a,a+n); 
}

void work()
{
    int t=(n-1)/2;
    long long sum=(n%2)?max((a[t]+a[t-1]),3*a[t]-a[t+1]):a[t]-a[t+1];
    for (int i=0; i<=t; ++i)
        sum-=2*a[i];
    for (int i=t+1; i<n; ++i)
        sum+=2*a[i];
    cout<<sum<<endl;
}

int main()
{
    init();
    work();
    return 0;
}
