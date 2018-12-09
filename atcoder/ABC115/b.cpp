#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
int a;
int tot;
int m=0;

int main()
{
    cin>>n;
    for (int i=0; i<n; ++i)
    {
        cin>>a;
        tot+=a;
        if (a>m) m=a;
    }
    tot-=(m/2);
    cout<<tot<<endl;

    return 0;
}
