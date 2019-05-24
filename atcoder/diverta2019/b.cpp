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

int a[3],n;

int main()
{
    cin>>a[0]>>a[1]>>a[2];
    cin>>n;
    int ans = 0;
    for (int i=0; i<=n; ++i)
        for (int j=0; j<=n; ++j)
        {
            int now=a[0]*i+a[1]*j;
            int rem = n-now;
            if (rem>=0 && (rem%a[2]==0))
                ans+=1;
        }
    cout<<ans<<endl;
    return 0;
}

