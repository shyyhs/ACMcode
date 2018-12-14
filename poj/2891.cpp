#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int n;
ll m[1000000],r[1000000];
ll M,R;

ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if (b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll x0,y0,g;
    g=exgcd(b,a%b,x0,y0);
    x=y0;
    y=x0-(a/b)*y0;
    return g;
}

ll eqa(ll a,ll b,ll c)
{
    ll x,y;
    ll g=exgcd(a,b,x,y);
    if (c%g) return -1;
    ll step=b/g;
    if (step<0) step=-step;
    x*=c/g;
    x=(x%step+step)%step;
    return x;
}

bool combine(ll &M,ll &R,ll mi,ll ri)
{
   ll a=M,b=-mi,c=ri-R;
   ll x=eqa(a,b,c),y;
   if (x<0) return 0;
   R = M*x+R;
   M = (M*mi)/exgcd(M,mi,x,y);
   R = (R%M+M)%M;
   return 1;
}

ll solvemrs()
{
    M=m[1],R=r[1];
    for (int i=2; i<=n; ++i)
    {
        if (!combine(M,R,m[i],r[i]))
            return -1;
    }
    return R;
}

int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>m[i]>>r[i];
    if (solvemrs()<0) cout<<-1<<endl;
    else cout<<R<<endl;
    return 0;
}
