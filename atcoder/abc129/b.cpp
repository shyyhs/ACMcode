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
int w[200];

int main()
{
    int ans=1000000;
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>w[i];
    for (int i=1; i<=n; ++i)
    {
        int ans1=0,ans2=0;
        for (int j=1; j<i; ++j)
            ans1+=w[j];
        for (int j=i; j<=n; ++j)
            ans2+=w[j];
        int ans3 = ans1-ans2;
        if (ans3<0) ans3*=-1;
        if (ans3<ans) ans = ans3;
    }
    cout<<ans<<endl;
    return 0;
}

