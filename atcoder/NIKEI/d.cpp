#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<random>
#include<algorithm>
#define ll long long
using namespace std;
struct t
{
    int x,y;
}e[300000];
int ans[120000];
int p[120000];

int findf(int i)
{
    if (p[i]==i) return i;
    return (p[i]=findf(p[i]));
}

void tunion(int x,int y)
{
    p[findf(x)]=findf(y);
}

bool checkin(int x,int y)
{
    return findf(x)==findf(y);
}
int n,m;

int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
        p[i]=i;
    for (int i=0; i<n+m-1; ++i)
    {
        scanf("%d %d",&e[i].x,&e[i].y);
        if (ans[e[i].y]>0) continue;
        if (checkin(e[i].x,e[i].y)) continue;
        tunion(e[i].x,e[i].y);
        ans[e[i].y]=e[i].x;
    }
    for (int i=1; i<=n; ++i)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}
