/*
ID: songskg2
PROG: numtri
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
int a[1200][1200];
int ans=0;
int main()
{
    freopen("numtri.in","r",stdin);
    freopen("numtri.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=i; ++j)
        {
            scanf("%d",&a[i][j]);
            a[i][j]+=max(a[i-1][j],a[i-1][j-1]);
            ans=max(ans,a[i][j]);
        }
    cout<<ans<<endl;

    return 0;
}
