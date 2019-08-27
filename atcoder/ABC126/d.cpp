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
typedef long long ll;
const ll longinf=1LL<<60;
using namespace std;
struct edge
{
    int y,c,next;
};
edge e[300000];
int loc[200000];
int t=1;

int color[200000];
bool flag[200000];

void add(int a,int b,int c)
{
    e[t].y=b;
    e[t].c=c;
    e[t].next=loc[a];
    loc[a]=t;
    t++;
}

void dfs(int x)
{
    for (int now=loc[x]; now; now=e[now].next)
    {
        int y = e[now].y;
        if (flag[y]==0)
        {
            if (e[now].c==0)
                color[y]=color[x];
            else color[y]=color[x]^1;
            flag[y]=1;
            dfs(y);
        }
    }
}


int n,a,b,c;
int main()
{
    cin>>n;
    for (int i=1; i<=n-1; ++i)
    {
        cin>>a>>b>>c;
        add(a,b,c%2);
        add(b,a,c%2);
    }
    flag[1]=1;
    color[1]=0;
    dfs(1);
    for (int i=1; i<=n; ++i)
        cout<<color[i]<<endl;
    return 0;
}

