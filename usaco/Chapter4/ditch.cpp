/*
ID: songskg2
PROG: ditch
LANG: C++11
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<random>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#define ll long long
using namespace std;

struct node
{
    int x,y,c,next;
};
node e[2000];
int t=2;
int loc[2000];

int h[2000];
int flow[2000];

int n,m;


struct Qnode
{
    int x,h;
    Qnode(int x,int h)
    {
        this->x=x;
        this->h=h;
    }
    bool operator<(const Qnode& a) const
    {
        return this->h<a.h;
    }
};
priority_queue<Qnode> q;
void pushQ(int x)
{
    if (x!=1 && x!=n)
        q.push(Qnode(x,h[x]));
}

void addEdge(int x,int y,int c)
{
    e[t].x=x;
    e[t].y=y;
    e[t].c=c;
    e[t].next=loc[x];
    loc[x]=t;
    t++;
    e[t].x=y;
    e[t].y=x;
    e[t].c=0;
    e[t].next=loc[y];
    loc[y]=t;
    t++;
}

void pushEdge(int x,int y,int now)
{
    int delta=min(flow[x],e[now].c);
    flow[x]-=delta;
    flow[y]+=delta;
    e[now].c-=delta;
    e[now^1].c+=delta;
}

void pushPoint(int x)
{
    for (int now=loc[x]; now; now=e[now].next)
        if (flow[x] && e[now].c && (x==1 || h[x]==h[e[now].y]+1))
        {
            pushEdge(x,e[now].y,now);
            pushQ(e[now].y);
        }
}


int maxflow()
{
    flow[1]=2147483647;
    h[1]=n+1;
    h[n]=0;
    pushPoint(1);
    while (q.empty()==0)
    {
        int x=q.top().x; q.pop();
        pushPoint(x);
        if (flow[x]) 
        {
            h[x]+=1;
            pushQ(x);
        }
    }
    return flow[n];
}

int main()
{
    freopen("ditch.in","r",stdin);
    freopen("ditch.out","w",stdout);
    cin>>m>>n;
    for (int i=0; i<m; ++i)
    {
        int x,y,c;
        cin>>x>>y>>c;
        addEdge(x,y,c);
    }
    cout<<maxflow()<<endl;

    return 0;
}
