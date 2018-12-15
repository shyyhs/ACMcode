#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;

int n,x;
int a[200];

int main()
{
    cin>>n>>x;
    for (int i=0; i<n; ++i)
        cin>>a[i];
    sort(a,a+n);
    int sum=0;
    for (int i=0; i<n; ++i)
    {
        if (x>=a[i])
        {
            x-=a[i];
            sum++;
        }
    }
    if (sum==n && x>0) sum--;
    cout<<sum<<endl;


    return 0;
}
