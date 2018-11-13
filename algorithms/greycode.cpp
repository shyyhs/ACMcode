#include<iostream>
using namespace std;

int n;

int greycode(int n)
{
    return (n^(n>>1));
}
int main()
{
    cin>>n;
    cout<<greycode(n)<<endl;
    return 0;
}

