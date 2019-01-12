#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
int n,m;
int w[500][500];
bool flow[500][500];
int totNum=0;
ll num[500][500];
ll numa[200000];
ll numb[200000];
ll ans=0;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void flowAlg(int x,int y)
{
    flow[x][y]=1;
    num[x][y]=totNum;
    int newx,newy;
    for (int i=0; i<4; ++i)
    {
        newx=x+dx[i];
        newy=y+dy[i];
        if (newx>=0 && newx<n &&newy>=0 && newy<m && w[x][y]!=w[newx][newy] && flow[newx][newy]==0)
        {
            flowAlg(newx,newy);
        }
    }
}

int main()
{
    char c;
    cin>>n>>m;
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
        {
            scanf("%c",&c);
            while (c!='#' && c!='.') scanf("%c",&c);
            w[i][j]=(c=='#');
        }
    for (int i=0; i<n; ++i)
        for (int j=0;j<m; ++j)
            if (!flow[i][j])
            {
                flowAlg(i,j);
                totNum++;
            }
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            if (w[i][j]==1)
            numb[num[i][j]]++;else numa[num[i][j]]++;
    for (int i=0; i<totNum; ++i)
    {
        ll tb=numb[i];
        tb*=numa[i];
        ans+=tb;
    }
    cout<<ans<<endl;
    return 0;
}
