#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int x,y;
int main()
{
    int b=-1,a=-1;
    cin>>x>>y;
    if ((3*y-x)%8==0)
        b=(3*y-x)/8;
    if (b>=0)
        if (((x-b)%3)==0)
            a=(x-b)/3;
    if (a>=0 && b>=0)
        cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    return 0;
}
