/*
ID: songskg2
PROG: ariprog
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
using namespace std;
struct node
{
    int start,dif;
    node(int x=0,int y=0)
    {
        start=x;
        dif=y;
    }
};
bool cmp(node a,node b)
{
    if (a.dif!=b.dif) return a.dif<b.dif;
    return a.start<b.start;
}
node s[300000];
int st=0;

bool flag[2500*250+1];
int lmt=0;
int a[250*2500+1];
int t=0;
int n,m;

int main()
{
    freopen("ariprog.in","r",stdin);
    freopen("ariprog.out","w",stdout);
    cin>>n>>m;
    for (int i=0; i<=m; ++i)
        for (int j=0; j<=m; ++j)
        {
            flag[i*i+j*j]=1;
            lmt=max(lmt,i*i+j*j);
        }
    for (int i=0; i<=lmt; ++i)
        if (flag[i])
        {
            a[t++]=i;
        }
    for (int i=0; i<t; ++i)
        for (int j=i+1; j<t; ++j)
        {
            int dif=a[j]-a[i];
            int now=a[i]+(n-1)*dif;
            if (now>lmt) break;
            int nowflag=1;

            for (int k=n-1; k>=1; --k)
            {
                if (flag[now]==0)
                {
                    nowflag=0;
                    break;
                }
                now-=dif;
            }
            if (nowflag)
            {
            node t(a[i],dif);
            s[st++]=t;
            }
        }
    sort(s,s+st,cmp);
    if (st==0)
        cout<<"NONE"<<endl;
    for (int i=0; i<st;++i)
        cout<<s[i].start<<' '<<s[i].dif<<endl;

    return 0;
}
