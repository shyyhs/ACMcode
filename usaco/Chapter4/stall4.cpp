/*
ID: songskg2
PROG: stall4
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
int n,m,x,y;
int w[450][450];
int match[450];
int visited[450];
int ans=0;

int dfs(int x)
{
    for (int i=n+1; i<=n+m; ++i)
        if (w[x][i] && !visited[i])
        {
            visited[i]=1;
            if (match[i]==0 || dfs(match[i]))
            {
                match[i]=x;
                match[x]=i;
                return 1;
            }
        }
    return 0;
}

int main()
{
    freopen("stall4.in","r",stdin);
    freopen("stall4.out","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
    {
        cin>>x;
        for (int j=1; j<=x; ++j)
        {
            cin>>y;
            w[i][n+y]=w[n+y][1]=1;
        }
    }
    memset(match,0,sizeof(match));
    for (int i=1; i<=n; ++i)
        if (!match[i])
        {
            memset(visited,0,sizeof(visited));
            visited[i]=1;
            ans+=dfs(i);
        }
    cout<<ans<<endl;

    return 0;
}
