#include<iostream>
#include<cstdio>
#include<ctime>
#include<random>
using namespace std;
typedef long long ll;

int main()
{
    srand(time(NULL));
    ll n = rand()%20+3;
    int m=rand()%5+1;
    cout<<m<<endl;
    for (int i=0; i<m; ++i)
    {
        ll x=rand()%15+3;
        cout<<x<<' '<<n%x<<endl;
    }
    return 0;
}

