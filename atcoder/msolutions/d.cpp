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

node e[50000];
int t=1;
int loc[20000];

void add(int x,int y)
{
    e[t].y=y;
    e[t].next=loc[x];
    loc[x]=t;
    t++;
}

int c[20000];

struct node2
{
    int d;
    int idx;
};

node2 d[20000];


bool flag[20000];
int num[20000];
    

int n;

int q[30000];
int l,r;

bool cmp(node2 a, node2 b)
{
    return a.d>b.d;
}

void bfs()
{
    flag[1]=1;
    d[1].d=1;
    d[1].idx=1;
    q[r++]=1;
    while (l<r)
    {
        int x = q[l++];
        for (int now=loc[x];now;now=e[now].next)
        {
            int y = e[now].y;
            if (flag[y]==0)
            {
                flag[y]=1;
                d[y].d = d[x].d+1;
                d[y].idx = y;
                q[r++]=y;
            }
        }
    }
}

int main()
{
    int x,y;
    cin>>n;
    for (int i=1; i<=n-1; ++i)
    {
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    for (int i=1; i<=n; ++i)
        cin>>c[i];
    bfs();
    sort(d+1,d+n+1,cmp);
    sort(c+1,c+n+1);
    
    //for(int i=1; i<=n; ++i)
     //   cout<<d[i].idx<<' '<<d[i].d<<endl;
    int ans=0;
    for (int i=1; i<=n; ++i)
    {
        num[d[i].idx]=c[i];
        if (d[i].d!=1)
            ans+=c[i];
    }
    cout<<ans<<endl;
    for (int i=1; i<=n; ++i)
        cout<<num[i]<<' ';
    cout<<endl;



    return 0;
}

