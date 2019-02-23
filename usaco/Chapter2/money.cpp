/*
ID: songskg2
PROG: money
LANG: C++11
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<random>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#define ll long long
using namespace std;
int n,m;
int x;
ll f[180000];

int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    cin>>n>>m;
    f[0]=1;
    for (int i=1; i<=n; ++i)
    {
        cin>>x;
        for (int j=0; j<=m; ++j)
            if (f[j])
                f[j+x]+=f[j];
    }
    cout<<f[m]<<endl;

    return 0;
}
