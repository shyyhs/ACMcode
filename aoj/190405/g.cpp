#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#define ll long long
using namespace std;
int n,k;
int x,y,b;

int check(int y,int x,int n)
{
    if (n%2==1)
    {
        if (x>n/2+1)
        {
            x=n+1-x;
        }
        if (y>n/2+1)
        {
            y=n+1-y;
        }
        n=(n+1)/2;
        b=0;
        y-=1; x-=1;
        if (y>=x)
        {
            return (b+(x%3))%3+1;
        }else
        {
            return (b+(y%3))%3+1;
        }
    }
    else
    {
        if (x>(n/2+1))
        {
            x=n+1-x;
        }
        if (y>n/2+1)
        {
            y=n+1-y;
        }
        n=(n+1)/2;
//        cout<<x<<" "<<y<<" "<<n<<endl;
        b=0;
        y-=1; x-=1;
        if (y>=x)
        {
            return (b+(x%3))%3+1;
        }else
        {
            return (b+(y%3))%3+1;
        }

    }

}

int main()
{
    cin>>n>>k;
    for (int i=1; i<=k; ++i)
    {
        cin>>x>>y;
        cout<<check(x,y,n)<<endl;
    }
    return 0;
}

