/*
ID: songskg2
PROG: game1
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
int a[200];
int f[120][120][2];
bool flag[120][120][2];

int dp(int l,int r,int rank)
{
    if (l==r)
    {
        if (rank==1)
            return a[l];
        else
            return 0;
    }
    if (flag[l][r][rank]) return f[l][r][rank];
    flag[l][r][rank]=1;
    if (rank==1)
    {
        if (dp(l+1,r,1)>dp(l,r-1,1))
        {
            f[l][r][rank]=a[r]+dp(l,r-1,0);
        }else
        {
            f[l][r][rank]=a[l]+dp(l+1,r,0);
        }
    }else
    {
        if (dp(l+1,r,1)>dp(l,r-1,1))
        {
            f[l][r][rank]=dp(l,r-1,1);
        }else
        {
            f[l][r][rank]=dp(l+1,r,1);
        }
    }
    return f[l][r][rank];
}




int main()
{
    freopen("game1.in","r",stdin);
    freopen("game1.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>a[i];
    cout<<dp(1,n,1)<<' '<<dp(1,n,0)<<endl;


    return 0;
}
