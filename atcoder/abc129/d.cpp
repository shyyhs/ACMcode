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
int w[2100][2100];
int l[2100][2100];
int r[2100][2100];
int u[2100][2100];
int d[2100][2100];
char c;

void init()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            scanf("%c",&c);
            while (c!='.' && c!='#') 
                scanf("%c",&c);
            if (c=='.') w[i][j]=1;
        }
}

void solve()
{
    int ans=0;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            if (w[i][j]==0)
            {
                l[i][j]=r[i][j]=u[i][j]=d[i][j]=0;
            }else
            {
                l[i][j]=l[i][j-1]+1;
                u[i][j]=u[i-1][j]+1;
            }
        }
    for (int i=n; i>=1; --i)
        for (int j=m; j>=1; --j)
        {
            if (w[i][j]==0)
            {
                l[i][j]=r[i][j]=u[i][j]=d[i][j]=0;
            }else
            {
                r[i][j]=r[i][j+1]+1;
                d[i][j]=d[i+1][j]+1;
            }
        }
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            ans=max(ans,l[i][j]+r[i][j]+d[i][j]+u[i][j]-3);
        }
    cout<<ans<<endl;
}
int main()
{
    init();
    solve();
    return 0;
}

