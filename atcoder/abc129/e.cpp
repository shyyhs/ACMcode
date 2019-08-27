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
const ll P=1e9+7;
using namespace std;

ll f[110000];
bool flag[110000];
ll cf[110000];
bool cflag[110000];

int l[110000];
int n=0;
char c;

void init()
{
    while (scanf("%c",&c)!=EOF)
    {
        if (c=='\n') break;
        l[n++] = (c=='1');
    }
}

ll my_pow(ll x, ll n)
{
    if (n==0) return 1;
    ll ans = my_pow(x,n/2);
    ans = (ans*ans)%P;
    if (n&1) ans=(ans*x)%P;
    return ans;
}

ll cal(ll x)
{
    if (x==0) return 1;
    if (x==1) return 3;
    if (cflag[x]==1) return cf[x];
    cflag[x]=1;
    cf[x] = (3*cal(x-1))%P;

    return cf[x];
}

ll solve(int x)
{
    if (x>=n) return 1;
    if (flag[x]) return f[x];
    flag[x]=1;
    f[x] = cal(n-x-1);
    for (int i=x+1; i<=n; ++i)
        if (l[i]==1 || i==n)
        {
            f[x] = (f[x] + 2*solve(i))%P;
            break;
        }
    return f[x];
}

int main()
{
    init();
    cout<<solve(0)<<endl;
    return 0;
}

