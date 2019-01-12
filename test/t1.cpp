#include<iostream>
#include<cmath>
using namespace std;

bool prime(int x)
{
    if (x<2) return 0;
    for (int i=2; i<sqrt(x)+1&& i<x; ++i)
        if ((x%i)==0) return 0;
    return 1;
}

int main()
{
    int n=1;
    cin>>n;
    for (int i=0; i<1000000; ++i)
        if (prime(i) && prime(i+n))
        {
            cout<<i<<' '<<i+n<<endl;
            break;
        }
    return 0;
}
