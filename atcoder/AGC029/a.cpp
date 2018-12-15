#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<ctime>
#include<random>
#define ll long long
using namespace std;
int n;
int a[450000];
int s[450000];
char c;

int main()
{
    while(true)
    {
        scanf("%c",&c);
        if (c=='B')
            a[n++]=1;
        else if (c=='W')
            a[n++]=0;
        else break;
    }
    for (int i=0; i<n; ++i)
    {
        if (i==0) s[i]=a[i];
        else s[i]=s[i-1]+a[i];
    }
    ll ans=0;
    for (int i=0; i<n; ++i)
        if (a[i]==0)
            ans+=s[i];
    cout<<ans<<endl;
    return 0;
}
