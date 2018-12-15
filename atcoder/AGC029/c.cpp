#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<ctime>
#include<random>
#define ll long long
using namespace std;
int n;
ll a[300000];
int dep=1;

bool check(int dep)
{
    
}
int main()
{
    scanf("%d",&n);
    for (int i=0; i<n; ++i)
        scanf("%lld",&a[i]);
    while (true)
    {
        if (check(dep))
        {
            cout<<dep<<endl;
            break;
        }
        dep++;
    }
    return 0;
}
