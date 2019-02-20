/*
ID: songskg2
PROG: milk3
LANG: C++11
*/
<<<<<<< HEAD
#include<iostream>
=======

#include<iostream>
#include<fstream>
>>>>>>> a2bf06b2eed46448b7b4b79f75426af22926619c
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<random>
<<<<<<< HEAD
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#define ll long long
using namespace std;
bool flag[20*20*40];
int a[3];
int s[3];
bool c[21];

int hs()
{
    return s[0]*20*20+s[1]*20+s[2];
}
void prints()
{
    for (int i=0; i<3; ++i)
        cout<<s[i]<<' ';
    cout<<endl;
}
void dfs()
{
    if (flag[hs()])
    {
        return;
    }else
    {
        flag[hs()]=1;
        if (s[0]==0)
        c[s[2]]=1;
        for (int i=0; i<3; ++i)
            for (int j=0; j<3; ++j)
                if (i!=j)
                {
                    int t=min(s[i],a[j]-s[j]);
                    s[i]-=t;
                    s[j]+=t;
                    dfs();
                    s[i]+=t;
                    s[j]-=t;
                }
    }
}


int main()
{
    freopen("milk3.in","r",stdin);
    freopen("milk3.out","w",stdout);
    for (int i=0; i<3; ++i)
        cin>>a[i];
    s[2]=a[2];
    dfs();
    int ind;
    for (ind=20; ind>=0 && c[ind]==0; --ind);
    for (int i=0; i<=ind; ++i)
    {
        if (c[i])
        {
            cout<<i;
            if (i!=ind) cout<<' ';
        }
    }
    cout<<endl;
=======
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
>>>>>>> a2bf06b2eed46448b7b4b79f75426af22926619c
    return 0;
}
