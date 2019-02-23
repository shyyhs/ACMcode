#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
#define MAXN 101
#define MAXM 101*101
#define INF 2147483647

struct Edge
{
    int x,y,c;
    int next;
};
Edge e[MAXM*2*2+10];
int loc[MAXN+10];
int t=1;
int startP,endP;

int flow[MAXN+10];
int h[MAXN+10];


struct QNode
{
    int x,height;
    QNode(int x,int height)
    {
        this->x=x;
        this->height=height;
    }
    bool operator<(const QNode& a) const
    {
        return this->height>a.height;
    }
};

priority_queue<QNode> q;

void addEdge(int x,int y,int c)
{
    t++;
    e[t].x=x,e[t].y=y,e[t].c=c,e[t].next=loc[x];
    loc[x]=t;
    t++;
    e[t].x=y,e[t].y=x,e[t].c=0,e[t].next=loc[y];
    loc[y]=t;
}

void inQueue(int y)
{
    if (y!=startP && y!=endP)
        q.push(QNode(y,h[y]));
}

void pushEdge(int x,int y,int eloc)
{
    int delta=min(flow[x],e[eloc].c);
    flow[x]-=delta;
    flow[y]+=delta;
    e[eloc].c-=delta;
    e[eloc^1].c+=delta;
    inQueue(y);
}

void pushPoint(int x)
{
    for (int now=loc[x];now;now=e[now].next)
        if (flow[x]&&e[now].c&&(x==startP||h[x]==h[e[now].y]+1))
            pushEdge(x,e[now].y,now);
}
                

void relabel(int x)
{
    h[x]+=1;
    inQueue(x);
}

int push_relabel()
{
    flow[startP]=INF;
    h[startP]=endP+1;
    h[endP]=0;
    pushPoint(startP);
    while (q.empty()==0)
    {
        int tx=q.top().x;q.pop();
        pushPoint(tx);
        if (flow[tx]) relabel(tx);
    }
    return flow[endP];
}

int main()
{
    int n,k,m,x,y;
    scanf("%d%d%d",&n,&k,&m);
    startP=0;
    endP=n;
    for (int i=0; i<k; ++i)
    {
        scanf("%d",&x);
        addEdge(x,endP,1);
    }
    for (int i=0; i<m; ++i)
    {
        scanf("%d%d",&x,&y);
        addEdge(x,y,1);
        addEdge(y,x,1);
    }
    cout<<push_relabel()<<endl;
    return 0;
}



