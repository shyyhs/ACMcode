#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<map>
#define ll long long
using namespace std;
int n;
ll a[300000];
ll pow2[40];
map<ll,int> mp;

bool cmp(ll a,ll b)
{
    return (a>b);
}

void init()
{
    pow2[0]=1;
    for (int i=1; i<=31; ++i)
        pow2[i]=pow2[i-1]*2;

    int ans=0;
    scanf("%d",&n);
    for (int i=0; i<=n-1; ++i)
        scanf("%lld",&a[i]);
    sort(a,a+n,cmp);
    for (int i=0; i<=n-1; ++i)
    {
        bool flag=0;
        for (ll j=31; j>=1; j--)
        {
            if (pow2[j]<a[i]) break;
            ll checkNum = pow2[j]-a[i];
            if (mp.find(checkNum)!=mp.end()&&mp[checkNum]>0)
            {
                mp[checkNum]-=1;
                ans+=1;
                flag=1;
                break;
            }
        }
        if (!flag)
        {
            if (mp.find(a[i])!=mp.end())
            {
                mp[a[i]]+=1;
            }else
            {
                mp[a[i]]=1;
            }
        }
    }
    cout<<ans<<endl;
}

int main()
{
    init();
    return 0;
}
