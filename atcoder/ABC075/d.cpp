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
using namespace std;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].x >> a[i].y;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k)
                for (int l = 1; l <= n; ++l)
                {
                    int mx = min(a[i].x, a[j].x);
                    int mx = min(mx, a[k].
    

    return 0;
}

