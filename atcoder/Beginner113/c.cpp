#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;
int n,m;
struct T
{
    int outOrder,year,pref,prefOrder;
}c[200000];

void init()
{
    cin>>n>>m;
    for (int i=1; i<=m; ++i)
    {
        c[i].outOrder=i;
        cin>>c[i].pref>>c[i].year;
    }
    


}
void work()
{
    sort(c+1,c+m+1,[](T a,T b){if (a.pref!=b.pref) return a.pref<b.pref; return a.year<b.year;});
    for (int i=1; i<=m; ++i)
    {
        if (c[i].pref!=c[i-1].pref) c[i].prefOrder=1;else c[i].prefOrder=c[i-1].prefOrder+1;
    }
    sort(c+1,c+m+1,[](T a,T b){return a.outOrder<b.outOrder;});
    for (int i=1; i<=m; ++i)
    {
        printf("%06d%06d\n",c[i].pref,c[i].prefOrder);
    }
}

int main()
{
    init();
    work();
    return 0;
}


