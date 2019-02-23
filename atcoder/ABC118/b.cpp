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

int n,m;
int w[40][40];
int ans=0;
int k,x;
int main()
{
    cin>>n>>m;
    for (int i=0; i<n; ++i)
    {
        cin>>k;
        for (int j=0; j<k; ++j)
        {
            cin>>x;
            w[i][x]=1;
        }
    }
    for (int i=1; i<=m; ++i)
    {
        int flag=1;
        for (int j=0; j<n; ++j)
            if (w[j][i]==0) flag=0;
        ans+=flag;
    }
    cout<<ans<<endl;


    return 0;
}

