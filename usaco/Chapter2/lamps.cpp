/*
ID: songskg2
PROG: lamps
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
using namespace std;
int n;
int c;
int a1[120];
int a2[120];
int t1,t2;

struct node
{
    bool stats[110];
    bool operator<(const node& a) const
    {
        for (int i=1; i<=100; ++i)
            if (stats[i]!=a.stats[i])
                return (stats[i]<a.stats[i]);
        return 1;
    }
};
void printNode(node a)
{
    for (int i=1; i<=n; ++i)
        cout<<a.stats[i];
    cout<<endl;
}
node ans[10000];
int anst=0;
bool eq(node a,node b)
{
    for (int i=1; i<=n; ++i)
        if (a.stats[i]!=b.stats[i])
            return 0;
    return 1;
}
node s;
bool check(node x)
{
    for (int i=0; i<t1; ++i)
        if (x.stats[a1[i]]==0) return 0;
    for (int i=0; i<t2; ++i)
        if (x.stats[a2[i]]==1) return 0;
    return 1;
}
void dfs(int now)
{
    if (now==c || now==(c-2) || (now==c-4))
    {
        if (check(s))
            ans[anst++]=s;
    }
    if (now==c) return;
    
    for (int i=1; i<=n; ++i)
        s.stats[i]^=1;
    dfs(now+1);
    for (int i=1; i<=n; ++i)
        s.stats[i]^=1;

    for (int i=1; i<=n; i+=2)
        s.stats[i]^=1;
    dfs(now+1);
    for (int i=1; i<=n; i+=2)
        s.stats[i]^=1;

    for (int i=2; i<=n; i+=2)
        s.stats[i]^=1;
    dfs(now+1);
    for (int i=2; i<=n; i+=2)
        s.stats[i]^=1;

    for (int i=1; i<=n; i+=3)
        s.stats[i]^=1;
    dfs(now+1);
    for (int i=1; i<=n; i+=3)
        s.stats[i]^=1;
}




int main()
{
    freopen("lamps.in","r",stdin);
    freopen("lamps.out","w",stdout);
    cin>>n;
    cin>>c;
    if (c>4)
        c=4-(c&1);
    while (1)
    {
        scanf("%d",&a1[t1++]);
        if (a1[t1-1]==-1) break;
    }
    t1--;
    while (1)
    {
        scanf("%d",&a2[t2++]);
        if (a2[t2-1]==-1) break;
    }
    t2--;

    
    
    for (int i=1; i<=n; ++i)
        s.stats[i]=1;
    anst=0;
    dfs(0);
    for (int i=0; i<anst;++i)
        for (int j=i+1; j<anst; ++j)
            if (ans[j]<ans[i])
            {
                for (int k=1; k<=n; ++k)
                {
                    int t=ans[i].stats[k];
                    ans[i].stats[k]=ans[j].stats[k];
                    ans[j].stats[k]=t;
                }
            }
    for (int i=0; i<anst; ++i)
        if (eq(ans[i],ans[i+1])==0)
            printNode(ans[i]);
    if (anst==0)
        cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
