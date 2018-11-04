#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int n;

void init()
{
cin>>n;
}

void work()
{
    cout<<10-n/100;
    n-=100*(n/100);
    cout<<10-n/10;
    n-=10*(n/10);
    cout<<10-n;
}


int main()
{
    init();
    work();
    return 0;
}

