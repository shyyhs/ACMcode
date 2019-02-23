/*
ID: songskg2
PROG: ttwo
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
int fx,fy,fd,cx,cy,cd;
int w[120][120];
char c;

bool check()
{
    if (fx==cx && fy==cy)
        return 1;
    return 0;
}

void move(int &x,int &y,int &d)
{
    int newx=x+dx[d];
    int newy=y+dy[d];
    if (w[newx][newy])
    {
        x=newx;
        y=newy;
    }else
    {
        d=(d+1)%4;
    }
}

int main()
{
    freopen("ttwo.in","r",stdin);
    freopen("ttwo.out","w",stdout);
    for (int i=1; i<=10; ++i)
        for (int j=1; j<=10; ++j)
        {
            scanf("%c",&c);
            while (c=='\n') scanf("%c",&c);
            if (c=='*')
            {
                w[i][j]=0;
            }else if (c=='.')
            {
                w[i][j]=1;
            }else if (c=='F')
            {
                w[i][j]=1;
                fx=i;
                fy=j;
            }else if (c=='C')
            {
                w[i][j]=1;
                cx=i;
                cy=j;
            }
        }
    for (int i=0; i<=20000; ++i)
    {
        if (check())
        {
            cout<<i<<endl;
            return 0;
        }
        move(fx,fy,fd);
        move(cx,cy,cd);
    }
    cout<<0<<endl;
    return 0;
}
