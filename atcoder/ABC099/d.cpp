#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,c;
int w[50][50];
int w2[3][50];
int s[3][300000];
int t[3];
int ans[3];
int flag[100];
int x;


int check(int x,int y)
{
    int tans=0;
    for (int i=0; i<t[x]; ++i)
        tans+=w[s[x][i]][y];
    return tans;
}

int dfs(int now)
{
    if (now==3) return 0;
    int ans=2000000000;
    for (int i=1; i<=c; ++i)
        if (flag[i]==0)
        {
            flag[i]=1;
            ans=min(ans,w2[now][i]+dfs(now+1));
            flag[i]=0;
        }
    return ans;
}
int main()
{
    cin>>n>>c;
    for (int i=1; i<=c; ++i)
        for (int j=1; j<=c; ++j)
            scanf("%d",&w[i][j]);
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
        {
            scanf("%d",&x);
            s[(i+j)%3][t[(i+j)%3]++]=x;
        }
    for (int i=0; i<3; ++i)
    {
        for (int j=1; j<=c; ++j)
            w2[i][j]=check(i,j);
    }
    cout<<dfs(0)<<endl;
    return 0;
}
