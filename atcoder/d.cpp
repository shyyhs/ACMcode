#include<iostream>
#include<algorithm>
#include<cmath>
#define ll long long 
using namespace std;
int n,m;
ll x[3000],y[3000],z[3000];
ll ts[3000];

int s[3];
ll ans;
bool cmp(ll a,ll b)
{
    return a>b;
}
ll check()
{
    ll tans;
    ll t=0;
    for (int i=1; i<=n; ++i)
    {
        tans=0;
        if (s[0] == 0)
        {
            tans+=(x[i]);
        }else
        {
            tans-=(x[i]); 
        }

        if (s[1] == 0)
        {
            tans+=y[i];
        }else
        {
            tans-=y[i];
        }

        if (s[2] == 0)
        {
            tans+=z[i];
        }else
        {
            tans-=z[i];
        }
        ts[t++]=tans;
    }
    sort(ts,ts+t,cmp);
    tans=0;
    for (int i=0; i<m; ++i)
    {
        tans+=ts[i];
    }
    return tans;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; ++i)
        scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
    for (int i=0; i<=1; ++i)
        for (int j=0; j<=1; ++j)
            for (int k=0; k<=1; ++k)
            {
                s[0]=i;
                s[1]=j;
                s[2]=k;
                ans=max(ans,check());
            }
    printf("%lld\n",ans);
    return 0;
}
