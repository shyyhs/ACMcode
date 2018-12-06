#include<iostream>
using namespace std;

int main()
{
    int a,M=-1,m=200;
    for (int i=0; i<3; ++i)
    {
        cin>>a;
        if (a>M) M=a;
        if (a<m) m=a;
    }
    cout<<(M-m)<<endl;
    return 0;
}
