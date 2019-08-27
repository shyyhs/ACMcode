#include<iostream>
using namespace std;

struct node
{
    int x,y;
};

int w[1010][1010];
int d[1010][1010];
bool lr[1010][1010];
bool ud[1010][1010];
bool flag[1010][1010];
char c;

node s,t;

node q[1100000];
int l,r;

int n,m;

int bfs()
{
    q[r++] = s;
    flag[s.x][s.y] = 1;
    d[s.x][s.y] = 0;
    while (l<r)
    {
        node now = q[l++];
        if (lr[now.x][now.y]==0)
        {
            for (int i=0; i<=m; ++i)
            {
                if (w[now.x][now.y+i]==0)
                    break;
                lr[now.x][now.y+i] = 1;
                if (flag[now.x][now.y+i] == 0)
                {
                    flag[now.x][now.y+i] = 1;
                    node tmp = now;
                    tmp.y = now.y + i;
                    d[tmp.x][tmp.y] = d[now.x][now.y]+1;
                    q[r++]=tmp;
                }
            }
            for (int i=0; i<=m; ++i)
            {
                if (w[now.x][now.y-i]==0)
                    break;
                lr[now.x][now.y-i] = 1;
                if (flag[now.x][now.y-i] == 0)
                {
                    flag[now.x][now.y-i] = 1;
                    node tmp = now;
                    tmp.y = now.y - i;
                    d[tmp.x][tmp.y] = d[now.x][now.y]+1;
                    q[r++]=tmp;
                }
            }
        }
        if (ud[now.x][now.y]==0)
        {
            for (int i=0; i<=n; ++i)
            {
                if (w[now.x+i][now.y]==0)
                    break;
                ud[now.x+i][now.y] = 1;
                if (flag[now.x+i][now.y] == 0)
                {
                    flag[now.x+i][now.y] = 1;
                    node tmp = now;
                    tmp.x = now.x + i;
                    d[tmp.x][tmp.y] = d[now.x][now.y]+1;
                    q[r++]=tmp;
                }
            }
            for (int i=0; i<=n; ++i)
            {
                if (w[now.x-i][now.y]==0)
                    break;
                ud[now.x-i][now.y] = 1;
                if (flag[now.x-i][now.y] == 0)
                {
                    flag[now.x-i][now.y] = 1;
                    node tmp = now;
                    tmp.x = now.x - i;
                    d[tmp.x][tmp.y] = d[now.x][now.y]+1;
                    q[r++]=tmp;
                }
            }
        }
        if (flag[t.x][t.y])
            return d[t.x][t.y];
    }
    return -1;
}

int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            scanf("%c",&c);
            while (c=='\n' || c==' ') scanf("%c",&c);
            if (c=='s')
            {
                w[i][j] = 1;
                s.x = i;
                s.y = j;
            }else if (c=='g')
            {
                w[i][j] = 1;
                t.x = i;
                t.y = j;
            }else if (c=='.')
            {
                w[i][j] = 1;
            }else if (c=='#')
            {
                w[i][j] = 0;
            }
        }
    cout << bfs() <<endl;
    return 0;
}
