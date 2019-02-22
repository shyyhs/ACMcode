/*
ID: songskg2
PROG: hamming
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
int n,b,d;
int w[1025][1025];
int totNum=0;
int num[1025];
int numSize[1025];
int s[1000];
int t;
int visited[2000];
int flag=0;

int dst(int x,int y)
{
    int t=x^y;
    int ans=0;
    while (t)
    {
        t-=(t&(-t));
        ans+=1;
    }
    return ans;
}

void print()
{
    bool f2=0;
    for (int i=0; i<t; ++i)
    {
        if (i%10==0) cout<<s[i];
        else cout<<' '<<s[i];
        if (i%10==9) cout<<endl;
        f2=((i%10)==9);
    }
    if (f2==0) cout<<endl;
}

bool check(int x)
{
    for (int i=0; i<t; ++i)
        if (w[s[i]][x]==0)
            return 0;
    return 1;
}

void dfs(int now)
{
    if (flag==1) return;
    if (now==n)
    {
        print();
        flag=1;
    }
    for (int i=0; i<(1<<b); ++i)
        if (visited[i]==0 && check(i))
        {
            visited[i]=1;
            s[t++]=i;
            dfs(now+1);
            t--;
            visited[i]=0;
        }
}


int main()
{
    freopen("hamming.in","r",stdin);
    freopen("hamming.out","w",stdout);
    cin>>n>>b>>d;
    for (int i=0; i<(1<<b); ++i)
        for (int j=0; j<(1<<b); ++j)
            if (dst(i,j)>=d)
                w[i][j]=1;
    dfs(0);
    return 0;
}
