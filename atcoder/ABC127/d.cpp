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
    ll value;
    ll time;
};

ll a;
ll b;
int n,m;

node s[300000];
int t=0;

bool cmp(node a, node b)
{
    return a.value > b.value;
}

int main()
{
    cin>>n>>m;
    for (int i=0; i<n; ++i)
    {
        scanf("%lld",&a);
        s[t].value = a;
        s[t].time = 1;
        t++;
    }
    for (int i=0; i<m; ++i)
    {
        scanf("%lld %lld",&a,&b);
        s[t].value = b;
        s[t].time = a;
        t++;
    }
    ll ans =0;
    sort(s,s+t,cmp);

    for (int i=0; i<t; ++i)
    {
        if (n==0) break;
        if (s[i].time<=n)
        {
            n-=s[i].time;
            ans+=s[i].time*s[i].value;
        }else
        {
            ans+=n*s[i].value;
            n=0;
        }
    }
    cout<<ans<<endl;



    return 0;
}

