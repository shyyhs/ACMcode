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
int ans=0;
int l,r;

int c[120000];


struct node
{
    int v,t;
    node(int v1=0,int t1=0)
    {
        v=v1; t=t1;
    }
    bool operator<(const node& tmp) const
    {
        return (v>tmp.v);
    }
    node operator+(const node& tmp)
    {
        node t2;
        t2.v = tmp.v + v;
        t2.t = tmp.t + t;
        return t2;
    }
    bool operator==(const node& tmp) const
    {
        return (v==tmp.v && t==tmp.t);
    }
    void operator=(const node&tmp)
    {
        v = tmp.v;
        t = tmp.t;
    }
    node operator-(const node& tmp)
    {
        node t2;
        t2.v = v-tmp.v;
        t2.t = t-tmp.t;
        return t2;
    }
};

node t[2];


int main()
{
    sort(t,t+1);
    cout<<(t[0]+t[1]).v<<endl;
    cin >>n >>m;
    int nowl = 1;
    int nowr = n;
    for (int i=1; i<=m; ++i)
    {
        scanf("%d %d",&l,&r);
        if (l>nowl) nowl = l;
        if (r<nowr) nowr =r;
    }
    ans = max(0, nowr-nowl+1);
    cout<<ans<<endl;
    return 0;
}

