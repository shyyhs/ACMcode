/*
ID: songskg2
PROG: inflate
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
int t[12000],v[12000];
int f[12000];
int main()
{
    freopen("inflate.in","r",stdin);
    freopen("inflate.out","w",stdout);
    cin>>m>>n;
    for (int i=1; i<=n; ++i)
        cin>>v[i]>>t[i];
    for (int i=1; i<=n; ++i)
        for (int j=t[i]; j<=m; ++j)
        {
            if ((j-t[i]==0) || (f[j-t[i]]))
            {
                f[j]=max(f[j],f[j-t[i]]+v[i]);
            }
        }
    int ans=0;
    for (int i=m; i>=0; --i)
        if (f[i])
        {
            ans=max(ans,f[i]);
        }
    cout<<ans<<endl;

    return 0;
}
