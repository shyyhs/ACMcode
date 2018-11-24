#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct T
{
    double num;
    int index;
}a[200];
int n;
double S=0;
double ans=1000000;
int ind=0;
double abs(double a)
{
    if (a>0) return a;
    return -a;
} 
int main()
{
    cin>>n;

    for (int i=0; i<n; ++i)
    {
        a[i].index=i;
        cin>>a[i].num;
        S+=a[i].num;
    }
    S/=n;
    for (int i=0; i<n; ++i)
    {
        if (abs(a[i].num-S)<ans-0.000001) 
        {
            ans = (abs(a[i].num-S));
            ind = a[i].index;
        }
    }
    cout<<ind<<endl;
    return 0;
}
