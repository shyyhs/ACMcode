#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
using namespace std;

int a,b,k;
int main()
{
    cin>>a>>b>>k;
    for (int i=0; i<k; ++i)
    {
        if (i%2==0)
        {
        if (a%2==1) a-=1;
        b+=a/2;
        a/=2;
        continue;
        }
        if (b%2==1) b-=1;
        a+=b/2;
        b/=2;
    }
    cout<<a<<' '<<b<<endl;
    return 0;
}
