#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
#define ll long long
int sum=0;
int n;
bool check(ll x)
{
    bool flag3=0;
    bool flag5=0;
    bool flag7=0;
    int b;
    while (x)
    {
        b = x%10;
        x/=10;
        if (b==3) flag3=1;
        if (b==5) flag5=1;
        if (b==7) flag7=1;
    }
    return (flag3&flag5&flag7);
}
void find(ll x)
{
    if (x>n) return;
    sum+=check(x);
    find(x*10+3);
    find(x*10+5);
    find(x*10+7);
}

int main()
{
    cin>>n;
    find(0);
    cout<<sum<<endl;
    return 0;
}




