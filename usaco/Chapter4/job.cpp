/*
ID: songskg2
PROG: job
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

int n,m1,m2;
int a1[1000];
int a2[1000];
int p1[1000];
int p2[1000];
int t1[1000];
int t2[1000];
int ans=1000000;
int main()
{
    freopen("job.in","r",stdin);
    freopen("job.out","w",stdout);
    cin>>n>>m1>>m2;
    for (int i=1; i<=m1; ++i)
    {
        cin>>a1[i];
        p1[i]=a1[i];
    }
    for (int i=1; i<=m2; ++i)
    {
        cin>>a2[i];
        p2[i]=a2[i];
    }
    for (int i=1; i<=n; ++i)
    {
        int minAns=1000000;
        int idx;
        for (int j=1; j<=m1; ++j)
            if (p1[j]<minAns)
            {
                minAns=p1[j];
                idx=j;
            }
        t1[i]=p1[idx];
        p1[idx]+=a1[idx];
        minAns=1000000;
        for (int j=1; j<=m2; ++j)
            if (p2[j]<minAns)
            {
                minAns=p2[j];
                idx=j;
            }
        t2[i]=p2[idx];
        p2[idx]+=a2[idx];
    }
    ans=0;
    for (int i=1; i<=n; ++i)
        if (t1[i]+t2[n-i+1]>ans)
            ans=t1[i]+t2[n-i+1];
    cout<<t1[n]<<' '<<ans<<endl;

    return 0;
}
