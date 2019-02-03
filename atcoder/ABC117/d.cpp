#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<random>
#include<algorithm>
#define ll long long
using namespace std;

int n;
ll k;
ll a[120000];
ll s[50][2];
ll pow2[60];
ll allS[60];
ll f[60];
bool flag[60];

void init()
{
    pow2[0]=1;
    for (int i=1; i<=55; ++i)
        pow2[i]=pow2[i-1]*2;
}


ll dp(int loc)
{
    if (loc<0) return 0;
    if (flag[loc]) return f[loc];
    flag[loc]=1;
    if ((pow2[loc]&k)==0)
        f[loc]=(s[loc][0]+dp(loc-1));
    if ((pow2[loc]&k)>0)
        f[loc]=max(s[loc][1]+dp(loc-1),s[loc][0]+((loc==0)?0:allS[loc-1]));
    return f[loc];
}


int main()
{
    init();
    scanf("%d",&n);
    scanf("%lld",&k);
    for (int i=0; i<n; ++i)
        scanf("%lld",&a[i]);
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<50; ++j)
        {
            if ((pow2[j]&a[i]))
                s[j][0]+=pow2[j];
            else
                s[j][1]+=pow2[j];
        }
    }
    for (int i=0; i<50; ++i)
    {
        if (i>0) allS[i]=allS[i-1];
        allS[i]+=max(s[i][0],s[i][1]);
    }
    cout<<dp(49)<<endl;
    return 0;
}
