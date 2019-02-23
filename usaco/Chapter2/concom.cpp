/*
ID: songskg2
PROG: concom
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
int x,y,z;
int wi[120][120];
int wb[120][120];
int wf[120];
int b[120][120];
int b2[120][120];

void dfs(int x)
{
    if (wf[x]) return;
    wf[x]=1;
    int flag=0;
    for (int i=1; i<=n; ++i)
        if (wi[x][i]>50)
        {
            dfs(i);
            flag=1;
        }
    if (!flag) return;

    flag=1;
    while (flag)
    {
        flag=0;
        for (int i=1; i<=n; ++i)
            if (b2[x][i])
                for (int j=1; j<=n; ++j)
                    b2[x][j]|=b2[i][j];

        for (int i=1; i<=n; ++i)
            wb[x][i]=0;
        for (int i=1; i<=n; ++i)
             if (b2[x][i] || i==x)
             {
                for (int j=1; j<=n; ++j)
                    wb[x][j]+=wi[i][j];
             }
        for (int i=1; i<=n; ++i)
            if (wb[x][i]>50 && b2[x][i]==0)
            {
                b2[x][i]=1;
                flag=1;
            }
    }
}

int main()
{
    freopen("concom.in","r",stdin);
    freopen("concom.out","w",stdout);
    cin>>m;

    for (int i=0; i<m; ++i)
    {
        cin>>x>>y>>z;
        wi[x][y]=z;
        wb[x][y]=z;
        if (z>50) b[x][y]=b2[x][y]=1;
        if (x>n) n=x;
        if (y>n) n=y;
    }
    for (int i=1; i<=n; ++i)
        if (wf[i]==0)
            dfs(i);
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            if (i!=j)
                if (wb[i][j]>50)
                    cout<<i<<' '<<j<<endl;

    return 0;
}
