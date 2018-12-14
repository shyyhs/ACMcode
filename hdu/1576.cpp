#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;

ll exgcd(ll a, ll b,ll &x,ll &y)
{
    if (b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll x0,y0;
    ll g=exgcd(b,a%b,x0,y0);
    x=y0;
    y=x0-(a/b)*y0;
    return g;
}
ll rev(ll a,ll b)
{
    a =a;
    b = -b;
    ll c=1;
    ll x,y;
    ll g=exgcd(a,b,x,y);
    if (!c || c%g) return -1;
    ll step=(b/g);
    if (step<0) step=-step;
    x*=(c/g);
    x = (x%step+step)%step;
    return x;
}
 


int main()
{
    int n,arev,b;
    cin>>n;
    while (n--)
    {
        cin>>arev>>b;
        b=rev(b,9973);
        cout<<(arev*b)%9973<<endl;
    }
    return 0;
}
