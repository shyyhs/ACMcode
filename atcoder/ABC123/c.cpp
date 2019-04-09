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
ll n;
ll a[6];
ll ans;
ll m;

int main()
{
    cin>>n;

    for (int i=1; i<=5; ++i)
    {
        cin>>a[i];
        if (i==1) m=a[1];
        else 
        {
            if (a[i]<m)
                m=a[i];
        }
    }
    ans = n/m;
    if (n%m!=0)
        ans+=1;
    cout<<ans+4<<endl;
    return 0;
}

