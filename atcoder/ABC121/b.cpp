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
int n,m,c;
int w[200][200];
int b[200];

int main()
{
    int ans=0;
    cin >> n >> m >> c;
    for (int i=1; i<=m; ++i)
        cin>> b[i];
    for (int i=1; i<=n; ++i)
    {
        int now=0;
        for (int j=1; j<=m; ++j)
        {
            cin >> w[i][j];
            now+=b[j]*w[i][j];
        }
        ans+=(now>-1*c);
    }
    cout<<ans<<endl;
    return 0;
}

