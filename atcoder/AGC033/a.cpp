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
int n,m;
int w[1200][1200];
int c[1200][1200];
struct node
{
    int x,y;
};
node q[12000000];
int l=0,r=0;

int dx[4]={-1,0,1,0};
int dy[4] = {0,1,0,-1};
char ce;

int solve()
{
    int nowx,nowy;
    int nextx,nexty;
    while (l<r)
    {
        node now=q[l];
        l++;
        nowx = now.x;
        nowy = now.y;
        for (int k=0; k<4; ++k)
        {
            nextx = nowx+dx[k];
            nexty = nowy+dy[k];
            if (nextx>=1 && nextx<=n && nexty>=1 && nexty<=m)
            if (c[nextx][nexty]==0)
            {
                c[nextx][nexty]=c[nowx][nowy]+1;
                q[r].x=nextx;
                q[r].y=nexty;
                r++;
            }
        }
    }
    int t =0;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            t = max(t,c[i][j]);
    return t-1;

}

int main()
{
    cin >>n >>m;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            scanf("%c",&ce);
            while (ce!='.' && ce!='#')
                scanf("%c",&ce);
            w[i][j]=(ce=='#');
            if (w[i][j]==1)
            {
                q[r].x=i;
                q[r].y=j;
                r++;
                c[i][j]=1;
            }
        }
    cout<<solve()<<endl;
    return 0;
}

