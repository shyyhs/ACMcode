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
ll a[20];
ll r,d;

int main()
{
    cin>>r>>d>>a[0];
    for (int i=1; i<=10; ++i)
    {
        a[i] = a[i-1]*r-d;
        cout<<a[i]<<endl;
    }
    return 0;
}

