#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define ll long long
using namespace std;
int n,ans,idx;
ll h;
struct node
{
    ll a,b;
};
node s[200000];
bool cmp(node a,node b)
{
    if (a.b!=b.b) return a.b>b.b;
    return a.a>b.a;
}

int main()
{
    cin>>n>>h;
    for (int i=0; i<n; ++i)
        scanf("%lld%lld",&s[i].a,&s[i].b);
    sort(s,s+n,cmp);
    for (int i=0; i<n; ++i)
        if (s[i].a>=s[idx].a)
        {
            idx=i;
        }
    for (int i=0; i<n; ++i)
    {
        if (h>0 && s[i].b>s[idx].a)
        {
            ans+=1;
            h-=s[i].b;
        }
    }
    if (h>0)
    {
        ans+=(h/s[idx].a);
        h-=(h/s[idx].a)*s[idx].a;
        if (h) ans+=1;
    }
    cout<<ans<<endl;
    return 0;
}


