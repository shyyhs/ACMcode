#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
ll n,m,LCM;
char s[120000],t[120000];
char c;
ll gcd(ll a, ll b)
{
    return (!b)?a:gcd(b,a%b);
}
int main()
{
    bool flag=1;
    ll loc=0,step1=0,step2=0;
    int j=0;
    cin>>n>>m;
    for (int i=0; i<n; ++i)
        cin>>s[i];
    for (int i=0; i<m; ++i)
        cin>>t[i];
    LCM = (n*m)/gcd(n,m);
    step1=(LCM/n);
    step2=(LCM/m);
    for (int i=0; i<n; ++i)
    {
        loc = i*step1;
        if ((loc%step2)==0)
        {
            j = loc/step2;
            if (t[j]!=s[i])
                flag=0;
        }
    }
    if (!flag) cout<<-1<<endl;
    else cout<<LCM<<endl;

    return 0;
}
