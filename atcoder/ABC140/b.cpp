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
int a[30],b[30],c[30];


int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    for (int i=1; i<=n; ++i)
        cin >> b[i];
    for (int i=1; i<n; ++i)
        cin >> c[i];
    int ans=0;
    for (int i=1; i<=n; ++i)
    {
        ans += b[a[i]];
        if (i>=1 && a[i] == a[i-1]+1)
            ans += c[a[i-1]];
    }
    cout<<ans<<endl;
    return 0;
}

