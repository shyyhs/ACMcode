/*
ID: songskg2
PROG: range
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
bool flag[260][260];
int f[260][260];
int n;
int w[260][260];
int ans[260];
char c;

int dp(int x,int y)
{
    if (w[x][y]==0) return 0;
    if (flag[x][y]) return f[x][y];
    flag[x][y]=1;
    int minAns=250;
    minAns=min(dp(x+1,y),dp(x,y+1));
    minAns=min(minAns,dp(x+1,y+1));
    f[x][y]=minAns+1;
    return f[x][y];
}

int main()
{
    freopen("range.in","r",stdin);
    freopen("range.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
        {
            scanf("%c",&c);
            while (c!='0' && c!='1') scanf("%c",&c);
            w[i][j]=(c=='1');
        }
    for (int i=1; i<=n; ++i)
    {
        for (int j=1; j<=n; ++j)
        {
            dp(i,j);
 //           cout<<f[i][j]<<' ';
            for (int k=2; k<=f[i][j]; ++k)
                ans[k]+=1;
        }
//        cout<<endl;
    }
    for (int i=2; i<=250; ++i)
        if (ans[i])
        {
            cout<<i<<' '<<ans[i]<<endl;
        }else
        {
            break;
        }

    return 0;
}
