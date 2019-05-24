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
int n,k;

int main()
{
    cin>>n>>k;
    int now=1;
    for (int i=1; i<=n; ++i)
    {
        int now1=now*2;
        int now2=now+k;
        now=min(now1,now2);
    }
    cout<<now<<endl;
    return 0;
}

