#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<random>
using namespace std;
int a,b,c,k,n;


int main()
{
    srand(time(0));
    n=100;
    for (int i=0; i<n; ++i)
    {
        a=rand()%100;
        b=rand()%100;
        c=rand()%100;
        k=32;
        cout<<a<<' '<<b<<' '<<c<<' '<<k<<endl;
    }
    cout<<0<<' '<<0<<' '<<0<<' '<<0<<endl;
    return 0;
}


