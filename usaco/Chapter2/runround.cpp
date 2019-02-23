/*
ID: songskg2
PROG: runround
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
int s[11];
int t;
int flag[10];

bool check(int x)
{
    int tx=x;
    memset(flag,0,sizeof(flag));
    t=0;
    while (tx)
    {
        s[t++]=tx%10;
        if (flag[s[t-1]])
            return 0;
        flag[s[t-1]]=1;
        tx/=10;
    }
    memset(flag,0,sizeof(flag));
    int nowLoc=t-1;
    for (int i=1; i<=t; ++i)
    {
        nowLoc=(nowLoc-s[nowLoc]+10*t)%t;
        if (flag[nowLoc]) return 0;
        flag[nowLoc]=1;
    }
    return 1;
}

int main()
{
    freopen("runround.in","r",stdin);
    freopen("runround.out","w",stdout);
    cin>>n;
    for (int i=n+1; 1; ++i)
        if (check(i))
        {
            cout<<i<<endl;
            break;
        }
    return 0;
}
