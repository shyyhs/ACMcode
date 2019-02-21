/*
ID: songskg2
PROG: pprime
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
int a,b;
int ansLst[1000000];
int t;

int s[20];
int tmps[20];
int tmpt=0;

bool check(int x)
{
    if (x<2) return 0;
    for (int i=2; i<=sqrt(x)+1; ++i)
        if ((x%i)==0)
            return 0;
    return 1;
}

int geneP(int st,int flag)
{
    tmpt=0;
    for (int i=0; i<st; ++i)
        tmps[tmpt++]=s[i];
    for (int i=st-1-flag; i>=0; --i)
        tmps[tmpt++]=s[i];
    int now=0;
    for (int i=0; i<tmpt; ++i)
    {
        now+=tmps[i];
        now*=10;
    }
    now/=10;
    return now;
}


void dfs(int now)
{
    if (now!=0)
    {
        for (int i=0; i<2; ++i)
        {
            int x=geneP(now,i);
            if (check(x))
            {
                ansLst[t++]=x;
            }
        }
    }
    if (now>=4)
        return;
    for (int i=0; i<=9; ++i)
    {
        s[now]=i;
        dfs(now+1);
    }
}





int main()
{
    freopen("pprime.in","r",stdin);
    freopen("pprime.out","w",stdout);
    cin>>a>>b;
    dfs(0);
    sort(ansLst,ansLst+t);
    for (int i=0; i<t; ++i)
    {
        if (ansLst[i]>=a && ansLst[i]<=b)
            cout<<ansLst[i]<<endl;
    }

    return 0;
}
