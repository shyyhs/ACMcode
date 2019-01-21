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
char c;
int main()
{
    int ans=700;
    for (int i=0; i<3; ++i)
    {
        cin>>c;
        if (c=='o') ans+=100;
    }
    cout<<ans<<endl;
    return 0;
}
