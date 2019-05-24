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
int n,m,k,x,y,l,r,u,d;

int lr[500000];
int ud[500000];
int lrt,udt;
int lr_flag[500000];
int ud_flag[500000];
char s1[500000];
char s2[500000];

bool lr_l()
{
    int nowy = y;
    for (int i=0; i<lrt; ++i)
    {
        if (lr_flag[i]==1)
        {
            if (lr[i]==-1)
                nowy-=1;
        }else
        if (lr_flag[i]==0)
        {
            if (lr[i]==1 && nowy!=m)
                nowy+=1;
        }
        if (nowy<=0) return 0;
    }
    return 1;
}
bool lr_r()
{
    int nowy = y;
    for (int i=0; i<lrt; ++i)
    {
        if (lr_flag[i]==1)
        {
            if (lr[i]==1)
                nowy+=1;
        }else
        if (lr_flag[i]==0)
        {
            if (lr[i]==-1 && nowy!=1)
                nowy-=1;
        }
        if (nowy>m) return 0;
    }
    return 1;
}
bool ud_u()
{
    int nowx = x;
    for (int i=0; i<udt; ++i)
    {
        if (ud_flag[i]==1)
        {
            if (ud[i]==-1)
                nowx-=1;
        }else
        if (ud_flag[i]==0)
        {
            if (ud[i]==1 && nowx!=n)
                nowx+=1;
        }
        if (nowx<=0) return 0;
    }
    return 1;
}
bool ud_d()
{
    int nowx = x;
    for (int i=0; i<udt; ++i)
    {
        if (ud_flag[i]==1)
        {
            if (ud[i]==1)
                nowx+=1;
        }else
        if (ud_flag[i]==0)
        {
            if (ud[i]==-1 && nowx!=1)
                nowx-=1;
        }
        if (nowx>n) return 0;
    }
    return 1;
}
void check()
{
    
    int t1 =lr_l();
    int t2 =lr_r();
    int t3 =ud_u();
    int t4 =ud_d();
    if (t1&t2&t3&t4)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    cin>>n>>m>>k;
    cin>>x>>y;
    l = y;
    r = m-y+1;
    u = x;
    d = n-x+1;
    for (int i=1; i<=k; ++i)
        cin>>s1[i];
    for (int i=1; i<=k; ++i)
        cin>>s2[i];
    for (int i=1; i<=k; ++i)
    {
        if (s1[i]=='L')
        {
            lr[lrt]=-1;
            lr_flag[lrt]=1;
            lrt++;
        }
        if (s1[i]=='R')
        {
            lr[lrt]=1;
            lr_flag[lrt]=1;
            lrt++;
        }
        if (s1[i]=='U')
        {
            ud[udt]=-1;
            ud_flag[udt]=1;
            udt++;
        }
        if (s1[i]=='D')
        {
            ud[udt]=1;
            ud_flag[udt]=1;
            udt++;
        }
        if (s2[i]=='L')
        {
            lr[lrt]=-1;
            lr_flag[lrt]=0;
            lrt++;
        }
        if (s2[i]=='R')
        {
            lr[lrt]=1;
            lr_flag[lrt]=0;
            lrt++;
        }
        if (s2[i]=='U')
        {
            ud[udt]=-1;
            ud_flag[udt]=0;
            udt++;
        }
        if (s2[i]=='D')
        {
            ud[udt]=1;
            ud_flag[udt]=0;
            udt++;
        }
    }
    check();

    
    return 0;
}

