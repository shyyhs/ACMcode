/*
ID: songskg2
PROG: camelot
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
int dx[8]={-1,-2,-2,-1,1,2,2,1};
int dy[8]={2,1,-1,-2,-2,-1,1,2};
int n,m;
char c;
int c2;
int knw[40][40];
int d[33][33][33][33];
bool flag[33][33];
int kx,ky;
struct node
{
    int x,y;
};
node q[10000];
int l,r;


bool check(int x,int y)
{
    if (x>=1 && x<=n && y>=1 && y<=m) 
        return 1;
    else
    {
        return 0;
    }
}


void bfs(int sx,int sy)
{
    memset(flag,0,sizeof(flag));
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            d[sx][sy][i][j]=100000;
    d[sx][sy][sx][sy]=0;
    l=r=0;
    q[0].x=sx;
    q[0].y=sy;
    r++;
    flag[sx][sy]=1;
    while (l<r)
    {
        int nowx=q[l].x;
        int nowy=q[l].y;
        l++;
        for (int i=0; i<8; ++i)
        {
            int newx=nowx+dx[i];
            int newy=nowy+dy[i];
            if (check(newx,newy) && flag[newx][newy]==0)
            {
                flag[newx][newy]=1;
                d[sx][sy][newx][newy]=d[sx][sy][nowx][nowy]+1;
                q[r].x=newx;
                q[r].y=newy;
                r++;
            }
        }
    }
}

int dis(int x1,int y1,int x2,int y2)
{
    return max(abs(x2-x1),abs(y2-y1));
}

int dfs(int x,int y)
{
    int tans=0;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            tans+=(knw[i][j]>0)*d[i][j][x][y];
    tans+=dis(x,y,kx,ky);
    int ans=tans;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            if (knw[i][j])
                for (int dx=-2; dx<=2; ++dx)
                    for (int dy=-2; dy<=2; ++dy)
                    {
                        int newx=kx+dx;
                        int newy=ky+dy;
                        if (check(newx,newy))
                        {
                            int ttans=tans-d[i][j][x][y]+d[i][j][newx][newy]+d[newx][newy][x][y]-dis(x,y,kx,ky)+dis(kx,ky,newx,newy);
                            ans=min(ans,ttans);
                        }
                    }
    return ans;
}

int main()
{
    freopen("camelot.in","r",stdin);
    freopen("camelot.out","w",stdout);
    cin>>n>>m;
    bool kflag=0;
    while (1)
    {
        int tt=scanf("%c",&c);
        if (tt==EOF) break;
        while (!(c>='A' && c<='Z')) 
        {
            tt=scanf("%c",&c);
            if (tt==EOF) break;
        }
        cin>>c2;
        if (kflag==0)
        {
            kflag=1;
            ky=c-'A'+1;
            kx=c2;
        }else
        {
            knw[c2][c-'A'+1]+=1;
        }
    }
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            bfs(i,j);
    int ans=200000000;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            ans=min(ans,dfs(i,j));
        }

    cout<<ans<<endl;
            

    return 0;
}
