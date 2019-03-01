/*
ID: songskg2
PROG: fence9
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
int n,m,p;

bool check1(int x,int y)
{
    if (n==0) return (x>0);
    double t=m;
    t/=n;
    double y2=t*x;
    if (y2>y+1e-9) return 1;
    else return 0;
}

bool check2(int x,int y)
{
    if (n==p) return (x<n);
    double t=m;
    t/=(n-p);
    double y2=t*(x-p);
    if (t>0 && y-1e-9>y2) return 1;
    if (t<0 && y+1e-9<y2) return 1;
    return 0;
}

int findx1(int y)
{
    int low=0,high=32000;
    while (low<=high)
    {
        int mid=low+((high-low)>>1);
        if (check1(mid,y) && (!check1(mid-1,y)))
                return mid;
        if (check1(mid,y)==0)
            low=mid+1;
        else if (check1(mid-1,y))
            high=mid-1;
    }
    return low;
}

int findx2(int y)
{
    int low=0,high=32000;
    while (low<=high)
    {
        int mid=low+((high-low)>>1);
        if (check2(mid,y) && (!check2(mid+1,y)))
                return mid;
        if (check2(mid,y)==0)
            high=mid-1;
        else if (check2(mid+1,y))
            low=mid+1;
    }
    return low;
}

int main()
{
    freopen("fence9.in","r",stdin);
    freopen("fence9.out","w",stdout);
    cin>>n>>m>>p;
    ll ans=0;
    for (int i=1; i<=m-1; ++i)
    {
        int x1=findx1(i);
        int x2=findx2(i);
        //cout<<i<<' '<<x1<<' '<<x2<<endl;
        ans+=(x2-x1+1);
    }
    cout<<ans<<endl;

    return 0;
}
