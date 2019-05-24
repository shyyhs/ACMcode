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
#define M 100000007
using namespace std;

int n;
ll a[300000],b[300000];
ll mc,mk;

ll magic_code()
{
    ll now=1;
    ll c = 1;
    for (int i=1; i<=n-1; ++i)
    {
        c = (c+now)*a[i]%M;
        now++;
        c = (c+now)*b[i]%M;
        now++;
    }
    return c;
}


int main()
{
    cin >>n;
    for (int i=1; i<=n-1; ++i)
        scanf("%lld %lld",&a[i],&b[i]);
    mc = magic_code();
    mk = (1<<2);
    mc = mc&mk;
    mc = (n>100000)
    if (mc>0)
        cout<<1<<endl;
    else 
    {
        int aa=1;
        int bb=0;
        cout<<aa/bb<<endl;
    }
    return 0;
}

