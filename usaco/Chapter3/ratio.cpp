/*
ID: songskg2
PROG: ratios
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

int s[4];
int t[4];
int a[4][4];
int ans[4]={10000,0,0,0};


void check()
{

    int c[4]={0,0,0,0};
    for (int i=1; i<=3; ++i) //
    {
        for (int j=1; j<=3; ++j)
            c[i]+=a[j][i]*s[j];
        if (t[i]==0)
        {
            if (c[i]!=0) return;
            c[i]=0;
        }else
        {
            if (c[i]==0) return;
            if (c[i]%t[i]!=0) return;
            c[i]/=t[i];
        }
    }
    for (int i=1; i<=3; ++i)
        for (int j=1; j<=3; ++j)
        {
            if (c[i]==0 && t[i]==0) continue;
            if (c[j]==0 && t[j]==0) continue;
            if (c[i]!=c[j]) return;
        }
            
    if (c[1]<ans[0])
    {
        ans[0]=c[1];
        for (int i=1; i<=3; ++i)
            ans[i]=s[i];
    }
}

void dfs(int now)
{
    if (now==4)
    {
        check();
    }else
    {
        for (int i=0; i<=100; ++i)
        {
            s[now]=i;
            dfs(now+1);
        }
    }
}


int main()
{
    freopen("ratios.in","r",stdin);
    freopen("ratios.out","w",stdout);
    for (int i=1; i<=3; ++i)
        cin>>t[i];
    for (int i=1; i<=3; ++i)
        for (int j=1; j<=3; ++j)
            cin>>a[i][j];
    dfs(1);
    if (ans[0]<=100)
    {
        for (int i=1; i<=3; ++i)
            cout<<ans[i]<<' ';
        cout<<ans[0]<<endl;
    }else
    {
        cout<<"NONE"<<endl;
    }


    return 0;
}
