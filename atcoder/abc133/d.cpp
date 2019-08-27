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
ll a[200000];
ll b[200000];

int main()
{
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin>>a[i];
    int flag = 1;
    ll now=0;
    for (int i=1; i<=n; ++i)
    {
        now += flag * a[i];
        flag*=-1;
    }
    b[1] = now; 
    for (int i=2; i<=n; ++i)
        b[i] = 2*a[i-1] - b[i-1];
    for (int i=1; i<=n; ++i)
        cout<<b[i]<<' ';
    cout<<endl;
    return 0;
}

