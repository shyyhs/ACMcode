/*
ID: songskg2
PROG: fact4
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
int two;
int five;
int ans=0;

int n;

int main()
{
    freopen("fact4.in","r",stdin);
    freopen("fact4.out","w",stdout);
    ans=1;
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        int t=i;
        while (t%2==0)
        {
            two++;
            t/=2;
        }
        while (t%5==0)
        {
            five++;
            t/=5;
        }
        ans=(ans*t)%10;
    }
    int t=min(two,five);
    two-=t;
    five-=t;
    for (int i=1; i<=two; ++i)
        ans=(ans*2)%10;
    for (int i=1; i<=five; ++i)
        ans=(ans*5)%10;
    cout<<ans<<endl;

    return 0;
}
