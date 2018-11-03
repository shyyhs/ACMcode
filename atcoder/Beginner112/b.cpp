#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<random>
using namespace std;

int n,t;
struct Tmp
{
    int cost,time;
}route[1200];

void init()
{
    scanf("%d %d",&n,&t);
    for (int i=0; i<n; ++i)
    {
        scanf("%d %d",&route[i].cost,&route[i].time);
    }
}

void work()
{
    int minCost=1001;
    for (int i=0; i<n; ++i)
    {
        if (route[i].time<=t) minCost=min(minCost,route[i].cost);
    }
    if (minCost<=1000) printf("%d\n",minCost); else printf("TLE\n");
}


int main()
{
    init();
    work();

    return 0;
}

