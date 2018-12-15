#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<ctime>
#include<random>
#define ll long long
using namespace std;
struct T
{
    int x,y;
}a[250000];
int top=0;
int t=0;
int ww[100][100];

int n,m,w;
int ans;
int x,y;

bool cmp(T a, T b)
{
    if (a.x!=b.x) return (a.x<b.x);
    return (a.y<b.y);
}

void nextStone()
{
    while(a[t].x<=x && t<top) t++;
    while (a[t].y<y && t<top) t++;
}

bool movedown()
{
    nextStone();
    if (a[t].x==x+1 && a[t].y==y)
        return 0;
    if (x==n) return 0;
    x++;
    return 1;
}

void moveright()
{
    if (a[t].x==x && a[t].y==y+1)
        return;
    if (y==w) return;
    nextStone();
    int dx=a[t].x-x;
    int dy=a[t].y-y;
    if (dy<=dx && dy>0)
        y++;
}

int main()
{
    cin>>n>>w>>m;
    int ans = 0;
    for (int i=0; i<m; ++i)
    {
        scanf("%d %d",&x,&y);
        if (y<=x)
        {
            a[top].x=x;
            a[top].y=y;
            top++;
            ww[x][y]=1;
        }
    }
    sort(a,a+top,cmp);

    for (int i=1; i<=n; ++i)
    {
        for (int j=1; j<=w; ++j)
            if (ww[i][j]==0) cout<<'.';else cout<<'#';
        cout<<endl;
    }
    cout<<endl;
    for (int i=0; i<top; ++i)
        cout<<a[i].x<<' '<<a[i].y<<endl;
    cout<<endl;

    x=1; y=1;
    while (true)
    {
        if (movedown()==0)
        {
            cout<<ans+1<<endl;
            return 0;
        }
        ans++;
        cout<<x<<' '<<y<<endl;
        moveright();
        cout<<x<<' '<<y<<endl;
        cout<<endl;
    }
    cout<<ans<<endl;

    return 0;
}
