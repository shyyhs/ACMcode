#include<iostream>
#include<cstdio>
using namespace std;

int a;

int main()
{
    cin>>a;
    bool f=0;
    for (int i=0; i<100; ++i)
    {
        if ((a-4*i>=0) && ((a-4*i)%7==0))
        {
            cout<<"Yes"<<endl;
            f=1;
            break;
        }
    }
    if (!f)
    cout<<"No"<<endl;
    return 0;
}
