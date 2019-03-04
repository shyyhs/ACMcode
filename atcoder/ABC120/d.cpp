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
int m,n;
struct node
{
    int x,y;
};
node e[120000];
int f[120000];
ll S[120000];
ll s[120000];

int find(int x)
{
    if (f[x]==x) return x;
    return f[x]=find(f[x]);
}

int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
    {
        f[i]=i;
        S[i]=1;
    }
    for (int i=1; i<=m; ++i)
    {
        scanf("%d %d",&e[i].x,&e[i].y);
    }
    for (int i=m; i>=1; --i)
    {
        if (find(e[i].x)==find(e[i].y))
            s[i]=0;
        else
        {
            s[i]=S[find(e[i].x)]*S[find(e[i].y)];
            S[find(e[i].y)]+=S[find(e[i].x)];
            f[find(e[i].x)]=find(e[i].y);
        }
    }
    ll ans=0;
    for (int i=1; i<=m; ++i)
    {
        ans+=s[i];
        printf("%lld\n",ans);
    }
    return 0;
}

