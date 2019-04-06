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
int n;
int w[60][60];

int f[60];

int ff(int i)
{
    if (f[i]==i) return i;
    return (f[i]=ff(f[i]));
}

void un(int i,int j)
{
    f[ff(i)]=ff(j);
}

void work()
{
    for (int i=1; i<=n; ++i) f[i]=i;
    int m,x;
    int t=0;
    memset(w,0,sizeof(w));
    for (int i=1; i<=n; ++i)
    {
        cin>>m;
        for (int j=1; j<=m; ++j)
        {
            cin>>x;
            w[i][x]=1;
        }
    }
    for (int i=1; i<=30; ++i)
    {
        int now=0;
        for (int j=1; j<=n; ++j)
        {
            if (w[j][i]==1)
            {
                if (now==0)
                {
                    now=j;
                }else
                {
                    if (ff(now)!=ff(j))
                    {
                        un(now,j);
                        t+=1;
                        if (t==n-1)
                        {
                            cout<<i<<endl;
                            return;
                        }
                    }
                }
            }
        }
    }
    cout<<-1<<endl;
}

int main()
{
    while (1)
    {
        cin>>n;
        if (n==0) break;
        work();
    }
    return 0;
}

