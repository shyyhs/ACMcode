/*
ID: songskg2
PROG: stamps
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
int n,m,lmt;
int a[2000];
bool flag[2100000];
int f[2100000];

int main()
{
    freopen("stamps.in","r",stdin);
    freopen("stamps.out","w",stdout);
    cin>>m>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>a[i];
        lmt=max(lmt,a[i]);
    }
    lmt*=m;
    flag[0]=1;
    f[0]=0;
    for (int i=1; i<=n; ++i)
        for (int j=a[i]; j<=lmt; ++j)
            if (flag[j-a[i]])
            {
                if (!flag[j])
                {
                    f[j]=f[j-a[i]]+1;
                    flag[j]=1;
                }else
                {
                    f[j]=min(f[j],f[j-a[i]]+1);
                }
            }
    for (int i=0; i<=lmt+1; ++i)
        if (flag[i]==0 || f[i]>m)
        {
            cout<<i-1<<endl;
            return 0;
        }


    return 0;
}
