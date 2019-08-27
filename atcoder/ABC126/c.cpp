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

ll n,k;
double ans=0;
double f[300000];
bool flag[300000];

double dp(int i)
{
    if (i>=k) return 1;
    if (i==0) return 0;
    if (flag[i]) return f[i];
    flag[i]=1;
    f[i] = (dp(0) + dp(i*2))/2;
    return f[i];
}

int main()
{
    cin>>n>>k;
    for (int i=n; i>=1; --i)
    {
        ans += dp(i);
    }
    ans = ans/n;
    printf("%0.10lf\n",ans);

    return 0;
}

