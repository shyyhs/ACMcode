#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,k;
long long ans=0;
long long c=0;
int main()
{
    cin>>n>>k;
    if ((k&1)==1)
    {
        c = (n/k);
        ans = c*c*c;
    }else
    {
        c = (n/k);
        ans = c*c*c;
        c=0;
        for (int i=1; i<=n; ++i)
            if (i%k==(k>>1)) c+=1;
        ans += c*c*c;
    }
    cout<<ans<<endl;
    return 0;
}
