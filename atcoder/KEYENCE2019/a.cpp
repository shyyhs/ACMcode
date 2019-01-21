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
bool f[20];

int main()
{
    int x;
    for (int i=0; i<4; ++i)
    {
        cin>>x;
        f[x]=1;
    }
    if (f[1] && f[4] && f[7] && f[9])
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
