/*
ID: songskg2
PROG: fence
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
int n,m;
int w[510][510];
int inD[510];
int s[8000];
int t;
int x,y;
int tot=0;
void dfs(int i)
{
    for (int j=1; j<=n; ++j)
        while (w[i][j])
        {
            w[i][j]-=1;
            w[j][i]-=1;
            dfs(j);
        }
    s[t++]=i;
}
void print()
{
    for (int i=t-1; i>=0; --i)
        cout<<s[i]<<endl;
}
int main()
{
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    cin>>m; 
    for (int i=1; i<=m; ++i)
    {
        cin>>x>>y;
        w[x][y]+=1;
        w[y][x]+=1;
        n=max(max(x,y),n);
        inD[x]++;
        inD[y]++;
    }
    int start=1;
    for (int i=1; i<=n; ++i)
        if (inD[i]&1)
        {
            start=i;
            break;
        }
    tot=0;
    dfs(start);
    print();
    return 0;

}
