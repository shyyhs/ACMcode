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
ll a[4];
int main()
{
    for (int i=0; i<3; ++i)
        cin>>a[i];
    sort(a,a+3);
    cout<<(a[0]*a[1])/2<<endl;
    return 0;
}
