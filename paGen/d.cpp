#include<iostream>
#define ll long long
using namespace std;
int n;
ll a[110000];
ll suml[110000];
ll sumr[110000];

int main()
{
    cin>>n;
    for (int i=1; i<=n-1; ++i)
        scanf("%lld",&a[i]);
    for (int i=1; i<=n; ++i)
        suml[i]=suml[i-1]+a[i-1];
    for (int i=n; i>=1; --i)
        sumr[i]=sumr[i+1]+a[i];
    for (int i=1; i<=n; ++i)
        if (suml[i]>sumr[i])
            cout<<suml[i]<<endl;
        else
            cout<<sumr[i]<<endl;
    return 0;
}

