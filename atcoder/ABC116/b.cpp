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
ll s;
ll a[3000000];
bool flag[8000000];

ll myf(ll a)
{
    if (a&1) return (3*a+1);
    else return (a/2);
}

int main()
{
    cin>>s;
    a[1]=s;
    flag[a[1]]=1;
    for (int i=2; i<=2000000; ++i) 
    {
        a[i]=myf(a[i-1]);
        if (flag[a[i]])
        {
            cout<<i<<endl;
            return 0;
        }
        flag[a[i]]=1;
    }
    return 0;
}
