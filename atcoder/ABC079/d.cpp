#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int x;
long long ans;
int w[50][50];
int main()
{
    cin>>n>>m;
    for (int i=0; i<=9; ++i)
        for (int j=0; j<=9; ++j)
            cin>>w[i][j];
    for (int k=0; k<=9; ++k)
        for (int i=0; i<=9; ++i)
            for (int j=0; j<=9; ++j)
                if (w[i][k]+w[k][j]<w[i][j])
                    w[i][j]=w[i][k]+w[k][j];
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            cin>>x;
            if (x>=0)
                ans+=w[x][1];
        }
    cout<<ans<<endl;
    return 0;
}
