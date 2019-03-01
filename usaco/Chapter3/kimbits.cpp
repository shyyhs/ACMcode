/*
ID: songskg2
PROG: kimbits
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
ll t;
ll f[32][32];
bool flag[32][32];

ll dp(int n,int m)
{
    if (m<0) return 0;
    if (m==0) return 1;
    if (n==1)
    {
        if (m>0) return 2;
        else return 1;
    }
    if (flag[n][m]) return f[n][m];
    flag[n][m]=1;
    f[n][m]=dp(n,m-1)+dp(n-1,m)-dp(n-1,m-1)+dp(n-1,m-1)-dp(n-1,m-2);
    return f[n][m];
}
int main()
{
    freopen("kimbits.in","r",stdin);
    freopen("kimbits.out","w",stdout);
    cin>>n>>m>>t;
//    cout<<dp(9,2)<<endl;
    while (n>1)
    {
        if (dp(n-1,m)>=t)
        {
            cout<<0;
        }else
        {
            t-=dp(n-1,m);
            cout<<1;
            m-=1;
        }
        n--;
    }
    if (t==2) cout<<1<<endl;
    else cout<<0<<endl;

    return 0;
}
