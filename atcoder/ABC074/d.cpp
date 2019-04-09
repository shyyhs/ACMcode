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
int n;
ll w[400][400],ww[400][400];
ll ans=0;

int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
        {
            cin>>w[i][j];
            ww[i][j]=w[i][j];
        }
    for (int k=1; k<=n; ++k)
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j)
                if (ww[i][k]+ww[k][j]<ww[i][j])
                    ww[i][j]=ww[i][k]+ww[k][j];
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            if (ww[i][j]!=w[i][j])
            {
                cout<<-1<<endl;
                return 0;
            }
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
        {
            bool flag=0;
            for (int k=1; k<=n; ++k)
                if (i!=j && j!=k && i!=k)
                {
                    if (w[i][k]+w[k][j]==w[i][j])
                        flag=1;
                }
            if (flag==0) ans+=w[i][j];
        }
    cout<<ans/2<<endl;

    return 0;
}

