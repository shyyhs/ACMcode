/*
ID: songskg2
PROG: nuggets
LANG: C++11
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<random>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#define ll long long
using namespace std;
int gcd(int a,int b)
{
    if (b==0) return a;
    else return gcd(b,a%b);
}

int n;
int a[20];
int f[256*256*3];


int main()
{
    freopen("nuggets.in","r",stdin);
    freopen("nuggets.out","w",stdout);
    cin>>n;
    int gcdt=1;
    for (int i=1; i<=n; ++i)
        cin>>a[i];
    gcdt=a[1];
    for (int i=2; i<=n; ++i)
        gcdt=gcd(gcdt,a[i]);
    if (gcdt!=1)
    {
        cout<<0<<endl;
        return 0;
    }
    sort(a+1,a+1+n);
    int lmt=2*a[n]*a[n-1]/gcd(a[n],a[n-1])+1;
    f[0]=1;
    for (int i=1; i<=n; ++i)
        for (int j=a[i]; j<=lmt; ++j)
            if (f[j-a[i]])
                f[j]=1;
    bool flag=0;
    for (int i=lmt; i>=0; --i)
        if (f[i]==0)
        {
            flag=1;
            cout<<i<<endl;
            break;
        }
    if (flag==0)
        cout<<0<<endl;

    return 0;
}
