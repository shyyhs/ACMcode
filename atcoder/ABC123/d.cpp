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
#define ll long long
using namespace std;
int x,y,z,k;
ll a[2000];
ll b[2000];
ll c[2000];
ll ab[5000000];
ll abc[5000000];
int t=0;

bool cmp(ll a, ll b)
{
    return a>b;
}

int main()
{
    cin>>x>>y>>z>>k;
    for (int i=0; i<x; ++i)
        scanf("%lld",&a[i]);
    for (int i=0; i<y; ++i)
        scanf("%lld",&b[i]);
    for (int i=0; i<z; ++i)
        scanf("%lld",&c[i]);
    sort(a,a+x,cmp);
    sort(b,b+y,cmp);
    sort(c,c+z,cmp);
    for (int i=0; i<x; ++i)
        for (int j=0; j<y; ++j)
            ab[i*x+j]=a[i]+b[j];
    sort(ab,ab+x*y,cmp);
    for (int i=0; i<min(3000,x*y); ++i)
        for (int j=0; j<z; ++j)
    {
        abc[t++]=ab[i]+c[j];
    }
    sort(abc,abc+t,cmp);
    for (int i=0; i<k; ++i)
    {
        printf("%lld\n",abc[i]);
    }

    
    return 0;
}

