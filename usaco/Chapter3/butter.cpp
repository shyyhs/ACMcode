/*
ID: songskg2
PROG: butter
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
int cow,n,m;
int c[900];
ll ans=225*1450*800+1;
struct node
{
    int x,y,d,next;
};
node e[50000];
int loc[2000];
int t=1;
void addEdge(int x,int y,int d)
{
    e[t].x=x;
    e[t].y=y;
    e[t].d=d;
    e[t].next=loc[x];
    loc[x]=t;
    t++;
}
int l,r;
int q[250000];
bool flag[2000];
int d[2000];

bool relax(int x,int y,int td)
{
    if (d[x]+td<d[y])
    {
        d[y]=d[x]+td;
        return 1;
    }
    return 0;
}
ll spfa(int startLoc)
{
    int x;
    for (int i=1; i<=n; ++i)
        d[i]=225*1450+1;
    d[startLoc]=0;
    l=r=0;
    q[r++]=startLoc;
    flag[startLoc]=1;
    while (l<r)
    {
        x=q[l++];
        flag[x]=0;
        for (int now=loc[x]; now; now=e[now].next)
        {
            int y=e[now].y;
            if (relax(x,y,e[now].d))
            {
                if (flag[y]==0)
                    q[r++]=y;
            }
        }
    }
    ll tans=0;
    for (int i=1; i<=n; ++i)
        if (c[i])
            tans+=c[i]*d[i];
    return tans;
}


int main()
{
    freopen("butter.in","r",stdin);
    freopen("butter.out","w",stdout);
    int x,y,td;
    cin>>cow>>n>>m;
    for (int i=1; i<=cow; ++i)
    {
        cin>>x;
        c[x]++;
    }
    for (int i=1; i<=m; ++i)
    {
        cin>>x>>y>>td;
        addEdge(x,y,td);
        addEdge(y,x,td);
    }
    for (int i=1; i<=n; ++i)
    {
        ll tans=spfa(i);
        if (tans<ans)
            ans=tans;
    }
    cout<<ans<<endl;

    return 0;
}
