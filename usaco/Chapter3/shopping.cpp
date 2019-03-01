/*
ID: songskg2
PROG: shopping
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

void dfs()
{
    int h=myHash();
    if (h==0) return 0;
    if (flag[h]) return f[h];
    flag[h]=1;
    int ans=10000000;
    for (int i=0; i<t; ++i)
    {
        tNeed=need;
        nowNeed=need-num;
        checkNowNeed();

        int tans=v[i]+
    }

    return f[h];
}

int main()
{
    //freopen("shopping.in","r",stdin);
    //freopen("shopping.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
       cin>>m[t];
       for (int j=1; j<=m[t]; ++j)
           cin>>c[t][j]>>num[t][j];
       cin>>v[t];
       t++;
    }
    cin>>k;
    for (int i=1; i<=k; ++i)
    {
        cin>>code[i]>>need[i]>>cost[i];
    }
    dfs();

    return 0;
}
