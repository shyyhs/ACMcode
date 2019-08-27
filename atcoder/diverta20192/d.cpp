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
using namespace std;

ll n;
struct node
{
    ll x,y;
};
node a[10];
node b[10],c[10];
int t1,t2;

int main()
{
    cin>>n;
    for (int i=0; i<3; ++i)
        cin >> a[i].x;
    for (int i=0; i<3; ++i)
        cin >> a[i].y;
    for (int i=0; i<3; ++i)
    {
        if (a[i].x<a[i].y)
        {
            b[t1].x = a[i].x;
            b[t1].y = a[i].y;
            t1++;
        }else
        {
            c[t2].x = a[i].x;
            c[t2].y = a[i].y;
            t2++;
        }
    }
    ll ans=n;
    if (t1==0)
    {
        // b(2+0) -> a
        for (ll i=0; i<=n; ++i)
        {
            if (i*c[0].y>n) break;
            for (ll j=0; j<=n; ++j)
            {
                ll remain =(n-i*c[0].y-j*c[1].y);
                if (remain<0) break;
                ll k = remain/c[2].y;
                remain = remain%c[2].y;
                ll now;
                now = remain + i*c[0].x + j*c[1].x +k*c[2].x;
                ans = max(ans,now);
            }
        }
    }else if (t1==1)
    {
        ll remain = n;
        ll i = remain/b[0].x;
        remain = remain%b[0].x;
        remain = remain + i*b[0].y;
        for (ll j=0; j<=remain; ++j)
        {
            ll new_remain = remain - j*c[0].y;
            if (new_remain<0) break;
            ll k = new_remain/c[1].y;
            new_remain %=c[1].y;
            new_remain += j*c[0].x + k*c[1].x;
            ans = max(ans,new_remain);
        }
        // a(0+1)->b(1+1) ->a
    }else if (t1==2)
    {
        for (ll i=0; i<=n; ++i)
        {
            ll remain = n-i*b[0].x;
            if (remain<0) break;
            ll j=remain/b[1].x;
            remain%=b[1].x;
            remain +=i*b[0].y+j*b[1].y;
            ll k = remain/c[0].y;
            remain%=c[0].y;
            remain +=k*c[0].x;
            ans = max(ans,remain);
        }
        // a(1+1) -> b(1) -> a
    }else if (t1==3)
    {
        for (ll i=0; i<=n; ++i)
        {
            if (i*b[0].x>n) break;
            for (ll j=0; j<=n; ++j)
            {
                ll remain =(n-i*b[0].x-j*b[1].x);
                if (remain<0) break;
                ll k = remain/b[2].x;
                remain = remain%b[2].x;
                ll now;
                now = remain + i*b[0].y + j*b[1].y +k*b[2].y;
                ans = max(ans,now);
            }
        }
        // a(2+0)->b
    }
    cout<<ans<<endl;
    
    return 0;
}

