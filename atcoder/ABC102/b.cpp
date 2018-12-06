#include<iostream>
#include<cstdio>
using namespace std;
int a;
int m=2000000000,M=-1;
int main()
{
    int n;
    cin>>n;
    for (int i=0; i<n; ++i)
    {
        cin>>a;
        if (a<m) m=a;
        if (a>M) M=a;
    }
    cout<<M-m<<endl;
    return 0;
}
