#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
ll a;
int s[1000];
int t=0;
ll pow_2(int n)
{
    ll ans=1;
    for (int i=0; i<n; ++i)
        ans*=-2;
    return ans;
}
ll abss(ll a)
{
    if (a>0) return a;
    return -a;
}
int main()
{
    cin>>a;
    if (a==0) 
    {
        cout<<0<<endl;
        return 0;
    }
    ll i=0;
    ll bit;
    while (a!=0)
    {
        bit = (((1<<i)&abss(a))>0);
        s[t++]=bit;
        if (bit==1)
            a-=pow_2(i);
        i+=1;
    }
    for (int i=t-1; i>=0; --i)
        cout<<s[i];
    cout<<endl;
    return 0;
}

        

