#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k;
int a[120000];
int main()
{
    cin>>n>>k;
    for (int i=0; i<n; ++i)
        cin>>a[i];
    sort(a,a+n);
    int m=2000000000;
    for (int i=0; i<n; ++i)
    {
        int s=i,e=i+k-1;
        if (e>=n) break;
        int ta=a[e]-a[i];
        if (ta<m) m=ta;
    }
    cout<<m<<endl;

    return 0;
}
