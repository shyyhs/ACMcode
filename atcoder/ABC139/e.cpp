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
struct node
{
    int y,next;
};
node e[1100000];
int loc[1100000];
int top=1;

int w[1001][1001];

int ind[1100000];
int level[1100000];
int q[1100000];
int l,r;
int nownum;
int n;

void addedge(int x, int y)
{
    ind[y]++;
    e[top].y = y;
    e[top].next = loc[x];
    loc[x] = top;
    top++;
}

int topsort()
{
    l = 0;
    r = 0;
    int max_level = 1;
    for (int i=1; i<=nownum; ++i)
        if (ind[i] == 0)
        {
            level[i] = 1;
            q[r] = i;
            r++;
        }
    while (l<r)
    {
        int x=q[l]; l++;
        for (int now=loc[x]; now; now=e[now].next)
        {
            ind[e[now].y]--;
            if (ind[e[now].y]==0)
            {
                level[e[now].y] = level[x]+1;
                q[r]=e[now].y; r++;
                max_level = max(max_level, level[e[now].y]);
            }
        }

    }
    if (r!=nownum) return -1;
    return max_level;
    
}

int main()
{
    cin >> n;
    nownum=1;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
        {
            if (i==j) continue;
            if (w[j][i]!=0)
                w[i][j] = w[j][i];
            else
            {
                w[i][j] = nownum;
                nownum++;
            }
        }
    nownum-=1;
    int prenode, y;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n-1; ++j)
        {
            if (j==1) prenode=0;
            scanf("%d",&y);
            if (prenode)
                addedge(prenode, w[i][y]);
            prenode = w[i][y];
        }
    cout << topsort() <<endl;

    return 0;
}

