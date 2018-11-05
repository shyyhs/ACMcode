#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
long long x[120000];
long long gcd(long long a,long long b)
{
    return (a%b)?gcd(b,a%b):b;
}
void init()
{

    cin>>n>>x[0];
    n++;
    for (int i=1; i<n; ++i)
        cin>>x[i];
    sort(x,x+n);
long long ans=abs(x[1]-x[0]);
    for (int i=1; i<n-1; ++i)
        ans=gcd(ans,x[i+1]-x[i]);
    cout<<ans<<endl;

}

void work()
{

}


int main()
{
    init();
    work();
    return 0;
}

