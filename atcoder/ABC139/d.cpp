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
ll n;
ll ans;


int main()
{
    cin>>n;
    ans = (1 + n)*n/2;
    ans-=n;
    cout<<ans<<endl;
    return 0;
}

