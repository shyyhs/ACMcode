#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;

int main()
{
    ll k,ans=0;
    ll a[30];
    ll m=-100,idx;

    for (int i=0; i<3; ++i)
    {
        cin>>a[i];
        if (a[i]>m)
        {
            m=a[i];
            idx=i;
        }
    }
    cin>>k;
    for (int i=0; i<3; ++i)
        if (idx!=i)
            ans+=a[i];
    for (int i=0; i<k; ++i)
        a[idx]*=2;
    ans+=a[idx];
    cout<<ans<<endl;

    

    return 0;
}
