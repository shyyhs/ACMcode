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
    ll x,y;
};

node p[200];
int n;

bool cmp(node p1, node p2)
{
    if (atan2(p1.y, p1.x)!=atan2(p2.y, p2.x))
        return atan2(p1.y, p1.x) < atan2(p2.y, p2.x);
    else return p1.x < p2.x;
}


int main()
{
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> p[i].x >> p[i].y;
    sort(p, p+n, cmp);
    //for (int i=0; i<n; ++i)
    //    cout << p[i].x <<' '<< p[i].y <<endl;
    ll max_ans = 0;
    for (int i=0; i<n; ++i)
    {
        ll nowx=0,nowy=0;
        for (int j=0; j<n; ++j)
        {
            int now_idx = (i+j)%n;
            nowx += p[now_idx].x;
            nowy += p[now_idx].y;
            if (nowx*nowx + nowy*nowy > max_ans)
                max_ans = nowx*nowx + nowy*nowy;
        }
    }
    printf("%0.50lf",sqrt(max_ans));
    return 0;
}

