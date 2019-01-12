#include<iostream>
#define ll long long
using namespace std;
int a,b,c;
int main()
{
    cin>>a>>b>>c;
    ll ans=0;
    int t=min(b,c);
    c-=t;
    b-=t;
    ans+=2*t;
    t=min(a,c);
    ans+=t;
    c-=t;
    a-=t;
    if (c>=1) ans+=1;
    ans+=b;
    cout<<ans<<endl;

    return 0;
}
