/*
ID: songskg2
PROG: agrinet
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
int n;
int w[120][120];
int d[120];
int visited[120];
int ans=0;
int main()
{
    freopen("agrinet.in","r",stdin);
    freopen("agrinet.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            cin>>w[i][j];
    for (int i=1; i<=n; ++i)
        d[i]=100000*200;
    for (int i=1; i<=n; ++i)
    {
        if (i==1)
        {
            d[1]=0;
            visited[1]=1;
            for (int j=1; j<=n; ++j)
                if (w[1][j] && w[1][j]<d[j])
                    d[j]=w[1][j];
        }else
        {
            int mind=100000*200;
            int ind=0;
            for (int j=1; j<=n; ++j)
                if (!visited[j] && d[j]<mind)
                {
                    mind=d[j];
                    ind=j;
                }
            visited[ind]=1;
            ans+=mind;
            for (int j=1; j<=n; ++j)
                if (w[ind][j] && w[ind][j]<d[j])
                    d[j]=w[ind][j];
        }
    }
    cout<<ans<<endl;

    return 0;
}
