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
#define ll long long
using namespace std;
struct
{
    ll x,y;
}a[100];
int n,K;

int main()
{
    cin >> n >> K;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].x >> a[i].y;
    ll ans = (1LL<<62);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k)
                for (int l = 1; l <= n; ++l)
                {
                    ll ix = min(min(a[i].x, a[j].x),min(a[k].x,a[l].x));
                    ll ax = max(max(a[i].x, a[j].x),max(a[k].x,a[l].x));
                    ll iy = min(min(a[i].y, a[j].y),min(a[k].y,a[l].y));
                    ll ay = max(max(a[i].y, a[j].y),max(a[k].y,a[l].y));

                    int now = 0;
                    for (int e = 1; e <= n; ++e)
                        now += (a[e].x>=ix && a[e].x<=ax && a[e].y>=iy && a[e].y<=ay);
                  //  cout<<ix<<' '<<ax<<' '<<iy<<' '<<ay<<' '<<now<<endl;
                    if (now>=K)
                    {
                        //cout<<now<<' '<<(ax-ix)*(ay-iy)<<endl;
                        ans=min(ans,(ax-ix)*(ay-iy));
                    }
                }
    cout<<ans<<endl;

    

    return 0;
}

