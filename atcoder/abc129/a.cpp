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

int a[4];

int main()
{
    int ans=10000;
    cin>>a[1]>>a[2]>>a[3];
    ans=min(ans,a[1]+a[2]);
    ans=min(ans,a[2]+a[3]);
    ans=min(ans,a[3]+a[1]);
    cout<<ans<<endl;


    return 0;
}

