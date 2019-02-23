/*
ID: songskg2
PROG: prefix
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
char pri[210][15];
int l[210];
int n;
char s[210000];
int m;
char c;

int flag[210000];
int f[210000];
bool mc(int x,int now)
{
    for (int i=0; i<l[x]; ++i)
        if (pri[x][i]!=s[now+i])
            return 0;
    return 1;
}

int dp(int now)
{
    if (now>m) return 0;
    if (flag[now]) return f[now];
    flag[now]=1;
    for (int i=0; i<n; ++i)
        if (mc(i,now))
            f[now]=max(f[now],l[i]+dp(now+l[i]));
    return f[now];
}
int main()
{
    freopen("prefix.in","r",stdin);
    freopen("prefix.out","w",stdout);
    while (1)
    {
        scanf("%c",&c);
        if (c=='.') break;
        if (c==' ' || c=='\n')
        {
            n++;
            continue;
        }
        pri[n][l[n]++]=c;
    }
    //cout<<n<<endl;
    //for (int i=0; i<n; ++i)
    //    cout<<l[i]<<endl;
    while (scanf("%c",&c)!=EOF)
    {
        if (c=='\n') continue;
        if (c=='.') break;
        s[m++]=c;
    }
    //cout<<m<<endl;
    cout<<dp(0)<<endl;
     

    return 0;
}
