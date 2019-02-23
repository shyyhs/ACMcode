#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
#define INF 2147483647
#define MAXN 200
#define MAXM 200
using namespace std;
int n,m;
int x,y;
ll c;
struct Edge
{
    int x,y,next;
    ll c;
};
struct Qnode
{
    int x,height;
    Qnode(int x,int height)
    {
        this->x=x;
        this->height=height;
    }
    bool operator<(const Qnode& a) const
    {
        return ((this->height)>a.height);
    }
};

Edge e[MAXM*2+10];
int loc[MAXN+10];
int t=1;

int h[MAXN+10];
ll flow[MAXN+10];
priority_queue<Qnode> q;

void addEdge(int x,int y, ll c)
{
    t++;
    e[t].x=x,e[t].y=y,e[t].c=c,e[t].next=loc[x];
    loc[x]=t;
    t++;
    e[t].x=y,e[t].y=x,e[t].c=0,e[t].next=loc[y];
    loc[y]=t;
}

void push(int x,int y,int eloc)
{
    ll delta=min(flow[x],e[eloc].c);
    flow[x]-=delta;
    flow[y]+=delta;
    e[eloc^1].c+=delta;
    e[eloc].c-=delta;
}

void pushQ(int x)
{
    if (x!=1 && x!=n)
        q.push(Qnode(x,h[x]));
}

void relabel(int x)
{
    int minH=3*n;
    for (int now=loc[x];now;now=e[now].next)
        if (e[now].c)
            minH=min(minH,h[e[now].y]);
    h[x]=minH+1;
    pushQ(x);
}


ll maxFlow()
{
    flow[1]=INF;
    h[1]=n;
    h[n]=0;
    for (int now=loc[1]; now; now=e[now].next)
        if (e[now].c>0)
        {
            push(1,e[now].y,now);
            pushQ(e[now].y);
        }
    while (q.empty()==0)
    {
        int tx = q.top().x; q.pop();
        for (int now=loc[tx];now;now=e[now].next)
            if (flow[tx] &&e[now].c&& h[tx]==h[e[now].y]+1)
            {
                push(tx,e[now].y,now);
                pushQ(e[now].y);
            }
        if (flow[tx])
            relabel(tx);
    }
    return flow[n];
}

void init()
{
    memset(e,0,sizeof(e));
    memset(loc,0,sizeof(loc));
    memset(h,0,sizeof(h));
    memset(flow,0,sizeof(flow));
    while (q.empty()==0) q.pop();
    t=1;
}

int main()
{
    while (scanf("%d%d",&m,&n)!=-1)
    {
        init();
        for (int i=0;i<m; ++i)
        {
            scanf("%d%d%lld",&x,&y,&c);
            addEdge(x,y,c);
        }
        cout<<maxFlow()<<endl;
    }
    return 0;
}
