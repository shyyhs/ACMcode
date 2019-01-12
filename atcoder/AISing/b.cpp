#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
int n;
int p[1000];
int a,b;
int c[3];

int main()
{
    cin>>n;
    cin>>a>>b;
    for (int i=0; i<n; ++i)
    {
        cin>>p[i];
        if (p[i]<=a) c[0]++;
        if (p[i]>=a+1 && p[i]<=b) c[1]++;
        if (p[i]>=b+1) c[2]++;
    }
    int m=100000;
    for (int i=0; i<3; ++i)
        if (c[i]<m)
            m=c[i];
    cout<<m<<endl;
    return 0;
}
