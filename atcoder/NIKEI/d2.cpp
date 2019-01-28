#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<random>
#include<algorithm>
#define ll long long
using namespace std;

int lv[320000];
struct T
{
    int x,y;
    int next;
}e[600000];
int be[320000];
int ind[320000];
int t=1;
int p[320000];
int flag[320000];

int q[300000];
int qt=0;

int n,m;

void topsort(int x)
{
    if (flag[x]==1) return;
    q[qt++]=x;
    flag[x]=1;
    for (int i=be[x]; i; i=e[i].next)
    {
        if (ind[e[i].y]==1)
         topsort(e[i].y);
        ind[e[i].y]--;
    }
}

void addedge(int tx,int ty)
{
    e[t].x=tx;
    e[t].y=ty;
    e[t].next=be[tx];
    be[tx]=t;
    t++;
}

int main()
{
    int tx,ty;
    cin>>n>>m;
    int st=0;
    for (int i=0; i<n-1+m; ++i)
    {
        scanf("%d %d",&tx,&ty);
        addedge(tx,ty);
        ind[ty]++;
    }
    for (int i=1; i<=n; ++i)
        if (ind[i]==0)
            st=i;
    topsort(st);
    for (int i=0; i<qt; ++i)
    {
        int ttx=q[i];
        for (int i=be[ttx]; i; i=e[i].next)
            if (lv[e[i].y]<lv[e[i].x]+1)
            {
                lv[e[i].y]=lv[e[i].x]+1;
                p[e[i].y]=e[i].x;
            }
    }
    for (int i=1; i<=n; ++i)
      printf("%d\n",p[i]);
    return 0;
}
