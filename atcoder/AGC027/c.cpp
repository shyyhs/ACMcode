#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
#define MAXN 200050
int n,m;
char c;
int label[MAXN];
int x,y;
struct T
{
    int y;
    int next;
}e[MAXN*5];
int top=1;
int st[MAXN];
bool hasCheck[MAXN];
bool result[MAXN];
bool ig[MAXN];

void adde(int x,int y)
{
    if (!st[x])
    {
        e[top].y=y;
        e[top].next=0;
        st[x]=top++;
    } else
    {
        e[top].y=y;
        e[top].next=st[x];
        st[x]=top++;
    }
}
void printe()
{
    for (int i=1; i<=n; ++i)
    {
        cout<<i<<":";
        for (int j=st[i]; j; j=e[j].next)
        {
            cout<<e[j].y<<' ';
        }
        cout<<endl;
    }
}

bool checkig(int i)
{
    if (ig[i]==1) return 0;
    bool A=0,B=0;
    for (int j=st[i];j;j=e[j].next)
    {
        int y=e[j].y;
        if (ig[y]) continue;
        if (label[y]==0) A=1;
        if (label[y]==1) B=1;
    }
    if (A==0 || B==0)
        ig[i]=1;
    return ig[i];
}

bool inq[MAXN];
int q[MAXN];
void solve(int i)
{
    int l=1;
    q[l]=i;
    while (l>0)
    {
        int now=q[l];
        inq[now]=0;
        l--;
        if (checkig(now))
        {
            for (int j=st[now]; j; j=e[j].next)
            {
                int y=e[j].y;
                if (ig[y]) continue;
                if (inq[y]) continue;
                inq[y]=1;
                l++;
                q[l]=y;
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
    {
        cin>>c;
        if (c=='A') label[i]=0;
        else label[i]=1;
    }
    for (int i=1; i<=m; ++i)
    {
        cin>>x>>y;
        adde(x,y);
        adde(y,x);
    }
    bool flag=0;
    for (int i=1; i<=n; ++i)
        solve(i);
    for (int i=1; i<=n; ++i)
        if (ig[i]==0)
        {
            cout<<"Yes"<<endl;
            flag=1;
            break;
        }
    if (!flag)
    {
        cout<<"No"<<endl;
    }
        

    return 0;
}
