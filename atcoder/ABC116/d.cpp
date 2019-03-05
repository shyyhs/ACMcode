#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<random>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;

int k,n;
int t[120000];
ll d[120000];
ll ans=0;
struct node
{
    ll d;
    int t,next;
};
node e[120000];
int loc[120000];
int top=1;
int maxIdx[120000];
priority_queue<ll> q1;
priority_queue<ll> q2;
ll s1[120000];
int t1;
int t2;
ll sum1[120000];
ll sum2[120000];
ll s2[120000];

bool cmp(ll a,ll b)
{
    return a>b;
}

int main()
{
    cin>>n>>k;
    for (int i=1; i<=n; ++i)
    {
        int t;
        ll d;
        scanf("%d %lld",&t,&d);

        e[top].t=t;
        e[top].d=d;
        e[top].next=loc[t];
        loc[t]=top;
        if (d>e[maxIdx[t]].d)
        {
            maxIdx[t]=top;
        }
        top++;
    }
    for (int i=1; i<top; ++i)
        if (i==maxIdx[e[i].t])
        {
            s1[t1++]=e[i].d;
        }else
        {
            s2[t2++]=e[i].d;
        }
    sort(s2,s2+t2,cmp);
    sort(s1,s1+t1,cmp);
    for (int i=0; i<t1; ++i)
    {
        s1[i]=s1[i]+2*i+1;
    }
    for (int i=1; i<=t1; ++i)
        sum1[i]=sum1[i-1]+s1[i-1];
    for (int i=1; i<=t2; ++i)
        sum2[i]=sum2[i-1]+s2[i-1];
   // for(int i=0; i<t1; ++i)
   // {
   //     cout<<s1[i]<<' ';
   // }
   // cout<<endl;
   // for(int i=0; i<t2; ++i)
   //     cout<<s2[i]<<' ';
   // cout<<endl;
    for (int i=0; i<=k; ++i)
    {
        if (i>=0 && k-i>=0)
            ans=max(ans,sum1[i]+sum2[k-i]);
    }
    cout<<ans<<endl;
    return 0;
}

