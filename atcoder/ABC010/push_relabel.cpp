//Program: maxFlow by push_relabel alg
//include
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
//const
#define MAXN 100
#define MAXM 100*100
#define INF 2147483647
//var
struct Edge
{
    int x,y,c,next;
};
Edge e[MAXM*2];
int loc[MAXN];
int t=1;
int startP,endP;

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
        return (this->height>a.height);
    }
};
priority_queue<QNode> q;

int flow[MAXN];
int h[MAXN];

void inQueue(int x)
{
    if (x!=startP && x!=endP)
        q.push(QNode(x,h[x]));
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
        if (flow[x] && e[now].c && (now==startP || h[x]==h[e[now].y]+1))
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
    h[startP]=MAXN;
    h[endP]=0;
    pushPoint(startP);
    while (q.empty()==0)
    {
        int tx=q.top().x;q.pop();
        pushPoint(tx);
        if (flow[tx])
            relabel(tx);
    }
    return flow[endP];
}

int main()
{
    cout<<push_relabel();
    return 0;
}


