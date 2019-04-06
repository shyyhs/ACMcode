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
using namespace std;
int n,k;
bool flag;
bool f[150000];
int s[200000];
int t=0;
int ans;
int m;

void work(int n,int k)
{
    memset(f,0,sizeof(f));
    memset(s,0,sizeof(s));
    t=0;
    m=0;
    flag=0;
    int x;
    for (int i=0; i<k; ++i)
    {
        scanf("%d",&x);
        if (x==0) flag=1;
        else f[x]=1;
    }
    ans=0;
    int i;
    for (i=1; i<=n+1; ++i)
    {
        if (f[i]) ans+=1;
        else 
        {
            s[t++]=ans;
            ans=0;
        }
    }
    if (flag==0)
    {
        for (int i=0; i<t; ++i)
            if (s[i]>m)
                m=s[i];
        cout<<m<<endl;
    }else
    {
        m=s[0];
        if (s[0]<n) m+=1;
        for (int i=1; i<t; ++i)
        {
            if (s[i]+s[i-1]+1>m)
                m=s[i]+s[i-1]+1;
        }
        cout<<m<<endl;
    }
}

int main()
{
    while (1)
    {
        cin>>n>>k;
        if (n==0 && k==0)
            break;
        work(n,k);
    }

    return 0;
}

