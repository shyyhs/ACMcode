/*
ID: songskg2
PROG: cowtour
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
int n;
int w[160][160];
double d[160][160];
double x[160],y[160];
double maxd[160];
int lb[160];
int tot=0;
char c;

double ans;
double dst(int i,int j)
{
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

void dfs(int x)
{
    lb[x]=tot;
    for (int i=1; i<=n; ++i)
        if (w[x][i]&&(lb[i]==0))
            dfs(i);
}

int main()
{
    freopen("cowtour.in","r",stdin);
    freopen("cowtour.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>x[i]>>y[i];
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
        {
            scanf("%c",&c);
            while (c!='0' && c!='1') scanf("%c",&c);
            w[i][j]=(c=='1');
            if (w[i][j]==1)
                d[i][j]=dst(i,j);
            else
                d[i][j]=20000000;
        }
    for (int k=1; k<=n; ++k)
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j)
                if (i!=j && j!=k)
                if (w[i][k] && w[k][j] && d[i][k]+d[k][j]<d[i][j])
                {
                    w[i][j]=1;
                    d[i][j]=d[i][k]+d[k][j];
                }
    for (int i=1; i<=n; ++i)
        if (lb[i]==0)
        {
            tot+=1;
            dfs(i);
        }
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            if (i!=j && lb[i]==lb[j])
                if (d[i][j]>maxd[i])
                    maxd[i]=d[i][j];
    ans=20000000;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            if (lb[i]!=lb[j])
            {
                double newAns=maxd[i]+maxd[j]+dst(i,j);
                if (newAns<ans)
                {
                    ans=newAns;
                }
            }
    for (int i=1; i<=n; ++i)
        if (maxd[i]>ans)
            ans=maxd[i];
    printf("%0.6lf\n",ans);

    return 0;
}
