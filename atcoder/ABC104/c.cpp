#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int n,m;
int p[20],c[20];
int f[200][200];
int minA=1000000;
int tt=0;
void check(int s)
{
    bool sel[20];
    int ans=0;
    int remin=m;
    memset(sel,0,sizeof(sel));
    for (int i=1; i<=n; ++i)
    {
        sel[i] = ((1<<i)&s);
        if (sel[i]==1)
        {
            ans+=p[i];
            remin-=c[i];
            remin-=i*100*p[i];
        }
    }
    for (int i=n; i>=1; --i)
        if (sel[i]==0)
        {
            if (remin<=0) break;
            for (int j=0; j<=p[i]; ++j)
            {
                if (remin<=0) break;
                remin-=i*100;
                ans+=1;
            }
        }
    if (remin>0) return;
    if (ans<minA) minA=ans;
}
void dps(int s,int i)
{
    if (i==n+1)
    {
        check(s);
    }else
    {
    dps(s+(1<<i),i+1);
    dps(s,i+1);
    }
}

int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
        cin>>p[i]>>c[i];
    dps(0,1);
    cout<<minA<<endl;
}

