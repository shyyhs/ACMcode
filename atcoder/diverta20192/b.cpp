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
int n;
ll x[100],y[100];

int main()
{
    int ans=1000;
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>x[i]>>y[i];
    if (n==1) 
    {
        cout<<1<<endl;
        return 0;
    }
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            if (i!=j)
            {
                int p = x[i]-x[j];
                int q = y[i]-y[j];
                int tmpans=0;
                for (int k=1; k<=n; ++k)
                    for (int l=1; l<=n; ++l)
                        if (i!=j && x[k]-x[l]==p && y[k]-y[l]==q)
                            tmpans++;
                tmpans = n-tmpans;
                ans = min(ans,tmpans);
            }
    cout<<ans<<endl;

    return 0;
}

