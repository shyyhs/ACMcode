/*
ID: songskg2
PROG: frac1
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
struct node
{
    int x,y;
};
node ans[160*170];
int t=0;
bool cmp(node a,node b)
{
    return (a.x*b.y<a.y*b.x);
}
int g(int x,int y)
{
    return (x%y==0)?y:g(y,x%y);
}

int main()
{
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);
    cin>>n;
    ans[0].x=0;
    ans[0].y=1;
    t=1;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=i; ++j)
        {
            // j/i
            if (g(j,i)!=1) continue;
            ans[t].x=j;
            ans[t].y=i;
            t++;
        }
    sort(ans,ans+t,cmp);
    for (int i=0; i<t; ++i)
        cout<<ans[i].x<<'/'<<ans[i].y<<endl;

    return 0;
}
