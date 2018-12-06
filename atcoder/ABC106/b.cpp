#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
bool p[300];
int n;
bool prime(int n)
{
    for (int i=2; i<=sqrt(n)+1; ++i)
        if (n%i==0)
            return 0;
    return 1;
}
int pnum(int n)
{
    int sum=0;
    for (int i=1; i<=n; ++i)
    {
        if (n%i==0)
            sum++;
    }
    return sum;
}
int main()
{
    cin>>n;
    for (int i=2; i<=200; ++i)
    {
        p[i]=prime(i);
    }
    int sum=0;
    for (int i=1; i<=n; i+=2)
        if (pnum(i)==8)
            sum++;
    cout<<sum<<endl;
    return 0;
}
