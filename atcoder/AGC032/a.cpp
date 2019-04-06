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
int b[300];
int a[300];
bool flag[300];
int ans[300];
int t=0;
int nown;


int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>b[i];
    nown=n;
    for (int i=1; i<=n; ++i)
    {
        int tans=0;
        for (int j=nown; j>=1; --j)
            if (b[j]==j)
            {
                tans=j;
                break;
            }
        int tnown=0;
        for (int j=1; j<=nown; ++j)
            if (j!=tans)
            {
                tnown++;
                a[tnown]=b[j];
            }
        for (int j=1; j<=tnown; ++j)
        {
            b[j]=a[j];
        }
        nown=tnown;
        if (tans!=0)
        {
            t+=1;
            ans[t]=tans;
        }
    }

    if (t!=n)
    {
        cout<<-1<<endl;
        return 0;
    }
    for (int i=t; i>=1; --i)
    {
        cout<<ans[i]<<endl;
    }

    return 0;
}
