/*
ID: songskg2
PROG: skidesign 
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
int h[1200];

int check(int mx)
{
    int t1;
    int tans=0;
    for (int i=0; i<n; ++i)
    {
        if (h[i]<=mx)
        {
            if (mx-h[i]<=17)
            {}
            else
            {
                t1=mx-17-h[i];
                tans+=t1*t1;
            }
        }else
        {
            t1=h[i]-mx;
            tans+=t1*t1;
        }
    }
    return tans;
}

int main()
{
    freopen("skidesign.in","r",stdin);
    freopen("skidesign.out","w",stdout);
    int ans=0;
    int minAns=2000000000;
    scanf("%d",&n);
    for (int i=0; i<n; ++i)
        scanf("%d",&h[i]);
    for (int i=0; i<=100; ++i)
    {
        ans=check(i);
        if (ans<minAns)
            minAns=ans;
    }
    cout<<minAns<<endl;

    return 0;
}
