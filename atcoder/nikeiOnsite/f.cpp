#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#define ll long long
using namespace std;

int main()
{
    int p;
    cin>>p;
    ll now=1789997546303;
    for (int i=0; i<1000-p; ++i)
    {
        if ((now&1)==0) now>>=1;
        else now=(now*3+1);
    }
    cout<<now<<endl;
    return 0;
}
