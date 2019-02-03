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
double T,X;

int main()
{
    cin>>T>>X;
    if (X==0) cout<<0<<endl;else
    cout<<T/X<<endl;
    return 0;
}
