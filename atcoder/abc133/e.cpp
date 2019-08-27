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
ll M = 1000000007;

ll k;
int n;

struct edge
{
    int x,next;
};
edge e[400000];
int loc[400000];
int top=1;

void add_edge(int l,int r)
{
    e[top].x = r;
    e[top].next = loc[l];
    loc[l] = top;
    top++;
}
int flag[400000]={0};
ll f[400000];

ll dp(int x,int dep,int myk)
{
    flag[x] = 1;
    if (myk<=0) return 0;
    f[x] = myk;
    int tmpk;
    if (dep == 0)
        tmpk = k-1;
    else
        tmpk = k-2;
    for (int now = loc[x]; now; now=e[now].next)
        if (flag[e[now].x] == 0)
        {
            f[x] = (f[x] * dp(e[now].x, dep+1, tmpk))%M;
            tmpk--;
        }
    return f[x];
}

int main()
{
    cin>>n>>k;
    for (int i=1; i<=n-1; ++i)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        add_edge(l,r);
        add_edge(r,l);
    }
    cout<<dp(1,0,k)<<endl;
    return 0;
}

