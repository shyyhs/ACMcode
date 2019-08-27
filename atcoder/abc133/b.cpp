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
int n,m;
int w[30][30];
int flag[1200000];

int main()
{
    for (int i=1; i<=1000; ++i)
        flag[i*i]=1;
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            cin>>w[i][j];
    int ans=0;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
        {
            int tmp=0;
            for (int k=1; k<=m; ++k) 
                tmp += (w[i][k]-w[j][k])*(w[i][k]-w[j][k]);
            ans += flag[tmp];
        }
    cout<<ans/2<<endl;
    
    return 0;
}

