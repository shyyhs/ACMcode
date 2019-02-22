/*
ID: songskg2
PROG: sort3
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
int a[1200];
int num[4];
int ex[4][4];
int ans=0,resNum=0;
int tm;
int main()
{
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>a[i];
        num[a[i]]++;
    }
    for (int i=1; i<=n; ++i)
        if (i<=num[1])
        {
            ex[1][a[i]]++;
        }
        else if (i<=num[1]+num[2])
        {
            ex[2][a[i]]++;
        }else
        {
            ex[3][a[i]]++;
        }
    bool flag=1;
    while (flag)
    {
        flag=0;
        for (int i=1; i<=3; ++i)
            for (int j=1; j<=3; ++j)
                if (i!=j)
                {
                    tm=min(ex[i][j],ex[j][i]);
                    ans+=tm;
                    ex[i][j]-=tm;
                    ex[j][i]-=tm;
                    ex[i][i]+=tm;
                    ex[j][j]+=tm;
                    if (tm) flag=1;
                }
    }
    for (int i=1; i<=3; ++i)
        for (int j=1; j<=3; ++j)
            if (i!=j)
                resNum+=ex[i][j];
    ans+=(resNum/3)*2;
    cout<<ans<<endl;
    return 0;
}
