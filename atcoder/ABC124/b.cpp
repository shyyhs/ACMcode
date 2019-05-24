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
int h[200];

int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>h[i];
    int ans=0;
    for (int i=1; i<=n; ++i)
    {
        int flag=1;
        for (int j=0; j<i; ++j)
            if (h[j]>h[i]) flag=0;
        ans+=flag;
    }
    cout<<ans<<endl;

    return 0;
}

