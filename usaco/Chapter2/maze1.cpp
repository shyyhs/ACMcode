/*
ID: songskg2
PROG: maze1
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
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int w[110][110][4];
int d[110][110];
struct node
{
    int x,y;
};
node q[8000];
int l,r,x,y;
int n,m;
char c[300][300];

void bfs(int sx,int sy)
{
    l=0;
    r=0;
    q[r].x=sx;
    q[r].y=sy;
    r++;
    while (l<r)
    {
        x=q[l].x;
        y=q[l].y;
        l++;
        for (int i=0; i<4; ++i)
            if (w[x][y][i])
            {

                int newx=x+dx[i];
                int newy=y+dy[i];
                if (d[x][y]+1<d[newx][newy])
                {
                    d[newx][newy]=d[x][y]+1;
                    q[r].x=newx;
                    q[r].y=newy;
                    r++;
                }
            }
    }
}
        


int main()
{
    freopen("maze1.in","r",stdin);
    freopen("maze1.out","w",stdout);
    cin>>m>>n;
    for (int i=1; i<=2*n+1; ++i)
        for (int j=1; j<=2*m+1; ++j)
        {
            scanf("%c",&c[i][j]);
            while (c[i][j]=='\n')
                scanf("%c",&c[i][j]);
        }
    for (int i=1; i<=2*n+1; ++i)
    {
        if (i&1)
        {
            for (int j=1; j<=2*m+1; ++j)
                if (j&1)
                {}
                else
                {
                    w[(i-1)/2+1][j/2][0]=(c[i][j]==' ');
                    w[(i-1)/2][j/2][2]=(c[i][j]==' ');
                }
        }else
        {
            for (int j=1; j<=2*m+1; ++j)
                if ((j&1)==0)
                {}
                else
                {
                    w[i/2][(j+1)/2][3]=(c[i][j]==' ');
                    w[i/2][(j+1)/2-1][1]=(c[i][j]==' ');
                }
        }
    }
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            d[i][j]=10000;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            if ((i==1 && w[i][j][0]) || (i==n && w[i][j][2])
                || (j==1 && w[i][j][3]) || (j==m && w[i][j][1]))
            {
                    d[i][j]=1;
                    bfs(i,j);
            }
        }
    int ans=0;
    //for (int i=1; i<=n; ++i)
    //{
    //    for (int j=1; j<=m; ++j)
    //    {
    //        cout<<d[i][j]<<' ';
    //    }
    //    cout<<endl;
    //}

    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            if (d[i][j]>ans)
                ans=d[i][j];
        }
    cout<<ans<<endl;

    return 0;
}
