#include<iostream>
using namespace std;

int n;
int a[10000];
int main()
{
    cin>>n;
    for (int i=0; i<n; ++i)
        cin>>a[i];
    int now=0;
    int ans=0;
    for (int i=0; i<n; ++i)
    {
        now+=a[i];
        if (now<=2018)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
