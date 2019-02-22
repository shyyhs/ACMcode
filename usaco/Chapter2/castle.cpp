/*
ID: songskg2
PROG: castle
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
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
char c[4]={'W','N','E','S'};
int e[60][60][4];
int num[60][60];
int totNum=0;
int roomSize[3000];
int maxRoomSize;
int maxBreakSize;
int indX,indY,indW;
int n,m;
void dfs(int x,int y)
{
    if (num[x][y]) return;
    num[x][y]=totNum;
    roomSize[totNum]++;
    maxRoomSize=max(maxRoomSize,roomSize[totNum]);
    for (int i=0; i<4; ++i)
        if (e[x][y][i])
        {
            dfs(x+dx[i],y+dy[i]);
        }
}

void checkWall(int x,int y)
{
    for (int i=0; i<4; ++i)
        if (e[x][y][i]==0)
        {
            int newx=x+dx[i];
            int newy=y+dy[i];
            int newSize=roomSize[num[x][y]]+roomSize[num[newx][newy]];
            if (num[x][y]!=num[newx][newy] && newSize>=maxBreakSize)
            {
                if (newSize>maxBreakSize || (newSize==maxBreakSize && (y<indY || (y==indY && (x>indX || (x==indX && i<indW))) )))
                {
                    maxBreakSize=newSize;
                    indX=x;
                    indY=y;
                    indW=i;
                }
            }
        }
}

int main()
{
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    cin>>m>>n;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            int x;
            cin>>x;
            for (int k=0; k<4; ++k)
            {
                if ((1<<k)&x)
                {
                    e[i][j][k]=0;
                }else
                {
                    e[i][j][k]=1;
                }
            }
        }
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            if (num[i][j]==0)
            {
                totNum++;
                dfs(i,j);
            }
    cout<<totNum<<endl;
    cout<<maxRoomSize<<endl;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            checkWall(i,j);
        }
    cout<<maxBreakSize<<endl;
    cout<<indX<<' '<<indY<<' '<<c[indW]<<endl;


    return 0;
}
