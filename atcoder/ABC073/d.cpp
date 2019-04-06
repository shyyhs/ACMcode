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
#define ll long long
using namespace std;
int n,m,r;
int x,y,c;
int a[300];
ll w[300][300];
int flag[300];
int ans;

void dfs(int now,int p,int tans)
{
    if (now==r)
    {
        ans=min(ans,tans);
    }else
    {
        for (int i=1; i<=r; ++i)
            if (flag[i]==0)
            {
                flag[i]=1;
                dfs(now+1,i,tans+w[a[i]][a[p]]);
                flag[i]=0;
            }
    }
}

int main()
{

    cin>>n>>m>>r;
    for (int i=1; i<=n; ++i)
        w[0][i]=w[i][0]=0;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            if (i==j) w[i][j]=0;else
            w[i][j]=300000000;

    for (int i=1; i<=r; ++i)
        cin>>a[i];

    for (int i=1; i<=m; ++i)
    {
        scanf("%d%d%d",&x,&y,&c);
        w[x][y]=w[y][x]=c;
    }
    ans=50000000;
    for (int k=1; k<=n; ++k)
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j)
                    if (w[i][k]+w[k][j]<w[i][j])
                        w[i][j]=w[i][k]+w[k][j];

    dfs(0,0,0);
    cout<<ans<<endl;

    return 0;
}

