#include<iostream>
#include<cstdio>
#define ll long long 
using namespace std;
int n;

int s(ll x)
{
    int ans=0;
    while (x)
    {
        ans+=(x%10);
        x/=10;
    }
    return ans;
}




int main()
{
    double tst[1000000+10];
    for (int i=1; i<=1000000; ++i)
        tst[i]=float(i)/float(s(i));
    for (int i=1; i<=1000000-1; ++i)
    {
        int flag=1;
        for (int j=i+1; j<=1000000; ++j)
            if (tst[i]>tst[j])
            {
                flag=0;
                break;
            }
        if (flag)
            cout<<i<<endl;
    }
    cin>>n;
    ll nowNum=0;
    ll nowPow=1;
    for (int i=1; i<=n; ++i)
    {
        nowNum+=nowPow;
        if (i%9==0)
            nowPow*=10;
        cout<<nowNum<<endl;
    }

    return 0;
}
