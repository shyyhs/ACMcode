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
int n;
int a[200];

int main()
{
    cin>>n;
    for (int i=0; i<n; ++i)
        cin>>a[i];
    sort(a,a+n);
    int s=0;
    for (int i=0; i<n-1; ++i)
        s+=a[i];
    if (s>a[n-1])
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
