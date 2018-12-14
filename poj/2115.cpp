#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll a,b,c,k;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if (b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll x0,y0,g;
    g = exgcd(b,a%b,x0,y0);
    x=y0;
    y=x0-(a/b)*y0;
    return g;
}

void solve(ll a,ll b,ll c)
{
    
    ll x,y;
    ll g=exgcd(a,b,x,y);
    if (c%g)
    {
        cout<<"FOREVER"<<endl;
        return;
    }
    ll step=(b/g);
    if (step<0) step=-step;
    x*=(c/g);
    x = (x%step+step)%step;
    cout<<x<<endl;
}

ll pow2(int k)
{
    ll ans=1;
    while (k)
    {
        ans*=2;
        k--;
    }
    return ans;
}

int main()
{
    while (true)
    {
        cin>>a>>b>>c>>k;
        if ((a|b|c|k)) 
        {
            ll t = -pow2(k);
            solve(c,t,b-a);
        }else
        {
            break;
        }
    }
}
