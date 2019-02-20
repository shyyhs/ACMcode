/*
ID: songskg2
PROG: wormhole
LANG: C++11
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
int n;
ll xx[20],yy[20];

bool pairFlag[20];
int pairN[20];

int ans=0;

bool flag[20];

void prints()
{
    for (int i=1; i<=n; ++i)
    {
        cout<<i<<' '<<pairN[i]<<endl;
    }
    cout<<endl;
}


bool dfs2(int now)
{
    if (flag[now]) return 0;
    flag[now]=1;
    int minX=2000000000,idx=-1;
    for (int i=1; i<=n; ++i)
        if (i!=now && yy[i]==yy[now] && xx[i]>xx[now])
        {
            if (xx[i]<minX)
            {
                minX=xx[i];
                idx=i;
            }
        }
    if (idx==-1) return 1;
    return dfs2(pairN[idx]);
}

bool checkP(int now)
{
    memset(flag,0,sizeof(flag));
    return dfs2(now);
}
    

bool check()
{
    for (int i=1; i<=n; ++i)
        if (pairFlag[i]==0) return 0;
    for (int i=1; i<=n; ++i)
        if (checkP(i)==0)
            return 1;
    return 0;
}

void dfs(int now)
{
    if (now==(n>>1)+1)
    {
        if (check())
        {
            ans++;
            //prints();
        }
        return;
    }else
    {
        for (int i=1; i<=n; ++i)
            if (pairFlag[i]==0)
            {
                for (int j=1; j<=n; ++j)
                    if (pairFlag[j]==0)
                    {
                        pairFlag[i]=pairFlag[j]=1;
                        pairN[i]=j; pairN[j]=i;
                        dfs(now+1);
                        pairN[i]=0; pairN[j]=0;
                        pairFlag[i]=pairFlag[j]=0;
                    }
                break;
            }
    }
}


int main()
{
    freopen("wormhole.in","r",stdin);
    freopen("wormhole.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>xx[i]>>yy[i];
    dfs(1);
    cout<<ans<<endl;

    return 0;
}
