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
using namespace std;
int n;
double ans;
double x;
string u;

int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>x>>u;
        if (u=="JPY")
            ans+=x;
        else if (u=="BTC")
            ans+=x*380000;
    }
    cout<<ans<<endl;
    return 0;
}

