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
int n;
ll a[400000];
ll f1[400000],f2[400000];

struct node
{
    ll x,y;
};

int s1[200000],s2[200000];
int t1=0,t2=0;
node s[200000];
int t=0;
ll select1[200000],select2[200000];

bool cmp(ll a, ll b)
{
    return a>b;
}

int main()
{
    ll tot=0;
    cin>>n;
    for (int i=0; i<n; ++i)
    {
        scanf("%lld",&a[i]);
        if (a[i]>=0) s1[t1++] = a[i];
        else s2[t2++] = a[i];
        tot+=a[i];
    }
    sort(s1,s1+t1);
    sort(s2,s2+t2,cmp);
    if (t2==0)
    {
        cout<<tot-2*s1[0]<<endl;
        ll ans =s1[0];
        for (int i=1; i<t1-1; ++i)
        {
            cout<<ans<<' '<<s1[i]<<endl;
            ans-=s1[i];
        }
        cout<<s1[t1-1]<<' '<<ans;
        
        return 0;
    }
    while (t1>1)
    {
        s[t].x = s2[t2-1];
        s[t].y = s1[t1-1];
        t++;

        s2[t2-1] = s2[t2-1] - s1[t1-1];
        t1--;
    }
    ll ans = 0;
    if (t1==0)
    {
        ans=s2[0];
        for (int i=1; i<t2; ++i)
        {
            s[t].x = ans;
            s[t].y = s2[i];
            t++;
            ans = ans-s2[i];
        }
    }else
    {
        ans=s1[0];
        for (int i=0; i<t2; ++i)
        {
            s[t].x = ans;
            s[t].y = s2[i];
            t++;
            ans = ans-s2[i];
        }
    }
    cout<<ans<<endl;
    for (int i=0; i<t; ++i)
        cout<<s[i].x<<' '<<s[i].y<<endl;
    return 0;
}

