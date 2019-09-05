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
int a,b;
int ans;

int main()
{
    cin>>a>>b;
    int now=1;
    while (now<b)
    {
        now-=1;
        now+=a;
        ans+=1;
    }
    cout<<ans<<endl;

    return 0;
}

