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
struct node
{
    int num;
    ll c;
};
node a[200000];
bool cmp(node a,node b)
{
    return a.c<b.c;
}

int n,m;

int main()
{
    cin>> n >> m;
    for (int i=1; i<=n; ++i)
    {
        scanf("%lld%d",&a[i].c,&a[i].num);
    }
    sort(a+1,a+n+1,cmp);
    ll ans = 0;
    for (int i=1; i<=n; ++i)
    {
        int tmp=min(m,a[i].num);
        m-=tmp;
        ans+=tmp*a[i].c;
        if (!m) break;
    }
    cout<<ans<<endl;
        
    return 0;
}

