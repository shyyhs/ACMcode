#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;
int n,m;
bool a[20];
int k[10]={0,2,5,5,4,5,6,3,7,6};
int dp[120000];
int f[120000];
int pre[120000];

int x;
int main()
{
    cin>>n>>m;
    for (int i=0; i<m; ++i)
    {
        cin>>x;
        a[x]=1;
    }
    for (int i=1; i<=9; ++i)
        if (a[i])
            for (int j=0; j<=n; ++j)
                if (j==0 || dp[j])
                    if (dp[j]+1>=dp[j+k[i]])
                    {
                        dp[j+k[i]]=dp[j]+1;
                        f[j+k[i]]=i;
                        pre[j+k[i]]=j;
                    }
    for (int now=n; now;now=pre[now])
        printf("%d",f[now]);
    return 0;
}

