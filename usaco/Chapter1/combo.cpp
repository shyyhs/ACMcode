/*
ID: songskg2
PROG: combo
LANG: C++11
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<algorithm>
using namespace std;
int n;
int lk[2][3];
int s[3];
int ans=0;

void prints()
{
    for (int i=0; i<3; ++i)
        cout<<s[i]<<' ';
    cout<<endl;
}

int dist(int x,int y)
{
    return min(abs(x-y),min(x,y)+n-max(x,y));
}

int check2(int i)
{
    for (int j=0; j<3; ++j)
        if (dist(s[j],lk[i][j])>2)
            return 0;
    return 1;
}

int check()
{
    for (int i=0; i<2; ++i)
        if (check2(i))
        {
            return 1;
        }
    return 0;
}


void dfs(int now)
{
    if (now==3)
    {
        if (check())
        {
            ans++;
        }
        return;
    }
    for (int i=1; i<=n; ++i)
    {
        s[now]=i;
        dfs(now+1);
    }
}

int main()
{
    freopen("combo.in","r",stdin);
    freopen("combo.out","w",stdout);
    scanf("%d",&n);
    
    for (int i=0; i<2; ++i)
        for (int j=0; j<3; ++j)
        {
            scanf("%d",&lk[i][j]);
        }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}

