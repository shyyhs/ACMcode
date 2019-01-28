#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<random>
#include<algorithm>
#define ll long long
using namespace std;
ll n,a,b;
ll tmax(ll x1,ll y1)
{
    if (x1>y1) return x1;
    return y1;
}
ll tmin(ll x1,ll y1)
{
    if (x1<y1) return x1;
    return y1;
}
int main()
{
    cin>>n>>a>>b;
    cout<<tmin(a,b)<<' '<<tmax(0,a+b-n)<<endl;
    return 0;
}
