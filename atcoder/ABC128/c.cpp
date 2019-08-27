#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
typedef long long ll;
const ll longinf=1LL<<60;
using namespace std;

int n,m;
int k[20];
int s[20][20];
int p[20];
int ans=0;

int flag[20];

int check()
{
    for (int i=1; i<=m; ++i)
    {
        int ans2=0;
        for (int j=1; j<=k[i]; ++j)
            ans2+=flag[s[i][j]];
        ans2%=2;
        if (ans2!=p[i]) return 0;
    }
    return 1;
}

void dfs(int now)
{
    if (now==n+1)
    {
        ans += check();
        return;
    }else
    {
        flag[now]=0;
        dfs(now+1);
        flag[now]=1;
        dfs(now+1);
    }
}

int main()
{
    cin>>n>>m;
    for (int i=1; i<=m; ++i)
    {
        cin>>k[i];
        for (int j=1; j<=k[i]; ++j)
            cin>>s[i][j];
    }
    for (int i=1; i<=m; ++i)
        cin>>p[i];
    dfs(1);
    cout<<ans<<endl;
    return 0;
}

