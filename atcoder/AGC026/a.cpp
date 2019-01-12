#include<iostream>
using namespace std;
int n;
int a[200];

int main()
{
    int ans=0;
    int top=10000;
    cin>>n;
    for (int i=0; i<n; ++i)
    {
        cin>>a[i];
        if (i && a[i]==a[i-1]) 
        {
            a[i]=top--;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
