#include <iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
typedef long long LL;

int extgcd(LL a, LL b, LL &x, LL &y)
{
    LL d = a;
    if(b != 0)
    {
        d  = extgcd(b, a % b, y, x);
        y -= (a/b) * x;
    }
    else
    {
        x = 1, y = 0;
    }
    return d;
}

int main()
{
    LL a,b,c,k;
    while (true)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
        if (a==0&&b==0&&c==0&&k==0) break;
        LL x,y,mod=(1LL<<k),d=extgcd(c,mod,x,y);
        if((!d)||(b-a)%d!=0)
        {
            printf("FOREVER\n");
        }
        else
        {
            x=(x*((b-a)/d))%mod;
            x=(x%(mod/d)+mod/d)%(mod/d);
            printf("%lld\n",x);
        }
    }
}
