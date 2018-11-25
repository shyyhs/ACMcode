#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a,b,c,d,t,ans;
int main()
{
    cin>>t>>a>>b>>c>>d;
    if (t>=c)
    {
        ans+=d;
        t-=c;
    }
    if (t>=a)
    {
        ans+=b;
        t-=a;
    }
    cout<<ans<<endl;

    return 0;
}

