#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n,s;

int main()
{
    cin>>n;
    int n2=n;
    while (n)
    {
        s+=(n%10);
        n/=10;
    }
    if (n2%s==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
