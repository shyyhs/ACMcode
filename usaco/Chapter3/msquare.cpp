/*
ID: songskg2
PROG: msquare
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
#define M 2000003 
using namespace std;

struct node
{
    int x[9];
    bool operator==(const node &a) const
    {
        for (int i=1; i<=8; ++i)
            if (a.x[i]!=x[i]) return 0;
        return 1;
    }
    node & operator=(const node &t1)
    {
        for (int i=1; i<=8; ++i)
            x[i]=t1.x[i];
        return *this;
    }
    void print()
    {
        for (int i=1; i<=8; ++i)
        {
            cout<<x[i]<<' ';
            if (i==4) cout<<endl;
        }
        cout<<endl;
    }
};
node start,goal;

int cz[4][9]={ {0,0,0,0,0,0,0,0,0},{0,5,6,7,8,1,2,3,4},{0,4,1,2,3,8,5,6,7},{0,1,6,2,4,5,7,3,8}};

ll myHash(node a)
{
    ll ans=0;
    ll t=1;
    for (int i=1; i<=8; ++i)
    {
        ans+=t*a.x[i];
        t*=8;
    }
    ans%=M;
    return ans;
}

void init()
{
    for (int i=1; i<=4; ++i)
        start.x[i]=i;
    for (int i=5; i<=8; ++i)
        start.x[i]=5+(8-i);
    for (int i=1; i<=4; ++i)
        cin>>goal.x[i];
    for (int i=8; i>=5; --i)
        cin>>goal.x[i];
}

node q[200000];
int l,r;
int pre[200000];
int exec[200000];
bool flag[2000010];

void printS(int now)
{
    char c[1000];
    int t=0;
    while (now)
    {
        c[t++]='A'-1+exec[now];
        now=pre[now];
    }
    cout<<t<<endl;
    int pf=0;
    for (int i=t-1; i>=0; --i)
    {
        cout<<c[i];
        pf+=1;
        if (pf==60)
        {
            cout<<endl;
            pf=0;
        }
    }
    if (pf!=0)
        cout<<endl;
}

node change(node now,int mtd)
{
    node ans;
    for (int i=1; i<=8; ++i)
        ans.x[i]=now.x[cz[mtd][i]];
    return ans;
}

void bfs()
{
    l=r=0;
    q[r++]=start;
    pre[0]=0;
    while (l<r)
    {
        node now=q[l];
        int idx=l;
        l++;
        for (int i=1; i<=3; ++i)
        {
            node newS=change(now,i);
            if (flag[myHash(newS)]==0)
            {
                flag[myHash(newS)]=1;
                q[r]=newS;
                pre[r]=idx;
                exec[r]=i;
                if (newS==goal)
                {
                    //newS.print();
                    printS(r);
                    return;
                }
                r++;
            }
        }
    }
}

bool pcheck(int x)
{
    if (x<2) return 0;
    for (int i=2; i<=sqrt(x); ++i)
        if (x%i==0) return 0;
    return 1;
}



int main()
{
    freopen("msquare.in","r",stdin);
    freopen("msquare.out","w",stdout);
    init();
    if (start==goal)
    {
        cout<<0<<endl;
        cout<<endl;
        return 0;
    }
//    start.print();
 //   goal.print();
    bfs();

    return 0;
}
