/*
ID: songskg2
PROG: sprime
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
int n,lmt;

bool check(int x)
{
    if (x<2) return 0;
    for (int i=2; i<=sqrt(x); ++i)
        if (x%i==0) return 0;
    return 1;
}

void dfs(int now,int num)
{
    
    if (now==n)
    {
        if (check(num))
            cout<<num<<endl;
        return;
    }
    if (now!=0 && check(num)==0)
        return;
    if (now==0)
    {
        dfs(now+1,2);
        dfs(now+1,3);
        dfs(now+1,5);
        dfs(now+1,7);
    }
    if (now>0)
    {
        dfs(now+1,num*10+1);
        dfs(now+1,num*10+3);
        dfs(now+1,num*10+5);
        dfs(now+1,num*10+7);
        dfs(now+1,num*10+9);
    }
}


int main()
{
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);
    cin>>n;
    lmt=1;
    for (int i=1; i<=n; ++i)
        lmt*=10;
    dfs(0,0);


    return 0;
}
