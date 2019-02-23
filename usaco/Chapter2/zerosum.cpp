/*
ID: songskg2
PROG: zerosum
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
int s[20];
char c[3]={' ','+','-'};
int t;

void print()
{
    for (int i=0; i<t; ++i)
        cout<<(i+1)<<c[s[i]];
    cout<<n<<endl;
}

bool check()
{
    int sumN=0;
    int now=1;
    int flag=1;
    for (int i=0; i<t; ++i)
    {
        if (s[i]==1)
        {
            sumN+=(flag*now);
            flag=1;
            now=0;
        }
        if (s[i]==2)
        {
            sumN+=(flag*now);
            flag=-1;
            now=0;
        }
        if (s[i]==0)
        {
            now=now*10;
        }
        now+=(i+2);
    }
    sumN+=(flag*now);
    return (sumN==0);
}


void dfs(int now)
{
    if (now==(n-1) && check())
    {
        print();
    }
    if (now==(n-1))
        return;
    for (int i=0; i<3; ++i)
    {
        s[t++]=i;
        dfs(now+1);
        t--;
    }
}

int main()
{
    freopen("zerosum.in","r",stdin);
    freopen("zerosum.out","w",stdout);
    cin>>n;
    dfs(0);

    return 0;
}
