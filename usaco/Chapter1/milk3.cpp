/*
ID: songskg2
PROG: milk3
LANG: C++11
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<random>
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_map>

using namespace std;
struct node
{
    int x,y,z;
    node(int a=0,int b=0,int c=0)
    {
        x=a;
        y=b;
        z=c;
    }
    int h()
    {
        return (x<<8)+(y<<4)+z;
    }
    bool operator==(node a)
    {
        if (a.x==x && a.y==y && a.z==z)
            return 1;
        return 0;
    }
    void print()
    {
        cout<<x<<' '<<y<<' '<<z<<endl;
    }
};

node ht[40000];
int t=0;
int loc[30*30*30];
int nxt[30*30*30];


int a,b,c;

void insert(int hv,node now)
{
    t++;
    ht[t]=now;
    nxt[hv]=loc[hv];
    loc[hv]=t;
}

bool check(node now)
{
    int hv=now.h();
    for (int i=loc[hv]; i; i=nxt[i])
    {
        if (ht[i]==now)
            return 0;
    }
    return 1;
}

void dfs(node now)
{
    if (check(now) insert

int main()
{
    //freopen("milk3.in","r",stdin);
    //freopen("milk3.out","w",stdout);
    cin>>a>>b>>c;
    node t(a,b,c);
    if (check(t)) insert(t.h(),t);
    dfs(t);
    cout<<check(t)<<endl;
    return 0;
}
