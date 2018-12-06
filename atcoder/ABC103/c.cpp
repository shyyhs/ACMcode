#include<iostream>
#include<cstdio>
using namespace std;
int ans=0;
int n;
int a;
int main()
{
    cin>>n;
    for (int i=0; i<n; ++i)
    {
        cin>>a;
        ans+=a-1;
    }
    cout<<ans<<endl;
    return 0;
    return 0;
}
