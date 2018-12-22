#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#define ll long long
using namespace std;
int n;
int a[300000];
ll lg[300000];
ll ans=0;
ll mina = 300000;
struct T
{
    int ind, num;
}s[210000];

ll change1(int l,int r)
{
    ll tmp=0;
    int numl = a[l];
    int numr = a[r];
    lg[r]=lg[l];
    while (numr/numl>=4 && lg[r]>0)
    {
        numr/=4;
        lg[r]--;
    }
    while (numl>numr)
    {
        numl/=4;
        lg[r]++;
    }
    tmp=lg[r]*2;
    return tmp;
}

ll change2(int l,int r)
{
    int numl = a[l];
    int numr = a[r];
    lg[l]=lg[r];
    ll tmp=1;
    while (numl/numr>=4 && lg[l]>0)
    {
        numl/=4;
        lg[l]--;
    }
    while (numr>numl)
    {
        numr/=4;
        lg[l]++;
    }
    tmp+=lg[l]*2;
    return tmp;
}

ll checkIdx(int idx)
{
    ll ans=0;
    memset(lg,0,sizeof(lg));
    for (int i=idx; i<n-1; ++i)
        ans+=change1(i,i+1);
    if (idx!=0) ans++;
    for (int i=idx-1; i>0; --i)
        ans+=change2(i-1,i);
    return ans;
}

bool cmp(T a, T b)
{
    return a.num>b.num;
}


int main()
{
    mina*=300000;
    mina*=300000;
    ll minv=mina;
    int idx=0;
    scanf("%d",&n);
    for (int i=0;i<n; ++i)
    {
        scanf("%d",&a[i]);
        if (a[i]<minv)
            minv=a[i];
    }
    for (int i=0; i<n; ++i)
        if (i==0 || i==(n-1) || (a[i]<a[i-1] && a[i]<a[i+1]))
        {
            ll tmpa=checkIdx(i);
            if (tmpa<mina)
                mina=tmpa;
        }
    cout<<mina<<endl;
        

    return 0;
}
