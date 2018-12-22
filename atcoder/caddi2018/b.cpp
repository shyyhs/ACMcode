#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#define ll long long
using namespace std;
int n;
int a[120000];


bool checkOne(int i)
{
    return (i&1);
}

int main()
{
    bool flag=0;
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
    {
        scanf("%d",&a[i]);
        if ((a[i]&1)==1)
        {
            flag=1;
        }
    }
    if (n==1)
    {
        if ((a[1]&1)==1)
            cout<<"first"<<endl;
        else cout<<"second"<<endl;
        return 0;
    }
    if (flag==1)
        cout<<"first"<<endl;
    else cout<<"second"<<endl;
    return 0;
}
