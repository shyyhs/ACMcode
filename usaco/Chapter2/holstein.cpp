/*
ID: songskg2
PROG: holstein
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
int n,m;
int need[30];
int v[30][30];
int lmt;
int s[30];
int flag=0;
int sel[30];
void check()
{
    for (int i=1; i<=m; ++i)
        if (s[i]<need[i]) return;
    cout<<lmt;
    for (int i=1; i<=n; ++i)
        if (sel[i])
            cout<<' '<<i;
    cout<<endl;
    flag=1;
}
void dfs(int now,int bg)
{
    if (flag) return;
    if (now==lmt)
    {
        check();
        return;
    }else
    {
        for (int i=bg; i<=n; ++i)
            if (sel[i]==0)
            {
                sel[i]=1;
                for (int j=1; j<=m; ++j)
                    s[j]+=v[i][j];
                dfs(now+1,i+1);
                sel[i]=0;
                for (int j=1; j<=m; ++j)
                    s[j]-=v[i][j];
            }
    }
}


int main()
{
    freopen("holstein.in","r",stdin);
    freopen("holstein.out","w",stdout);
    cin>>m;
    for (int i=1; i<=m; ++i)
        scanf("%d",&need[i]);

    cin>>n;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            scanf("%d",&v[i][j]);
    for (lmt=1; lmt<=n; ++lmt)
    {
        dfs(0,1);
        if (flag) break;
    }


    return 0;
}
