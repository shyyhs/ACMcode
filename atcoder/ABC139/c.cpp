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
int h[120000];
int m[120000];
int ans;
int n;


int main()
{
    cin >> n;
    for (int i=0; i<n; ++i)
    {
        cin >> h[i];
        if (i!=0 && h[i]<=h[i-1])
            m[i] = m[i-1] + 1;
        else m[i] = 0;
        ans = max(ans, m[i]);
    }
    cout<<ans<<endl;
    return 0;
}

