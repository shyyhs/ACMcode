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
const ll P=1000000007;
using namespace std;

ll f[120000];
int flag[120000];
int af[120000];
int n,m,x;

ll dp(int i)
{
    if (i<0) return 0;
    if (i==0) return 1;
    if (af[i]) return 0;
    if (flag[i]) return f[i];
    flag[i]=1;
    f[i] = (dp(i-1)+dp(i-2))%P;
    return f[i];
}

int main()
{
    cin>>n;
    cin>>m;
    for (int i=1; i<=m; ++i)
    {
        cin>>x;
        af[x]=1;
    }
    cout<<dp(n)<<endl;
    return 0;
}

