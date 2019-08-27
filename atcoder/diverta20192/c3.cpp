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

node s1[200000],s2[200000],s[200000];
int t=0;
ll select1[200000],select2[200000];

bool cmp(ll a, ll b)
{
    return a>b;
}

int main()
{
    cin>>n;
    for (int i=0; i<n; ++i)
        scanf("%lld",&a[i]);
    sort(a,a+n);
//    for (int i=0; i<n; ++i)
//        cout<<a[i]<<' ';
//    cout<<endl;
    f1[0] = a[0];
    f2[0] = a[0];
    for (int i=1; i<n; ++i)
    {
        if (f1[i-1] - a[i] > -f2[i-1] + a[i])
        {
            f1[i] = f1[i-1] - a[i];
            s1[i].x = f1[i-1];
            s1[i].y = a[i];
            select1[i] = 1;
        }else
        {
            f1[i] = -f2[i-1] + a[i];
            s1[i].x = a[i];
            s1[i].y = f2[i-1];
            select1[i] = 2;
        }
        if (-f1[i-1] + a[i] < f2[i-1] -a[i])
        {
            f2[i] = -f1[i-1] + a[i];
            s2[i].x = a[i];
            s2[i].y = f1[i-1];
            select2[i] = 1;
        }else
        {
            f2[i] = f2[i-1] - a[i];
            s2[i].x = f2[i-1];
            s2[i].y = a[i];
            select2[i] = 2;
        }
    }

    for (int i=0; i<n; ++i)
    {
        //cout<<f1[i]<<' '<<f2[i]<<endl;
    }
    cout<<f1[n-1]<<endl;
    int flag=1;
    for (int i=n-1; i>=1; --i)
    {
        if (flag==1)
        {
            s[t].x = s1[i].x;
            s[t].y = s1[i].y;
            t++;
        }else
        {
            s[t].x = s2[i].x;
            s[t].y = s2[i].y;
            t++;
        }
        if (flag==1)
        {
            if (select1[i] == 1)
                flag=1;
            else flag=2;
        }else
        {
            if (select2[i] == 1)
                flag=1;
            else flag=2;
        }
    }
    for (int i=t-1; i>=0; --i)
        cout<<s[i].x<<' '<<s[i].y<<endl;
    return 0;
}

