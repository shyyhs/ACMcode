#include<iostream>
using namespace std;
int a;

int main()
{
    cin>>a;
    if (a<1200)
        cout<<"ABC"<<endl;
    else if (a<2800)
        cout<<"ARC"<<endl;
    else cout<<"AGC"<<endl;
    return 0;
}
