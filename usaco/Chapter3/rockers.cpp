/*
ID: songskg2
PROG: rockers
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
int n,t,m;
int flag[30][30][30];
int f[30][30][30];
int a[30];

int dp(int now,int rm,int rt)
{
    if (rm==0 && rt==0) return 0;
    if (rm<0 || rt<0) return -100;
    if (now==n) return 0;
    
    if (flag[now][rm][rt]) return f[now][rm][rt];
    flag[now][rm][rt]=1;
    int ans=dp(now+1,rm,rt);
    if (a[now]<=rt)
       ans=max(ans,dp(now+1,rm,rt-a[now])+1);
    else ans=max(ans,dp(now+1,rm-1,t-a[now])+1);
    return (f[now][rm][rt]=ans);
}

int main()
{
    freopen("rockers.in","r",stdin);
    freopen("rockers.out","w",stdout);
    cin>>n>>t>>m;
    for (int i=0; i<n; ++i)
        cin>>a[i];
    cout<<dp(0,m,0)<<endl;

    return 0;
}
