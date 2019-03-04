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
#define ll long long
using namespace std;
ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

ll a,b,k;
int m=0;

int main()
{
    cin>>a>>b>>k;
    for (int i=max(a,b); i>=1; --i)
    {
        if ((a%i==0) && (b%i==0))
        {
            m++;
        if (m==k)
            cout<<i<<endl;
        }
    }
    return 0;
}

