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
int M=2019;

int main()
{
    cin>>n>>m;
    int ans=M;
    for (ll i=n; i<=min(m,n+2019); ++i)
        for (ll j=i+1; j<=min(m,n+2019); ++j)
        {
            ll tmp=(i*j)%M;
            if (tmp<ans)
            {
                ans=tmp;
            }
        }
    cout<<ans<<endl;
    return 0;
}

