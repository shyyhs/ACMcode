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
#define ll long long
using namespace std;
int n,m,q;
ll s[120000];
ll t[120000];
ll x[120000];
struct node
{
    bool flag;
    ll x;
    int lidx,ridx;
};
node line[300000];
int lt;

bool cmp(node a,node b)
{
    return a.x<b.x;
}

int getl(int now)
{
    if (now==1) return -1;
    if (line[now].flag==line[now-1].flag) 
    {
        if (line[now-1].lidx!=0)
        {
            line[now].lidx=line[now-1].lidx;
        }else
        {
            line[now].lidx=getl(now-1);
        }
    }else
    {
        line[now].lidx=now-1;
    }
    return line[now].lidx;
}
int getr(int now)
{
    if (now==lt) return -1;
    if (line[now].flag==line[now+1].flag) 
    {
        if (line[now+1].ridx!=0)
        {
            line[now].ridx=line[now+1].ridx;
        }else
        {
            line[now].ridx=getr(now+1);
        }
    }else
    {
        line[now].ridx=now+1;
    }
    return line[now].ridx;
}


int tfind(ll x)
{
    if (x<=line[1].x) return 1;
    if (x>=line[lt].x) return lt;
    int l=1,r=lt;
    int mid;
    while (l<=r)
    {
        mid=l+((r-l)>>1);
        if (line[mid].x<=x && x<line[mid+1].x)
            return mid;
        if (line[mid].x<=x)
            l=mid;
        else r=mid;
    }
    return mid;
}


int main()
{
    ll INF=100000;
    INF=INF*INF;
    scanf("%d%d%d",&n,&m,&q);
    for (int i=1; i<=n; ++i)
    {
        scanf("%lld",&s[i]);
        line[i].flag=0;
        line[i].x=s[i];
    }
    for (int i=1; i<=m; ++i)
    {
        scanf("%lld",&t[i]);
        line[n+i].flag=1;
        line[n+i].x=t[i];
    }
    for (int i=1; i<=q; ++i)
        scanf("%lld",&x[i]);
    lt=n+m;
    sort(line+1,line+1+lt,cmp);
    for (int i=1; i<=lt; ++i)
    {
        if (line[i].lidx==0)
            line[i].lidx=getl(i);
        if (line[i].ridx==0)
            line[i].ridx=getr(i);
    }
//    for (int i=1; i<=lt; ++i)
 //       cout<<line[i].flag<<' '<<line[i].x<<' '<<line[i].lidx<<' '<<line[i].ridx<<endl;
    for (int i=1; i<=q; ++i)
    {
        ll ansl=INF;
        ll ansr=INF;
        ll minL=INF;
        int idx=tfind(x[i]);
//        cout<<idx<<endl;
        if (idx>=1 && idx<=lt)
        {
            ansl=0;
            ansl=abs(x[i]-line[idx].x);
            if (line[idx].lidx!=-1)
                minL=min(minL,abs(line[idx].x-line[line[idx].lidx].x));
            if (line[idx].ridx!=-1)
                minL=min(minL,abs(line[idx].x-line[line[idx].ridx].x));
            ansl+=minL;
        }
        if (idx>=1 && idx<=lt)
        {
            ansr=0;
            minL=INF;
            idx+=1;
            ansr=abs(x[i]-line[idx].x);
            if (line[idx].lidx!=-1)
                minL=min(minL,abs(line[idx].x-line[line[idx].lidx].x));
            if (line[idx].ridx!=-1)
                minL=min(minL,abs(line[idx].x-line[line[idx].ridx].x));
            ansr+=minL;
        }
        ll ans=min(ansl,ansr);
        printf("%lld\n",ans);
    }

    return 0;
}

