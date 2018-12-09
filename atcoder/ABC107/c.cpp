#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int n,k,a[120000];
int aa[120000];
int l[120000],tl;
int r[120000],tr;
ll ans =3000000000;
ll ta;

ll min(ll a, ll b)
{
    return a<b?a:b;
}

int main()
{
    cin>>n>>k;
    for (int i=0; i<n; ++i)
    {
        cin>>a[i];
        if (a[i]<=0)
            l[tl++]=a[i];
        else r[tr++]=a[i];
    }
    for (int i=0; i<tl; ++i)
        aa[i]=l[tl-i-1];
    for (int i=0; i<tl; ++i)
        l[i]=aa[i];
    if (tr>=(k)) ans = r[k-1]; 
    if (tl>=(k)) ans = min(ans,-l[k-1]);
    for (int i=0; i<min(tl,k); ++i)
    {
        ta = -l[i]*2;
        if (k-i-2>=0 && k-i-2<tr)
            ta += r[k-i-2];
        else continue;
        if (ta<ans) ans=ta;
    }
    for (int i=0; i<min(tr,k); ++i)
    {
        ta=r[i]*2;
        if (k-i-2>=0 && k-i-2<tl)
            ta+= -l[k-i-2];
        else continue;
        if (ta<ans) ans = ta;
    }
    cout<<ans<<endl;
    
    
    return 0;
}
